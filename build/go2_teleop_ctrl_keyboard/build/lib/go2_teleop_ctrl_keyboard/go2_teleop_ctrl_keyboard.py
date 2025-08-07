"""
需求：
    编写键盘控制节点，控制go2的运动

"""




import rclpy 
from rclpy.node import Node
import termios
import sys
import tty



class TeleopNode(Node):
    def _init_(self):
        super()._init_('teleop_ctrl_keyboard')

def getkey(settings):
    #设置读取模式
    tty.setraw(sys.stdin,fileno())
    #获取按键
    key = sys.stdin.read(1)
    #恢复终端的设置
    termios.tcsetattr(sys.stdin,termios.TCSADRAIN,settings)
    #返回按键值
    return key

def main():
    #读取键盘录入实现
    #1.获取标准输入流终端属性并返回
    settings = termios.tcgetattr(sys.stdin)

    #2.循环读取按键
    while True:
        key = getkey(settings)
        print(key)


    rclpy.init()
    rclpy.spin(TeleopNode())
    rclpy.shutdown()

    if _name_ == '_main_':
        main()






