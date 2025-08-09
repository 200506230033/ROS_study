/*
需求：订阅twist消息，并将之转换为go2需要的request消息以控制机器狗运动
实现：
    1.创建一个Request的发布对象
    2.创建twist订阅对象
    3.在回调函数中实现消息转换和发布
*/
#include "rclcpp/rclcpp.hpp"
#include "unitree_api/msg/request.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sport_model.hpp"
#include "nlohmann/json.hpp"

using namespace std::placeholders;


class TwistBridge : public rclcpp::Node{
public:
  TwistBridge():Node("my_node"){
    RCLCPP_INFO(this -> get_logger(), "TwistBridge创建!");
    //1.创建一个Request的发布对象
    request_pub_ = this -> create_publisher<unitree_api::msg::Request>("/api/sport/request",10);
    //2.创建twist订阅对象
    twist_pub_ = this -> create_subscription<geometry_msgs::msg::Twist>("cmd_vel",10,std::bind(&TwistBridge::twist_cb,this,_1));
  }

private:
  rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr request_pub_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twist_pub_;
  void twist_cb(const geometry_msgs::msg::Twist::SharedPtr twist){
    //3.在回调函数中实现消息转换和发布
    unitree_api::msg::Request request;

    //转换实现
    //获取 twist 消息的线速度和角速度
    double x = twist -> linear.x;
    double y = twist -> linear.y;
    double z = twist -> angular.z;
    //默认api_id 为平衡站立
    auto api_id = ROBOT_SPORT_API_ID_BALANCESTAND;
    if( x != 0 || y != 0 || z != 0 ){
      api_id = ROBOT_SPORT_API_ID_MOVE;

      //设置参数
      nlohmann::json js;
      js["x"] = x;
      js["y"] = y;
      js["z"] = z;
      request.parameter = js.dump();
    }
    request.header.identity.api_id = api_id;
    request_pub_ -> publish(request);

  }
};





int main(int argc,char*argv[]){

  //初始化 ROS2 客户端
  rclcpp::init(argc,argv);
  //调用 spin 函数，并传入节点对象指针
  rclcpp::spin(std::make_shared<TwistBridge>());
  //释放资源
  rclcpp::shutdown();
   
  return 0;
}
