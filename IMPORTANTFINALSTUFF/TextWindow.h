#pragma once
#include "Sprite.h"
class TextWindow : public PixelSprite{
public:
	TextWindow();
	TextWindow(unsigned int a_width, unsigned int a_height);
	void Reize(unsigned int a_width, unsigned int a_height);
	void SwapBackBuffer();
	void RenderSprite(Sprite &a_Sprite);
	void RenderSprite(PixelSprite &a_Sprite);
	void RenderSprite(PixelSprite &a_Sprite,Vec2 pos);

	COORD getConsoleSizeInPixels();
	
	Vec2 makeVec2(int x, int y) {
		static Vec2 v = Vec2(x, y);
		return v;
	}

private:
	void ClearBackBuffer();
	HANDLE m_Buffers[2];//handle to the two buffers we're going to use to render
	bool m_CurrentBuffer = false;
	COORD m_Size;
};