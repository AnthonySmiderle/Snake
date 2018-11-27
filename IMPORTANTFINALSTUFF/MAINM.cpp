#include "TextWindow.h"
#include "Timer.h"

int main() {

	TextWindow tw(800, 600);
	char buffer[] = { 'l','k','m','o' };
	Sprite mySprite(buffer,2,2);
	//tw.RenderSprite(mySprite);
	tw.SwapBackBuffer();
	AnimatedSprite aps;
	//aps.AddSprite(PixelSprite(20, 20, 5));
	//aps.AddSprite(PixelSprite(20, 20, 6));
	char Buffer[2] = { 'l','a' };
	Sprite sp(Buffer, 2, 1);
	while (true) {

		
		Timer::CalculateDeltaTime();
		//tw.RenderSprite(aps.GetAnimation());
		tw.RenderSprite(sp);
		tw.SwapBackBuffer();
		float check = Timer::GetDeltaTime();
	}



	return 0;
}