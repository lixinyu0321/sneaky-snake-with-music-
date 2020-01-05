#include "stdafx.h"
#include"Utils.h"
#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void Utils::gotoXY(int x, int y)      //设定输出位置
{
	COORD c;   //光标位置
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//获取句柄，设置位置
	showCursor(false);   //取消光标闪烁
}
//-----------------------------------------------------------------
void Utils::color(int a)              //颜色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

//---------------------------------------------
void Utils::setWindows(int cols, int lines) {
	system("title 贪吃蛇");
	char ch[30];
	sprintf_s(ch, "mode con cols=%d lines=%d", cols, lines);
	system(ch);
}
//---------------------------------------------
void Utils::showCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;   //控制台光标信息结构类型
	cci.dwSize = 1;   //光标大小
	cci.bVisible = isShow;      //是否显示光标  true显示
	SetConsoleCursorInfo(hOutStd, &cci);   //设置控制台屏幕光标大小和可见性
}

//------------------------------------
void Utils::setEnglish() {        //输入法切换为英文输入状态
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}

//----------------------------------------------------------
void Utils::save()      //存储最高分及名字
{
	FILE *fp;
	if (fopen_s(&fp, "Hero_list", "wb") != 0)
	{
		cout << "can not open file!" << endl; return;
	}
	if (fwrite(&Hero, sizeof(struct HeroList), 1, fp) != 1)
		cout << "file write error!" << endl;
	fclose(fp);
}


//-----------------------------