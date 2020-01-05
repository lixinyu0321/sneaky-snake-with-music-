#include "stdafx.h"
#include"stdlib.h"
#include"time.h"
#include"Food.h"
#include"CSnake.h"


int Food::generatefood() {
	
	srand((unsigned int) time(NULL));       //以时间为种子生成随机序列
	do {
		//	food.getX() = rand() % 20;       //食物输出的X坐标
		//	food.getY() = rand() % 20;      //食物输出的Y坐标
		setX(rand() % 20);
		setY(rand() % 20);



	} while (image[getX()][getY()] != 0);    //产生的食物坐标限定在游戏面板内，且食物坐标不与小蛇身体坐标重合
	image[getX()][getY()] = 2;
	return image[getX()][getY()];

}


int Food::createFoodCM() {
	srand((unsigned int)time(NULL));       //以时间为种子生成随机序列
	do {
		//	food.getX() = rand() % 20;       //食物输出的X坐标
		//	food.getY() = rand() % 20;      //食物输出的Y坐标
		setX(rand() % 20);
		setY(rand() % 20);


	} while (imageCM[getX()][getY()] != 0);    //产生的食物坐标限定在游戏面板内，且食物坐标不与小蛇身体坐标重合
	imageCM[getX()][getY()] = 2;
	return imageCM[getX()][getY()];

}





int Food::getX() { return FoodX; }
int Food::getY() { return FoodY; }
void Food::setX(int x) { this->FoodX = x; }
void  Food::setY(int y) { this->FoodY = y; }