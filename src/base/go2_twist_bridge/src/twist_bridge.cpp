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
