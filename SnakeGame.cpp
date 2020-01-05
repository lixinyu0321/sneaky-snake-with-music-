
#include "stdafx.h"
#include <stdio.h>  
#include <windows.h>  
#include <time.h>  
#include <conio.h> 
#include"Utils.h"
#include"StartScreen.h"
#include"CSnake.h"
#include"SnakeGame.h"
#include"CustomGame.h"
#include <iostream>
#pragma comment(lib,"winmm.lib")
using namespace std;

HeroList Hero[10];
CSnake* SNAKE;

void main()         //主函数
{
	startGame();
}


void startGame() {
	if (SNAKE == NULL) {
		SNAKE = new CSnake();
	}

	char Name[10] = " ";
	char ch;    //菜单选择号
	Utils utils;
	utils.setWindows(80, 30);

	StartScreen ss;
	ss.Welcome();

	while (1)
	{
		utils.color(14);       // 主界面黄色
		utils.gotoXY(10 * 2, 1);
		cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
		utils.gotoXY(10 * 2, 2);
		cout << "   -----* - * - * - * - * - * - *----   " << endl;
		utils.gotoXY(10 * 2, 3);
		cout << "   《  ▁▁▁▁▁▁▁▁▁▁▁▁▁▁   》     " << endl;
		utils.gotoXY(10 * 2, 4);
		cout << "   《  ▏                          ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 5);
		cout << "   《  ▏       1.开始游戏         ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 6);
		cout << "   《  ▏       2.设置难度         ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 7);
		cout << "   《  ▏       3.游戏教程         ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 8);
		cout << "   《  ▏       4.高分榜           ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 9);
		cout << "   《  ▏       5.自定义           ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 10);
		cout << "   《  ▏       6.读取存档         ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 11);
		cout << "   《  ▏       7.退出             ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 12);
		cout << "   《  ▏                          ▏ 》     " << endl;
		utils.gotoXY(10 * 2, 13);
		cout << "   《  ▔▔▔▔▔▔▔▔▔▔▔▔▔▔   》     " << endl;
		utils.gotoXY(10 * 2, 14);
		cout << "   -----* - * - * - * - * - * - *----   " << endl;
		utils.gotoXY(10 * 2, 15);
		cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
		utils.gotoXY(10 * 2, 16);
		cout << "请输入的你的操作选项：";
		cin >> ch;

		if (ch == '1')
		{
			system("cls");

			if (SNAKE == NULL) {
				SNAKE = new CSnake();
			}
			
			SNAKE->playGame();
			system("cls");
			if (Hero[0].Highscore < 100)
			{
				cout << "真菜！" << endl; cout << endl;
			}
			else if (200 > Hero[0].Highscore&&Hero[0].Highscore >= 100)
			{
				cout << "加油！" << endl; cout << endl;
			}
			else if (400 > Hero[0].Highscore&&Hero[0].Highscore >= 200)
			{
				cout << "不错哦！" << endl; cout << endl;
			}
			else if (600 > Hero[0].Highscore&&Hero[0].Highscore >= 400)
			{
				cout << "太强啦！" << endl; cout << endl;
			}
			else
			{
				cout << "6666666666666666666" << endl; cout << endl;
			}
			if (Hero[0].Highscore > 10)
			{
				cout << "请输入您的大名：";
				cin >> Hero[0].Name;
				utils.save();
			}
			delete SNAKE;
			system("pause");
			system("cls");
			continue;
		}


		else if (ch == '2')
		{
			system("cls");
			SNAKE->setspeed();
			system("pause");
			system("cls");
			continue;
		}


		else if (ch == '3')       //详细使用说明
		{
			system("cls");
			cout << "                                                    " << endl;
			cout << "                                                    " << endl; utils.color(3);
			cout << "    *********************************************** " << endl; utils.color(3);
			cout << "    *   上移：8 ;       左移：4 ;    暂停：p      * " << endl;
			cout << "    *   下移：5 ;       右移：6 ;    退出：e      * " << endl; utils.color(3);
			cout << "    *********************************************** " << endl; utils.color(3);
			cout << "    $            请根据上面键进行操作!            $ " << endl;
			cout << "    $         编辑自定义地图请先按p键解锁！       $ " << endl;
			cout << "    $ 鼠标左键是墙，右击是障碍物，左键双击是删除! $ " << endl; utils.color(3);
			cout << "    #-------------------------------------------- # " << endl;
			cout << "    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
			cout << "                                                    " << endl;
			cout << "                                                    " << endl;
			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '4')                                             // 记录最高分，显示英雄榜
		{
			system("cls");
			utils.color(10);

			FILE *fp;
			fopen_s(&fp, "Hero_list", "rb");
			fread(&Hero, sizeof(struct HeroList), 1, fp);

			for (int i = 0; i < 10 && Hero[i].Highscore != 0; i++) {

				cout << "$#######_---   高分榜：  ---_#######$" << endl;
				cout << "               名字:" << Hero[i].Name << endl;
				cout << "               分数:" << Hero[i].Highscore << endl;
				cout << "--------------------------------------------" << endl;
			}

			fclose(fp);

			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '5') {//自定义游戏
			system("cls");
			CustomGame customGame;
			customGame.customMap.editMap();

			system("pause");
			system("cls");
		}
		else if (ch == '6') {//读取存档游戏
			system("cls");
			SNAKE->readGame();
			SNAKE->playGame();


			system("cls");
			if (Hero[0].Highscore < 100)
			{
				cout << "真菜！" << endl; cout << endl;
			}
			else if (200 > Hero[0].Highscore&&Hero[0].Highscore >= 100)
			{
				cout << "加油！" << endl; cout << endl;
			}
			else if (400 > Hero[0].Highscore&&Hero[0].Highscore >= 200)
			{
				cout << "不错哦！" << endl; cout << endl;
			}
			else if (600 > Hero[0].Highscore&&Hero[0].Highscore >= 400)
			{
				cout << "太强啦！" << endl; cout << endl;
			}
			else
			{
				cout << "6666666666666666666" << endl; cout << endl;
			}
			if (Hero[0].Highscore > 10)
			{
				cout << "请输入您的大名：";
				cin >> Hero[0].Name;
				utils.save();
			}
			delete SNAKE;
			system("pause");
			system("cls");
			continue;

		}
		else if (ch == '7')//退出游戏
		{
			system("cls");
			exit(0);
		}
		else
		{
			system("cls");
			cout << "请重新输入！" << endl;
			continue;
		}
	}

}