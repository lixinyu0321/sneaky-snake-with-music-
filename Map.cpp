#include"stdafx.h"
#include"windows.h"
#include"Map.h"
#include"CSnake.h"
#include"Utils.h"
#include"conio.h"
#include"CustomGame.h"
#include<iostream>
using namespace std;

void Map::initPartMap() {
	for (int i = 0; i<20; i++)      //初始化游戏面板 
		for (int j = 0; j<20; j++)
			image[i][j] = 0;   //置空
	for (int i = 0; i<4; i++)      //初始化小蛇初始位置
	{
		snake[0][i] = 1;     //各个节点横坐标为1  赋值横坐标
		snake[1][i] = i + 1;  //各节点纵坐标分别为1,2,3,4  赋值纵坐标
	}
	for (int i = 1; i <= 3; i++)  //初始化小蛇各节点图案
		image[1][i] = 3;
	image[1][4] = 1;
}


void Map::initPartMapCM() {

	for (int i = 0; i<4; i++)      //初始化小蛇初始位置
	{
		snakeCM[0][i] = 1;     //各个节点横坐标为1  赋值横坐标
		snakeCM[1][i] = i + 1;  //各节点纵坐标分别为1,2,3,4  赋值纵坐标
	}
}


void Map::display() { //显示游戏面板int& score,int& level,int& healthPoint
	utils.color(8);
	utils.gotoXY(1, 1);
	for (int i = 0; i<22; i++)
		printf("■");
	utils.gotoXY(1, 2);
	for (int i = 0; i<20; i++)
	{
		utils.color(8);
		printf("■");
		for (int j = 0; j<20; j++)
		{
			switch (image[i][j])
			{
			case 0:utils.color(15); printf("  "); break;
			case 1:utils.color(2); printf("○"); break;   //蛇头
			case 2:utils.color(12); printf("☆"); break;   //食物
			case 3:utils.color(13); printf("●"); break;    //蛇身节点
			case 4:utils.color(5); printf("▲"); break;     //障碍物
			}
		}  utils.color(8);
		printf("■\n");
	}
	utils.color(8);
	for (int i = 0; i<22; i++)
		printf("■");  utils.color(13);
	utils.color(12);
	utils.gotoXY(46, 5); printf("有趣的C++贪吃蛇游戏！\n");
	utils.gotoXY(46, 6); printf("少玩游戏，快去学习！\n");
}

void Map::setBackColor()//设置文本背景色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

int Map::showMenu() {
	utils.color(11);
	utils.gotoXY(46, 13);
	cout << "菜单：";
	Sleep(100);
	utils.gotoXY(46, 15);
	setBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	utils.gotoXY(46, 17);
	utils.color(11);
	std::cout << "保存游戏";
	Sleep(100);
	utils.gotoXY(46, 19);
	std::cout << "返回菜单";

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					utils.gotoXY(46,15);
					setBackColor();
					std::cout << "继续游戏";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "保存游戏";

					--tmp_key;
					break;
				case 3:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "保存游戏";
					utils.gotoXY(46, 19);
					utils.color(11);
					std::cout << "返回菜单";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "保存游戏";
					utils.gotoXY(46, 15);
					utils.color(11);
					std::cout << "继续游戏";

					++tmp_key;
					break;
				case 2:
					utils.gotoXY(46, 19);
					setBackColor();
					std::cout << "返回菜单";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "保存游戏";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		utils.gotoXY(0, 31);
	}

	if (tmp_key == 1) //选择继续游戏，则将菜单擦除
	{
		utils.gotoXY(46, 13);
		std::cout << "      ";
		utils.gotoXY(46, 17);
		std::cout << "        ";
		utils.gotoXY(46, 15);
		std::cout << "        ";
		utils.gotoXY(46, 19);
		std::cout << "        ";
	}
	return tmp_key;
}




int Map::showMenuCM() {
	utils.color(11);
	utils.gotoXY(46, 13);
	cout << "菜单：";
	Sleep(100);
	utils.gotoXY(46, 15);
	setBackColor();
	std::cout << "继续编辑";
	Sleep(100);
	utils.gotoXY(46, 17);
	utils.color(11);
	std::cout << "开始游戏";
	Sleep(100);
	utils.gotoXY(46, 19);
	std::cout << "返回菜单";

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					utils.gotoXY(46, 15);
					setBackColor();
					std::cout << "继续编辑";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "开始游戏";

					--tmp_key;
					break;
				case 3:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "开始游戏";
					utils.gotoXY(46, 19);
					utils.color(11);
					std::cout << "返回菜单";

					--tmp_key;
					break;
				}
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					utils.gotoXY(46, 17);
					setBackColor();
					std::cout << "开始游戏";
					utils.gotoXY(46, 15);
					utils.color(11);
					std::cout << "继续编辑";

					++tmp_key;
					break;
				case 2:
					utils.gotoXY(46, 19);
					setBackColor();
					std::cout << "返回菜单";
					utils.gotoXY(46, 17);
					utils.color(11);
					std::cout << "开始游戏";

					++tmp_key;
					break;
				}
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		utils.gotoXY(0, 31);
	}

	if (tmp_key == 1) //选择继续编辑，则将菜单擦除
	{
		utils.gotoXY(46, 13);
		std::cout << "      ";
		utils.gotoXY(46, 17);
		std::cout << "        ";
		utils.gotoXY(46, 15);
		std::cout << "        ";
		utils.gotoXY(46, 19);
		std::cout << "        ";
	}
	return tmp_key;

}
