#include "TextWindow.h"
#include "Timer.h"
#include "Snake.h"
#include <cstdlib>
#include <ctime>

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
	std::vector<PixelSprite*> eats(1, new PixelSprite(2,1,8));

	for (int i = 0; i < 2; i++)
		snakeVisuals.push_back(new PixelSprite(2, 1, 5));


	Snek Snake(snakeVisuals);

	Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);//set position to middle of screen
	Snake.getDirection('U');
	eats[0]->SetPosition(1, 1);
	static int count = 0;
	COORD randomPlace{ 0,0 };
	while (true)
	{
		srand(time(NULL));
		count++;
		if (count == 80) {
			randomPlace.X = rand() % tw.getConsoleSizeInPixels().X;
			randomPlace.Y = rand() % tw.getConsoleSizeInPixels().Y;
			count = 0;

		}

		eats[0]->SetPosition(randomPlace.X, randomPlace.Y);

		capFrameRate(FRAMERATE);
		tw.RenderSprite(*eats[0]);

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



		Timer::CalculateDeltaTime();
		
		for (int i = Snake.getBody().size() - 1; i > 0; i--)
		{
			Snake.getBody(i)->SetPosition(Snake.getBody(i - 1)->GetPosition().X, Snake.getBody(i - 1)->GetPosition().Y);
			
			tw.RenderSprite(*Snake.getBody(i));
		}
		Snake.getDir();
		tw.RenderSprite(*Snake.getBody(0));


		for (int i = 1; i < Snake.getBody().size(); i++)
		{

			if (Snake.getBody(0)->GetPosition().X == Snake.getBody(i)->GetPosition().X && Snake.getBody(0)->GetPosition().Y == Snake.getBody(i)->GetPosition().Y)
				Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);
			


			if (Snake.getBody(0)->GetPosition().X <= 0 || Snake.getBody(0)->GetPosition().X == tw.getConsoleSizeInPixels().X) 
				Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);



			if (Snake.getBody(0)->GetPosition().Y <= 0 || Snake.getBody(0)->GetPosition().Y == tw.getConsoleSizeInPixels().Y) 
				Snake.getBody(0)->SetPosition(tw.getConsoleSizeInPixels().X / 2, tw.getConsoleSizeInPixels().Y / 2);
			
		}
		for (int j = 0; j < eats.size(); j++) {
			if (Snake.getBody(0)->GetPosition().X == eats[j]->GetPosition().X && Snake.getBody(0)->GetPosition().Y == eats[j]->GetPosition().Y) {
				//add to score
				Snake.grow();
				randomPlace.X = rand() % tw.getConsoleSizeInPixels().X;
				randomPlace.Y = rand() % tw.getConsoleSizeInPixels().Y;
				eats[0]->SetPosition(randomPlace.X, randomPlace.Y);

			}
		}
		tw.SwapBackBuffer();
		float check = Timer::GetDeltaTime();
	}
	return 0;
}