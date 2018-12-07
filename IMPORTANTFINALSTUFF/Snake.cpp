#include "Snake.h"

Snek::Snek(std::vector<PixelSprite*> SNEKBODY)//snek constructor
{
	this->body = SNEKBODY;//setting body vector to the provided vector
	this->head = body[0];//setting the head to the first element
}

Snek::Snek()//default constructor
{
}

std::vector<PixelSprite*> Snek::getBody()
{
	return this->body;//function that returns the body
}

PixelSprite * Snek::getBody(int e)
{
	return this->body[e];//function that returns a pixel sprite pointer at a given element number
}

void Snek::moveUP()
{
	//sets the position of the head to its current position - its height, so that the head moves up by 1 block
	this->head->SetPosition(this->head->GetPosition().X, this->head->GetPosition().Y - this->head->GetSize().Y);

}

void Snek::moveDOWN()
{
	//same thing as moveUP, just adding the height so it moves down
	this->head->SetPosition(this->head->GetPosition().X, this->head->GetPosition().Y + this->head->GetSize().Y);
}

void Snek::moveLEFT()
{
	//same thing as the other two, just on the x axis in the negative x direction
	this->head->SetPosition(this->head->GetPosition().X - this->head->GetSize().X, this->head->GetPosition().Y);
}

void Snek::moveRIGHT()
{
	//same thing as the other three, just on the x axis in the positive x direction
	this->head->SetPosition(this->head->GetPosition().X + this->head->GetSize().X, this->head->GetPosition().Y);
}

//this function is used so that the snake continues in one direction when you press a key
bool Snek::getDirection(char DIR)
{

	switch (DIR) {

	case 'U'://if we pass in U
		if (this->down == true)//if we're moving down
			break;//don't move up
		this->down = false; //reset the movement booleans so that we only move in one direction
		this->left = false;	//^
		this->right = false;//^
		return this->up = true;//return the appropriate direction
	case 'D':
		if (this->up == true)
			break;
		this->up = false;
		this->left = false;
		this->right = false;
		return this->down = true;
	case 'L':
		if (this->right == true)
			break;
		this->down = false;
		this->up = false;
		this->right = false;
		return this->left = true;
	case 'R':
		if (this->left == true)
			break;
		this->down = false;
		this->left = false;
		this->up = false;
		return this->right = true;

		
	}
	return false;//if we somehow get out of the switch statement, return false so that the program doesn't crash
}

void Snek::getDir()
{
	//the purpose of this wrapper function is so that the snake continuously moves in a given direction
	if(this->up)//if we press W
		this->moveUP();//move up
	else if (this->down)//else if we press S
		this->moveDOWN();//move down
	else if (this->left)
		this->moveLEFT();
	else if (this->right)
		this->moveRIGHT();
	

}
