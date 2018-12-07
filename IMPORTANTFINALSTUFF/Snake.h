#pragma once
#include <vector>
#include "Sprite.h"
#include "Events.h"
#include "Input.h"


class Snek {
public:

	Snek(std::vector<PixelSprite*>);
	Snek();

	std::vector<PixelSprite*> getBody();
	PixelSprite* getBody(int e);

	void moveUP();
	void moveDOWN();
	void moveLEFT();
	void moveRIGHT();


	void grow();
	bool getDirection(char DIR);
	bool isDoingAHeck();
	bool isNomFroot();

	void getDir();

private:

	std::vector<PixelSprite*> body;
	PixelSprite* head;

	int currentPositionX;
	int currentPositionY;

	int lastPositionX;
	int lastPositionY;


	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

	//int length = 4;

	

};

//body[0] = new PixelSprite(1, 1, 4);