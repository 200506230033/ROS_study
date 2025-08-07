#ifndef _SPORT_MODEL_
#define _SPORT_MODEL_
#include<iostream>

#pragma pack(1)


//1001:阻尼控制
const int32_t ROBOT_SPORT_API_ID_DAMP = 1001 ;
//1002:平衡站立，控制机器人进入平衡站立状态，保持立直和稳定
const int32_t ROBOT_SPORT_API_ID_BALANCESTAND = 1002 ;
//1003：停止运动，停止机器人所有运动，使其立即停止
const int32_t ROBOT_SPORT_API_ID_STOPMOVE = 1003 ;
//1004:站立，控制机器人从其他姿势恢复到站立姿势
const int32_t ROBOT_SPORT_API_ID_STANDUP = 1004 ;
//1005:站立下降，控制机器人从站立姿势转变为其他姿势
const int32_t ROBOT_SPORT_API_ID_STANDDOWN = 1005 ;
//1006:恢复站立，控制机器人在失去平衡后恢复到站立姿势
const int32_t ROBOT_SPORT_API_ID_RECOVERSTAND = 1006 ;
//1007：欧拉角控制，用于调整机器人的姿态
const int32_t ROBOT_SPORT_API_ID_EULER = 1007 ;
//1008: 移动，控制机器人进行移动，可能直线运动或者转向
const int32_t ROBOT_SPORT_API_ID_MOVE = 1008 ;
//1009：坐下，控制机器人进入坐下姿势 
const int32_t ROBOT_SPORT_API_ID_SIT = 1009 ;
//1010: 从坐下恢复站立，控制机器人从坐下姿势恢复到站立姿势
const int32_t ROBOT_SPORT_API_ID_RISESIT = 1010 ;
//1011：切换步态，切换机器人的步态
const int32_t ROBOT_SPORT_API_ID_SEITCHGAIT = 1011 ;
//1012：触发，可能用于触发某个特定的动作或者事件
const int32_t ROBOT_SPORT_API_ID_TRIGGER = 1012 ;
//1013:身体高度调整，调整机器人的身体高度
const int32_t ROBOT_SPORT_API_ID_BOODHEIGHT = 1013 ;
//1014：脚步抬起高度调整，调整机器人脚的抬起高度
const int32_t ROBOT_SPORT_API_ID_FOOTRAISEHEIGHT = 1014 ;
//1015：速度级别调整
const int32_t ROBOT_SPORT_API_ID_SPEEDLEVEL = 1015 ;
//1016：打招呼
const int32_t ROBOT_SPORT_API_ID_HELLO = 1016 ;
//1017：伸展
const int32_t ROBOT_SPORT_API_ID_STRETCH = 1017 ;
//1018: 轨迹跟随，控制机器人按照预定的轨迹进行移动
const int32_t ROBOT_SPORT_API_ID_TRAJECTORYFOLLOW = 1018 ;
//1019：连续步态
const int32_t ROBOT_SPORT_API_ID_CONTINUOUSGAIT = 1019 ;
//1020：内容，用于控制机器人显示或者执行某种任务
const int32_t ROBOT_SPORT_API_ID_CONTENT = 1020 ;
//1021：打滚
const int32_t ROBOT_SPORT_API_ID_WALLOW = 1021 ;
//1022：舞蹈1
const int32_t ROBOT_SPORT_API_ID_DANCE1 = 1022 ;
//1023：舞蹈2
const int32_t ROBOT_SPORT_API_ID_DANCE2 = 1023 ;
//1024：获取身体高度
const int32_t ROBOT_SPORT_API_ID_GETBODYHEIGHT = 1024 ;
//1025: 获取脚步抬起高度
const int32_t ROBOT_SPORT_API_ID_GETFOOTRAISEHEIGHT = 1025 ;
//1026：获取速度级别
const int32_t ROBOT_SPORT_API_ID_GRTSPEEDLEVEL = 1026 ;
//1027：切换操控杆
const int32_t ROBOT_SPORT_API_ID_SWITCHJOYSTICK = 1027 ;
//1028：姿态，控制机器人进入特定的姿态或者姿势
const int32_t ROBOT_SPORT_API_ID_POSE = 1028 ;
//1029: 刮擦
const int32_t ROBOT_SPORT_API_ID_SCRAPE = 1029 ;
//1030：前空翻
const int32_t ROBOT_SPORT_API_ID_FRONTFLIP = 1030 ;
//1031：前跳
const int32_t ROBOT_SPORT_API_ID_FRONTJUMP = 1031 ;
//1032：前扑
const int32_t ROBOT_SPORT_API_ID_FRONTPOUNCE = 1032 ;




#endif