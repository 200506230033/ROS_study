import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/zjh/unitree_go2_ws/install/go2_teleop_ctrl_keyboard'
