#pragma once
#include"Food.h"
#include"Map.h"
#include"Utils.h"
#include"Block.h"
#include"CustomMap.h"

class Food;
class Map;
class Utils;
class Block;

extern int image[20][20]; //蛇活动范围
extern int snake[2][500];//记录小蛇所有身体的坐标


class CSnake{
public:
	Food food;
	Map map;
	Utils utils;
	Block block;
	CustomMap customMap;

	Food foodCM;


	int snakeX;               //记录小蛇的头部X坐标
	int snakeY;               //记录小蛇的头部Y坐标
	int head;                 //小蛇头部下标
	int tail;                 //小蛇尾部下标
	int node;                 //蛇的节点数
	int direction;            //蛇头方向   

	int healthPoint;  //蛇的生命值

	int gamespeed;            //游戏速度
	int score;                //分数
	char arrowKey;            //接收按键的变量
	int gameOver;             //使游戏结束的变量
	int level;                //设置等级
	int length;               //根据长度设置等级


	CSnake()   //构造函数初始化部分变量
	{
		healthPoint = 100;   //初始化生命值为100
		head = 3;                //初始化头部下标
		tail = 0;                //初始化尾部下标
		node = 4;                //蛇初始为四节点
		gamespeed = 300;         //游戏速度（移动的间隔时间ms）
		score = 0;               //初始化分数为0
		direction = 6;           //蛇的初始方向向右
		gameOver = 0;            //进入游戏初始化为0
		level = 1;
		length = 4;
	}
	~CSnake(){}
//	void Init();                //初始化游戏面板及小蛇的坐标
	int  drawSnake();           //记录小蛇每次移动后头部及身体的下一坐标

	int drawSnakeCM();

	void  automove();            //蛇自动移动
	void automoveCM();


	int  gameover();            //判断游戏是否结束
	int gameoverCM();

//	int  Generatefood();        //产生食物
	void display_er();             //显示玩家数据
	void displayCMer();



	void toLeft();           //左移
	void toRight();          //右移
	void toDown();           //下移
	void toUp();	         //上移
	int  playGame();            //执行游戏
	void setspeed();            //设置速度

	int pause();                //游戏的暂停
	int pauseCMGame();    //自定义游戏的暂停
	int pauseCM();    //自定义编辑地图的暂停

	void saveGame();
	void readGame();
};