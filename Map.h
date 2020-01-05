#pragma once
#include"Utils.h"

class Utils;

class Map {
	Utils utils;
public:
	void initPartMap(); //初始化部分地图数据
	void initPartMapCM();

	void display();// 显示游戏面板（包括围墙、食物及小蛇）

	int showMenu();
	int showMenuCM();
	void setBackColor();
};

