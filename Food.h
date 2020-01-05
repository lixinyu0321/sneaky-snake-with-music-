#pragma once

class Food{
	int FoodX; //食物的X坐标			   
	int FoodY; //食物的Y坐标
public:
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int generatefood();
	int createFoodCM();

};