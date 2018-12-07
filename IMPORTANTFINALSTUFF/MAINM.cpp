#include "TextWindow.h"
#include "Timer.h"
#include "Snake.h"

int main()
{
	TextWindow tw(800, 600);
	//char buffer[] = { 'l','k','m','o' };
	//Sprite mySprite(buffer, 2, 2);
	//tw.RenderSprite(mySprite);
	//AnimatedSprite aps;
	//aps.AddSprite(PixelSprite(20, 20, 5));
	//aps.AddSprite(PixelSprite(20, 20, 6));
	//char Buffer[2] = { 'l','a' };
	//	PixelSprite sp(1, 1, 2);
	tw.SwapBackBuffer();

	bool eatFruit = false;

	PixelSprite fruit(1, 1, 3);

	std::vector<PixelSprite*> Fruits;

	std::vector<PixelSprite*> snakeVisuals;

	snakeVisuals.push_back(new PixelSprite(2, 1, 6));
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

		Sleep(20);
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

			if(i == 0)
				Snake.getBody(i)->SetPosition(Snake.getBody(i)->GetPosition().X, Snake.getBody(i)->GetPosition().Y);
			else
			Snake.getBody(i)->SetPosition(Snake.getBody(i - 1)->GetPosition().X , Snake.getBody(i - 1)->GetPosition().Y);
			tw.RenderSprite(*Snake.getBody(i));
		}
		//	Fruits[0]->SetPosition(500, 10);
			//tw.RenderSprite(Snake.getBody(0));
			//tw.RenderSprite(fruit);
		tw.SwapBackBuffer();
		float check = Timer::GetDeltaTime();

	}

	////if(eat fruit)
	//Snake.push_back(new PixelSprite(1, 1, 7));
	//Snake.push_back(new PixelSprite(1, 1, 7));
	//Snake.push_back(new PixelSprite(1, 1, 7));
	//
	//Fruits.push_back(new PixelSprite(1, 1, 3));
	//
	//	while (true)
	//	{
	//		Sleep(40);
	//		Snake[0]->SetPosition(Snake[0]->GetPosition().X + 1.0, Snake[0]->GetPosition().Y);
	//		Timer::CalculateDeltaTime();
	//		//tw.RenderSprite(aps.GetAnimation());
	//		Fruits[0]->SetPosition(500, 10);
	//		tw.RenderSprite(fruit);
	//		tw.SwapBackBuffer();
	//		float check = Timer::GetDeltaTime();
	//	}
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