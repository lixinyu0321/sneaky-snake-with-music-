#include"stdafx.h"
#include"Block.h"
#include"time.h"
#include"stdlib.h"
#include"CSnake.h"


int Block::generateBlock() {   //生成第几个障碍物
	srand((unsigned int)time(NULL));       //以时间为种子生成随机序列
	do {
	
		blockX = (rand() % 20);
		blockY = (rand() % 20);

	} while (image[blockX][blockY] != 0);    //产生的食物坐标限定在游戏面板内，且食物坐标不与小蛇身体坐标重合
	image[blockX][blockY] = 4;
	return image[blockX][blockY];

}

void Block::createBlockCM(Block* blockCM) {

	srand((unsigned int)time(NULL));       //以时间为种子生成随机序列
	int count = 0;
	for (int i = 0; i < 10;i++) {
		if (blockCM[i].blockX == 0) {
			count = i;
			break;
		}
	}

	do {

		blockCM[count].blockX = (rand() % 20);
		blockCM[count].blockY = (rand() % 20);

	} while (image[blockCM[count].blockX][blockCM[count].blockY] != 0);    //产生的食物坐标限定在游戏面板内，且食物坐标不与小蛇身体坐标重合
	image[blockCM[count].blockX][blockCM[count].blockY] = 4;

}