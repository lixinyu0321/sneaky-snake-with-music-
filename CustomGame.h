#pragma once
#include"Utils.h"
#include"Block.h"
#include"CustomMap.h"
#include"Map.h"

extern int snakeCM[2][500];//记录小蛇所有身体的坐标
extern Block* blockCM;

class CustomGame {

public:
	Utils utils;
	Block block;
	CustomMap customMap;
	Map map;
	void playCGame();

};