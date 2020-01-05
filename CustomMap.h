#pragma once
#include"windows.h"

extern int imageCM[22][22]; //蛇活动范围

class CustomMap {
public :

void MouseEventProc(MOUSE_EVENT_RECORD mer);  // 鼠标事件处理函数
void MessageLoop();  //消息处理函数
void keyEventProc(KEY_EVENT_RECORD ker);
void gotoXYCM(int x, int y);
void displayCM();
void showCursorCM(bool isShow);
void colorCM(int a);
void printRange();
void editMap();
int x;
int y;
int n;

};