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


	std::vector<PixelSprite*> snakeVisuals(1, new PixelSprite(2, 1, 7));

	for (int i = 0; i < 1; i++)
		snakeVisuals.push_back(new PixelSprite(2, 1, 5));




	Snek Snake(snakeVisuals);
	//for (int i = 0; i < Snake.getBody().size(); i++) {
	//
	//	Snake.getBody(i)->SetPosition(Snake.getBody(i)->GetPosition().X + Snake.getBody(i)->GetSize()., Snake.getBody(i)->GetPosition().Y );
	//
	//}

	Snake.getDirection('R');
	while (true)
	{

		capFrameRate(FRAMERATE);

		//	Snake.grow();
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



		//Snake.getDir();
		Timer::CalculateDeltaTime();
		//tw.RenderSprite(*Snake.getBody(0));
				//Snake.getBody(0)->SetPosition(400, 300);

		for (int i = Snake.getBody().size() - 1; i > 0; i--)
		{
			//if (i == 0)
			//	
			//else
			
				Snake.getBody(i)->SetPosition(Snake.getBody(i - 1)->GetPosition().X, Snake.getBody(i - 1)->GetPosition().Y);
			
			tw.RenderSprite(*Snake.getBody(i));
		}
		Snake.getDir();
		Snake.getBody(0)->SetPosition(Snake.getBody(0)->GetPosition().X, Snake.getBody(0)->GetPosition().Y);
		tw.RenderSprite(*Snake.getBody(0));
		for (int i = 1; i < Snake.getBody().size(); i++)
		{
			if (Snake.getBody(0)->GetPosition().X == Snake.getBody(i)->GetPosition().X && Snake.getBody(0)->GetPosition().Y == Snake.getBody(i)->GetPosition().Y)
			{
				Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);
			}
			if (Snake.getBody(0)->GetPosition().X <= 0 || Snake.getBody(0)->GetPosition().X == tw.getConsoleSizeInPixels().X) 
				Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);

			if (Snake.getBody(0)->GetPosition().Y <= 0 || Snake.getBody(0)->GetPosition().Y == tw.getConsoleSizeInPixels().Y) 
				Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);

		
		}
		//tw.RenderSprite(*Snake.getBody(0));

		//check collision
		//if (Snake.getBody(0)->GetPosition().X == 0 || Snake.getBody(0)->GetPosition().X == 800)
		//{
		//	tw.RenderSprite(*Snake.getBody(0), tw.makeVec2(400, 300));
		//}
		//
		//if (Snake.getBody(0)->GetPosition().Y == 0 || Snake.getBody(0)->GetPosition().Y == 600)
		//{
		//	tw.RenderSprite(*Snake.getBody(0), tw.makeVec2(400, 300));
		//}

		tw.SwapBackBuffer();
		float check = Timer::GetDeltaTime();
	}
	return 0;
}