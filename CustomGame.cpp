#include "stdafx.h"
#include"CustomGame.h"
#include"CustomMap.h"
#include"Food.h"
#include"CSnake.h"
#include"Utils.h"
#include"SnakeGame.h"
#include"conio.h"


int snakeCM[2][500];   //保存自定义地图蛇位置的数组
Block* blockCM = new Block[10];//保存自定义障碍物数组


void CustomGame::playCGame() {

	CSnake cs;
	int a[22][22] = { 0 };
	if (memcmp(imageCM, a, sizeof(imageCM)) == 0) {
	
		map.initPartMapCM();
		cs.foodCM.createFoodCM();           //产生食物
		blockCM[0].createBlockCM(blockCM);
	}
	map.initPartMapCM();
	cs.foodCM.createFoodCM();           //产生食物

	customMap.displayCM();//显示地图

	cs.displayCMer();//显示玩家数据

	utils.showCursor(false);
	PlaySoundA("sound\\bg_snake.wav", NULL, SND_ASYNC | SND_LOOP);   //循环播放背景音效
	utils.setEnglish();  //切换英文输入法

	while (!cs.gameOver)
	{
		if (_kbhit())          //接收按键
		{
			cs.arrowKey = _getch();
		}
		if (cs.direction == 2 || cs.direction == 8)  //移动上下时，左右可用
		{
			switch (cs.arrowKey)
			{
			case'6':cs.toRight(); break;
			case'4':cs.toLeft(); break;
			case'e':exit(1); break;
			case'p':cs.pauseCMGame(); break;
			default:;//break;
			}
		}
		else if (cs.direction == 4 || cs.direction == 6)  //移动左右时，上下可用
		{
			switch (cs.arrowKey)
			{
			case'8':cs.toUp(); break;
			case'5':cs.toDown(); break;
			case'e':exit(1); break;
			case'p':cs.pauseCMGame(); break;
			default:;// break;
			}
		}
		Sleep(cs.gamespeed);    //移动一格的速度
		cs.automoveCM();			   // 小蛇自动移动
		cs.gameoverCM();            //判断游戏是否结束
		if (cs.gameOver == 1) {     //游戏结束跳出循环
			PlaySoundA("sound\\die.wav", NULL, SND_ASYNC | SND_NODEFAULT);   //播放死亡背景音效
			break;
		}
		cs.drawSnakeCM();        //判断是否吃食物 
		 //显示游戏面板
		customMap.displayCM();

		cs.displayCMer();     //显示玩家数据

		utils.showCursor(false);
	}

	delete blockCM;
	system("pause");
	system("cls");
	exit(1);
}