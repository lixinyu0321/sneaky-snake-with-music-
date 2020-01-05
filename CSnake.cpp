#include "stdafx.h"
#include <windows.h>  
#include <time.h>  
#include <conio.h> 
#include"CSnake.h"
#include"Utils.h"
#include"Food.h"
#include"Map.h"
#include"SnakeGame.h"
#include"CustomMap.h"
#include"CustomGame.h"
#include <iostream>
#include<string.h>
#include<fstream>
#pragma comment(lib,"winmm.lib")
using namespace std;

int image[20][20];        //蛇活动范围s
int snake[2][500];       //记录蛇所有身体的坐标

//---------------------------------------------------------------
int CSnake::gameover()    //判断游戏是否结束
{
	//生命值为零，游戏结束
	if (healthPoint == 0) {
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}

	if (snakeX < 0 || snakeX>19 || snakeY < 0 || snakeY>19)    // 碰到墙壁游戏结束
	{
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}
	if ((image[snakeX][snakeY] != 0) && !(snakeX == food.getX() && snakeY == food.getY())
		&& !(snakeX == block.blockX && snakeY == block.blockY))   //蛇头碰到蛇身游戏结束
	{
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}
	return 0;
}

//---------------------------------------------------------
int CSnake::gameoverCM()    //判断自定义游戏是否结束
{
	//生命值为零，游戏结束
	if (healthPoint == 0) {
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}
	if (snakeX < 0 || snakeX>21 || snakeY < 0 || snakeY>21)    // 碰到墙壁游戏结束
	{
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}
	if (imageCM[snakeX][snakeY] == 5)    // 碰到墙壁游戏结束
	{
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}


	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (blockCM[i].blockX == snakeX) {
			count = i;
			break;
		}
	}


	if ((imageCM[snakeX][snakeY] != 0) && !(snakeX == foodCM.getX() && snakeY == foodCM.getY())
		&& !(snakeX == blockCM[count].blockX && snakeY == blockCM[count].blockY))   //蛇头碰到蛇身游戏结束
	{
		utils.gotoXY(1, 25);
		cout << "游戏结束!" << endl;
		gameOver = 1;
		return gameOver;
	}

	return 0;
}


//----------------------------------------------------------------
int CSnake::drawSnake()
{
	if (snakeX == food.getX() && snakeY == food.getY())  //若小蛇头部坐标与食物坐标重叠则吃掉食物
	{
		node++;     // 蛇节点数增一
		score += 10;   //分数增加 


		length++;
		if (length >= 10)     //当蛇增长到10节点，等级加一
		{
			length -= 10;
			level++;
			gamespeed -= 20;

		}
		image[snakeX][snakeY] = 1;      //小蛇头部移动的下一位置头部图像对应的值赋给图像
		image[snake[0][head]][snake[1][head]] = 3;   //小蛇头部其后紧跟的身体一格移动的下一位置头部图像对应的值赋给图像
		head = (head + 1) % 10000;
		snake[0][head] = snakeX;     //将小蛇头部此时的坐标值赋给记录头部坐标的snake[0][head]
		snake[1][head] = snakeY;
		food.generatefood();              	//吃掉食物后再随机生成食物
		map.display();        //刷新显示
		display_er();
	}
	else if (snakeX == block.blockX && snakeY == block.blockY) {  //撞到障碍物

		healthPoint -= 20;  //掉血
		image[snake[0][tail]][snake[1][tail]] = 0;   //擦去小蛇尾部
		tail = (tail + 1) % 10000;
		image[snake[0][head]][snake[1][head]] = 3;    //小蛇头部其后紧跟的身体一格移动的下一位置头部图像对应的值赋给图像
		head = (head + 1) % 10000;
		snake[0][head] = snakeX;                     //将小蛇头部此时的坐标值赋给记录头部坐标的snake[0][head]
		snake[1][head] = snakeY;
		image[snake[0][head]][snake[1][head]] = 1;   //小蛇头部移动的下一位置头部图像对应的值赋给图像

		block.generateBlock();  //生成新的障碍

		map.display();
		display_er();

	}

	else
	{                                               //没有吃食物
		image[snake[0][tail]][snake[1][tail]] = 0;   //擦去小蛇尾部

		tail = (tail + 1) % 10000;

		image[snake[0][head]][snake[1][head]] = 3;   //小蛇头部后一格移动的下一位置头部图像对应的值赋给图像
		head = (head + 1) % 10000;
		snake[0][head] = snakeX;                     //将小蛇头部坐标值赋给记录头部坐标的snake[0][head]
		snake[1][head] = snakeY;
		image[snake[0][head]][snake[1][head]] = 1;   //小蛇头部移动的下一位置头部图像对应的值赋给图像
		map.display();
		display_er();
	}
	return 0;
}


//---------------------------------------------------
int CSnake::drawSnakeCM() {

	if (snakeX == foodCM.getX() && snakeY == foodCM.getY())  //若小蛇头部坐标与食物坐标重叠则吃掉食物
	{
		node++;     // 蛇节点数增一
		score += 10;   //分数增加 

		length++;
		if (length >= 10)     //当蛇增长到10个节点，等级加一
		{
			length -= 10;
			level++;
			gamespeed -= 20;
		}
		imageCM[snakeX][snakeY] = 1;      //下一位置头部图像对应的值赋给图像数组
		imageCM[snakeCM[0][head]][snakeCM[1][head]] = 3;   //下一位置图像对应的值赋给图像数组

		head = (head + 1) % 10000;

		snakeCM[0][head] = snakeX;     //将小蛇头部坐标值赋给记录头部坐标的snake[0][head]
		snakeCM[1][head] = snakeY;
		//吃掉食物后再随机生成食物
		foodCM.createFoodCM();
		//刷新显示
		customMap.displayCM();
		display_er();
	}
	else
	{                                               //没有吃食物
		imageCM[snakeCM[0][tail]][snakeCM[1][tail]] = 0;   //擦去小蛇尾部
		tail = (tail + 1) % 10000;
		imageCM[snakeCM[0][head]][snakeCM[1][head]] = 3;   //下一位置头部图像对应的值赋给图像数组
		head = (head + 1) % 10000;
		snakeCM[0][head] = snakeX;                     //将蛇头部此时的坐标值赋给记录头部坐标的snake[0][head]
		snakeCM[1][head] = snakeY;
		imageCM[snakeCM[0][head]][snakeCM[1][head]] = 1;   //下一位置头部图像对应的值赋给图像数组
		customMap.displayCM();
		display_er();
	}




	//吃到自定义的障碍物
	for (int i = 0; i < 10; i++) {
		if (snakeX == blockCM[i].blockX && snakeY == blockCM[i].blockY) {
			healthPoint -= 20;  //掉血
			imageCM[snakeCM[0][tail]][snakeCM[1][tail]] = 0;   //擦去小蛇尾部
			tail = (tail + 1) % 10000;
			imageCM[snakeCM[0][head]][snakeCM[1][head]] = 3;    //下一位置头部图像对应的值赋给图像数组
			head = (head + 1) % 10000;
			snakeCM[0][head] = snakeX;                     //将蛇头部坐标值赋给记录头部坐标的snake[0][head]
			snakeCM[1][head] = snakeY;
			imageCM[snakeCM[0][head]][snakeCM[1][head]] = 1;   //下一位置头部图像对应的值赋给图像数组

            //生成新的障碍
			blockCM[i].createBlockCM(blockCM);
			customMap.displayCM();
			display_er();
		}
	}

	return 0;
}






//-----------------------------------------------------------
void CSnake::toLeft()      //向左
{
	direction = 4;
}
//++++++++++++++++++++++++++
void CSnake::toRight()            //向右
{
	direction = 6;
}
//+++++++++++++++++++++++++++
void CSnake::toUp()        //向上
{
	direction = 8;
}
//+++++++++++++++++++++++++++
void CSnake::toDown()      //向下
{
	direction = 2;
}
//------------------------------------------------------
void CSnake::automove()
{
	switch (direction)
	{
		//向右，蛇头部Y坐标加一，X坐标不变
	case 6:snakeX = snake[0][head]; snakeY = snake[1][head] + 1; break;

		//向左Y坐标减一，X坐标不变
	case 4:snakeX = snake[0][head]; snakeY = snake[1][head] - 1; break;

		//向上X坐标加一，Y坐标不变
	case 8:snakeX = snake[0][head] - 1; snakeY = snake[1][head]; break;

		//向下X坐标加一，Y坐标不变
	case 2:snakeX = snake[0][head] + 1; snakeY = snake[1][head]; break;
	default:;
	}
}

//---------------------------------------------
void CSnake::automoveCM() {
	switch (direction)
	{
		//向右，蛇头部Y坐标加一，X坐标不变
	case 6:snakeX = snakeCM[0][head]; snakeY = snakeCM[1][head] + 1; break;

		//向左Y坐标减一，X坐标不变
	case 4:snakeX = snakeCM[0][head]; snakeY = snakeCM[1][head] - 1; break;

		//向上X坐标加一，Y坐标不变
	case 8:snakeX = snakeCM[0][head] - 1; snakeY = snakeCM[1][head]; break;

		//向下X坐标加一，Y坐标不变
	case 2:snakeX = snakeCM[0][head] + 1; snakeY = snakeCM[1][head]; break;
	default:;
	}
}


//----------------------------------------------------
void CSnake::setspeed()     //设置小蛇移动的速度
{
	int flag = 0;
	while (!flag)
	{
		int speed;
		utils.color(12);
		cout << "1.非常慢   2.慢   3.正常   4.快   5.非常快 " << endl;
		cout << "请输入您的选择：";
		cin >> speed;
		switch (speed)
		{
		case 0:
			flag = 1;
			gamespeed = 300;
			break;
		case 1:
			gamespeed = 300;
			flag = 1;
			break;
		case 2:
			gamespeed = 200;
			flag = 1;
			break;
		case 3:
			gamespeed = 80;
			flag = 1;
			break;
		case 4:
			gamespeed = 30;
			flag = 1;
			break;
		case 5:
			gamespeed = 12;
			flag = 1;
			break;
		default:
			flag = 0;
		}
	}
}
//-----------------------------------------------------------
int CSnake::pause()                   //暂停功能
{

	int tmp = map.showMenu();//展示菜单并返回值

	if (tmp == 1) { arrowKey = 0; return arrowKey; }  //继续游戏
	else if (tmp == 2) {
		//保存游戏
		saveGame();
		system("cls");
		PlaySoundA(NULL, NULL, SND_FILENAME);//关闭音乐
		startGame();

	}
	else {
		system("cls");
		PlaySoundA(NULL, NULL, SND_FILENAME);
		startGame();
	}  //退出游戏到操作界面

	return 0;

}
//---------------------------------------
//自定义游戏中的暂停
int CSnake::pauseCMGame() {
	char c;
	do {
		c = _getch();
	} while (c != 'p');
	arrowKey = 0;
	return arrowKey;
}

//---------------------------------
int CSnake::pauseCM() {
	int tmp = map.showMenuCM();//菜单并返回值

	if (tmp == 1) { arrowKey = 0; return arrowKey; }  //继续编辑
	else if (tmp == 2) {//开始游戏

		system("cls");
		CustomGame customGame;
		customGame.playCGame();

	}
	else {
		delete blockCM;
		system("cls");
		startGame();
	}

	return 0;
}




//--------------------------------------------   
int CSnake::playGame()        //执行游戏
{
	int a[20][20] = { 0 };
	if (memcmp(image, a, sizeof(image)) == 0) {
		map.initPartMap();          //初始化数据
		food.generatefood();           //产生食物
		block.generateBlock();
	}

	map.display();                //显示游戏面板
	display_er();
	utils.showCursor(false);
	PlaySoundA("sound\\bg_snake.wav", NULL, SND_ASYNC | SND_LOOP);   //循环播放背景音效
	utils.setEnglish();  //切换英文输入法

	while (!gameOver)
	{
		if (_kbhit())          //接收按键
		{
			arrowKey = _getch();
		}
		if (direction == 2 || direction == 8)  //移动方向为上下时，左右键才起作用
		{
			switch (arrowKey)
			{
			case'6':toRight(); break;
			case'4':toLeft(); break;
			case'e':exit(1); break;
			case'p':pause(); break;
			default:;//break;
			}
		}
		else if (direction == 4 || direction == 6)  //移动方向为左右时，上下键才起作用
		{
			switch (arrowKey)
			{
			case'8':toUp(); break;
			case'5':toDown(); break;
			case'e':exit(1); break;
			case'p':pause(); break;
			default:;//break;
			} 
		}
		Sleep(gamespeed);    //小蛇移动速度
		automove();			   // 小蛇自动移动
		gameover();            //判断游戏是否结束
		if (gameOver == 1) {     //游戏结束跳出循环
			PlaySoundA("sound\\die.wav", NULL, SND_ASYNC | SND_NODEFAULT);   //播放死亡背景音效
			break;
		}
		drawSnake();        //判断是否吃食物 
		map.display();       //显示游戏面板
		display_er();     //显示玩家数据
		utils.showCursor(false);
	}

	Hero[0].Highscore = score;
	return 0;
}


void CSnake::display_er() {
	utils.gotoXY(46, 9); printf("SCORE:     ");      //分数
	utils.gotoXY(46, 10); printf("LEVEL:    "); //等级
	utils.gotoXY(46, 11); printf("HP:       ");  //生命值

	utils.gotoXY(46, 9); printf("SCORE: %d", SNAKE->score);      //分数
	utils.gotoXY(46, 10); printf("LEVEL: %d", SNAKE->level); //等级
	utils.gotoXY(46, 11); printf("HP: %d", SNAKE->healthPoint);  //生命值
}
//-------------------------------
void CSnake::displayCMer() {      //显示自定义地图玩家数据
	utils.gotoXY(46, 9); printf("SCORE:     ");      //分数
	utils.gotoXY(46, 10); printf("LEVEL:    "); //等级
	utils.gotoXY(46, 11); printf("HP:       ");  //生命值

	utils.gotoXY(46, 9); printf("SCORE: %d", this->score);      //分数
	utils.gotoXY(46, 10); printf("LEVEL: %d", this->level); //等级
	utils.gotoXY(46, 11); printf("HP: %d", this->healthPoint);  //生命值
}




void CSnake::saveGame() {
	FILE * file;
	if (fopen_s(&file, "snake1.txt", "wb") != 0)
	{
		cout << "can not open file!" << endl; return;
	}
	if (fwrite(&SNAKE, sizeof(CSnake), 1, file) != 1)
		cout << "file write error!" << endl;
	fclose(file);

	ofstream out1("snake2.txt");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 500; j++) {
			out1 << snake[i][j] << ' ';
		}
		out1 << endl;
	}
	out1.close();


	//image;
	ofstream out2("image.txt");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			out2 << image[i][j] << ' ';
		}
		out2 << endl;
	}
	out2.close();


	//保存完成界面
	utils.color(11);
	utils.gotoXY(10, 20);
	cout << "━━━━━━━━━━━━━━━━━━━━━━";
	utils.gotoXY(9, 21);
	cout << " ┃              保存成功 !!!              ┃";
	utils.gotoXY(10, 22);
	cout << "━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(500);

}


void CSnake::readGame() {   //读取上一次游戏数据

	int x[20][20];
	FILE* fp1;
	int flag1 = fopen_s(&fp1, "image.txt", "rb");   //游戏图像数据
	if (flag1 == 0) {
		cout << "open file" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				fscanf_s(fp1, "%d", &x[i][j]);
			}
		}
	}
	fclose(fp1);

	memcpy(image, x, sizeof(x));

	int y[2][500];
	FILE* fp2;
	int flag2 = fopen_s(&fp2, "snake2.txt", "rb");  //游戏蛇位置数据
	if (flag2 == 0) {
		cout << "open file" << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 500; j++) {
				fscanf_s(fp2, "%d", &y[i][j]);
			}
		}
	}
	fclose(fp2);

	memcpy(snake, y, sizeof(y));

	FILE *fp;
	if (fopen_s(&fp, "snake1.txt", "rb") == 0) {  //游戏中蛇的各种属性
		fread(&SNAKE, sizeof(CSnake), 1, fp);
	}
	fclose(fp);
}