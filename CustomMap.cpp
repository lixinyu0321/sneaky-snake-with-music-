#include "stdafx.h"
#include"CustomMap.h"
#include"Block.h"
#include"CustomGame.h"
#include"conio.h"
#include"CSnake.h"
#include<iostream>
using namespace std;

int imageCM[22][22];


void CustomMap::editMap() {

	for (int i = 0; i < 10; i++) {//初始化
		blockCM[i].blockX = 0;
		blockCM[i].blockY = 0;
	}

	for (int i = 0; i<20; i++)      //初始化
		for (int j = 0; j<20; j++)
			imageCM[i][j] = 0;   //置空

	for (int i = 1; i <= 3; i++)  //初始化蛇各节点图案
		imageCM[1][i] = 3;
	imageCM[1][4] = 1;

	displayCM();
	showCursorCM(false);
	MessageLoop();
	getchar();
	system("pause");
}

void CustomMap::MouseEventProc(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags) {
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			//左键单击添加墙体节点
			imageCM[x][y] = 5;

			displayCM();
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			//WriteChar(0,0,"右键单击",0x50);
			//右键单击添加障碍物
			
			if (n <=10) {
			for (int i = 0; i < 10; i++) {
				if (blockCM[i].blockX == 0) {
					blockCM[i].blockX = x;
					blockCM[i].blockY = y;
					imageCM[x][y] = 4;
					n++;
					break;
				}
			}
			}
			else {
				gotoXYCM(30,30);
				printf("已经达到障碍上限");
			}


			displayCM();

		}
		break;
	case DOUBLE_CLICK:
		//双击删除
	{
		//删除障碍
		if (imageCM[x][y]==4) {
			imageCM[x][y] = 0;
			for (int i = 0; i < 10; i++) {
				if (blockCM[i].blockX == x) {
					blockCM[i].blockX = 0;
					blockCM[i].blockY = 0;
					n--;
					break;
				}
			}
		}
		else imageCM[x][y] = 0;  //删除墙体

		displayCM();

	}
	break;
	case MOUSE_MOVED:
	{
		y = mer.dwMousePosition.X / 2;
		x = mer.dwMousePosition.Y; }
	break;

	}

}


void CustomMap::keyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown) {	
		char ch;
		ch = _getch();
		if (ch=='p') {
			CSnake cs;
			cs.pauseCM();
		}
	}
}


void CustomMap::MessageLoop() {
	Utils utils;
	utils.setEnglish();

	ShowCursor(false);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);


	while (1) {
		//等待事件
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//处理事件
		if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
		else if(stcRecord.EventType ==KEY_EVENT) {
			keyEventProc(stcRecord.Event.KeyEvent);
		}
	}
}

void CustomMap::showCursorCM(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;   //控制台光标信息结构类型
	cci.dwSize = 1;   //光标大小
	cci.bVisible = isShow;      //是否显示光标  true显示
	SetConsoleCursorInfo(hOutStd, &cci);   //设置控制台屏幕光标大小和可见性
}



void CustomMap::gotoXYCM(int x, int y)      //设定输出位置
{
	COORD c;   //光标位置
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//获取句柄，设置位置
	showCursorCM(false);   //取消光标闪烁
}

void CustomMap::colorCM(int a)              //颜色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}


void CustomMap::printRange() {
	colorCM(6);
	gotoXYCM(0, 22);
	for (int i = 0; i < 22; i++) {
		printf("--");
	}
	colorCM(6);
	for (int j = 0; j < 22; j++) {
		gotoXYCM(22 * 2, j);
		printf("|");
	}
}


void CustomMap::displayCM() {
	// system("cls");
	printRange();
	colorCM(7);
	gotoXYCM(25*2, 0);
	printf("《请按p键解锁后编辑地图》");
	gotoXYCM(24 * 2, 1);
	printf("注意事项：障碍物个数最多为10个");
	gotoXYCM(0, 0);
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			switch (imageCM[i][j]) {
			case 0:colorCM(15); printf("  "); break;
			case 1:colorCM(2); printf("○"); break;   //蛇头
			case 2:colorCM(12); printf("☆"); break;   //食物
			case 3:colorCM(13); printf("●"); break;    //蛇身节点
			case 4:colorCM(5); printf("▲"); break;     //障碍物
			case 5:colorCM(4); printf("■"); break;
			}
		}
		printf("\n");
	}
	showCursorCM(false);
}
