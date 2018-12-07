#include "TextWindow.h"
#include "Timer.h"
#include "Snake.h"

#define FRAMERATE 30.0f

void capFrameRate(float frameRate) {

	static long frameClocker = clock();//sets the frame clocker to the current system clock

	while ((CLOCKS_PER_SEC / frameRate) > (clock() - frameClocker));//while the clocks per sec over the frame rate is
																	//greater than the current clock time minus the last clock time, stall the program
																	//this is done so that the program will slow down until the desired frame rate is reached

	frameClocker = clock();//sets the frame clocker to the newest system time
}



int main()
{


	TextWindow tw(800, 600);

	tw.SwapBackBuffer();

	

	std::vector<PixelSprite*> snakeVisuals;

	snakeVisuals.push_back(new PixelSprite(2, 1, 7));
	snakeVisuals.push_back(new PixelSprite(2, 1, 5));
	snakeVisuals.push_back(new PixelSprite(2, 1, 5));
	snakeVisuals.push_back(new PixelSprite(2, 1, 5));
	snakeVisuals.push_back(new PixelSprite(2, 1, 5));
	snakeVisuals.push_back(new PixelSprite(2, 1, 5));
	snakeVisuals.push_back(new PixelSprite(2, 1, 5));




	Snek Snake(snakeVisuals);

	//for (int i = 0; i < Snake.getBody().size(); i++) {
	//
	//	Snake.getBody(i)->SetPosition(Snake.getBody(i)->GetPosition().X + Snake.getBody(i)->GetSize()., Snake.getBody(i)->GetPosition().Y );
	//
	//}


	while (true)
	{
		capFrameRate(FRAMERATE);

		Snake.grow();
		//Snake.getBody(0)->SetPosition(Snake.getBody(0)->GetPosition().X + 1.0, Snake.getBody(0)->GetPosition().Y);
		COORD lastPosition = Snake.getBody(0)->GetPosition();
		if (isEvent(Events::W))
		{
			Snake.getDirection('U');
		}

		else if (isEvent(Events::S))
		{
			Snake.getDirection('D');
		}

		else if (isEvent(Events::A))
		{
			Snake.getDirection('L');
		}

		else if (isEvent(Events::D))
		{
			Snake.getDirection('R');
		}



		Snake.getDir();
		Timer::CalculateDeltaTime();
		tw.RenderSprite(*Snake.getBody(0));
		for (int i = Snake.getBody().size() - 1; i >= 0; i--) {

			tw.RenderSprite(*Snake.getBody(i));
			if (i == 0)
				Snake.getBody(i)->SetPosition(Snake.getBody(i)->GetPosition().X, Snake.getBody(i)->GetPosition().Y);
			else
				Snake.getBody(i)->SetPosition(Snake.getBody(i - 1)->GetPosition().X, Snake.getBody(i - 1)->GetPosition().Y);
		}
		

		tw.SwapBackBuffer();
		float check = Timer::GetDeltaTime();

	}

	
	return 0;
}

/*

						TO DO LIST:
________________________________________________________
			 \/
Start screen /\
					 /
Input for movement \/
					\/
Boundaries for Snek /\
							   \/
Spawn fruit randomly on screen /\
								  \/
Add to body for every fruit eaten /\
															  \/
Collision w/ walls and own tail results in instntaneous DEATH /\
				 \/
Game over screen /\

*/