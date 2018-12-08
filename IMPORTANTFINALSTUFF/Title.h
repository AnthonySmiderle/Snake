#pragma once
#include "TextWindow.h"
#include <string>

class Title : public TextWindow
{
	public:
		Title();

		std::string display(std::string);


	private:
		std::string userid = "Anthony Smiderle\nMichelle Escpobar\nJordan McGill\nKristian Menes\nJeremy Kan\nAbbey Finestone";
		std::string name = "100695532\n100709888\n100716900\n100383679\n100704536\n100699864\n";
		std::string howto = "Press the WASD keys to move the snake. \nCollect fruit to grow your snake! \nLook out for the walls, and your own tail!";
};