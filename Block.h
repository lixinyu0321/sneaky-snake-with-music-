#pragma once
class Block {
public:
	int blockX;
	int blockY;

	int generateBlock();
	void createBlockCM(Block* blockCM);
};