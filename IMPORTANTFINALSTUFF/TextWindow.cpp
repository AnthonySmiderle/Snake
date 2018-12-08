#include "TextWindow.h"
//struct Vec2 : public _COORD {
//	Vec2(unsigned int a_X, unsigned int a_Y){ X = a_X; Y = a_Y; }
//	Vec2() {}
//};

TextWindow::TextWindow() {
	m_Buffers[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	m_Buffers[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
}

TextWindow::TextWindow(unsigned int a_width, unsigned int a_height) : TextWindow()
{
	Reize(a_width,a_height);
}

void TextWindow::Reize(unsigned int a_width, unsigned int a_height)
{
	m_Size = Vec2(a_width, a_height);
	SetConsoleScreenBufferSize(m_Buffers[0], Vec2(a_width, a_height));
	SetConsoleScreenBufferSize(m_Buffers[1], Vec2(a_width, a_height));
}

void TextWindow::SwapBackBuffer()
{
	//swap front buffer to back buffer
	m_CurrentBuffer = !m_CurrentBuffer;

	SetConsoleActiveScreenBuffer(m_Buffers[(int)m_CurrentBuffer]);
	ClearBackBuffer();
}

void TextWindow::RenderSprite(Sprite & a_Sprite)
{
	SMALL_RECT temp;
	temp.Bottom = a_Sprite.GetPosition().Y + a_Sprite.GetSize().Y;
	temp.Left = a_Sprite.GetPosition().X;
	temp.Right = a_Sprite.GetPosition().X + a_Sprite.GetSize().X;
	temp.Top = a_Sprite.GetPosition().Y;

	WriteConsoleOutputA(m_Buffers[(int)!m_CurrentBuffer], a_Sprite.GetBuffer(), a_Sprite.GetSize(), Vec2(0, 0), &temp);
}
void TextWindow::RenderSprite(PixelSprite & a_Sprite)
{
	SMALL_RECT temp;
	temp.Bottom = a_Sprite.GetPosition().Y + a_Sprite.GetSize().Y;
	temp.Left = a_Sprite.GetPosition().X;
	temp.Right = a_Sprite.GetPosition().X + a_Sprite.GetSize().X;
	temp.Top = a_Sprite.GetPosition().Y;

	WriteConsoleOutputA(m_Buffers[(int)!m_CurrentBuffer], a_Sprite.GetBuffer(), a_Sprite.GetSize(), Vec2(0,0), &temp);
}
//void TextWindow::RenderSprite(PixelSprite & a_Sprite, Vec2 pos)
//{
//	SMALL_RECT temp;
//	temp.Bottom = a_Sprite.GetPosition().Y+ a_Sprite.GetSize().Y;
//	temp.Left = a_Sprite.GetPosition().X;
//	temp.Right = a_Sprite.GetPosition().X + a_Sprite.GetSize().X;
//	temp.Top = a_Sprite.GetPosition().Y;
//	COORD a;
//	a.X = 10;
//	a.Y = 10;
//
//	WriteConsoleOutputA(m_Buffers[(int)!m_CurrentBuffer], a_Sprite.GetBuffer(), a_Sprite.GetSize(), Vec2(0, 0), &temp);
//}
COORD TextWindow::getConsoleSizeInPixels()
{
	CONSOLE_SCREEN_BUFFER_INFO I;
	GetConsoleScreenBufferInfo(m_Buffers[(int)!m_CurrentBuffer], &I);
	
	//subtracting left from right to get the width of the window, subtracting bottom from top to get the height
	return COORD{ I.srWindow.Right - I.srWindow.Left, I.srWindow.Bottom - I.srWindow.Top };
}

void TextWindow::ClearBackBuffer()
{
	DWORD USELESS;
	FillConsoleOutputCharacter(m_Buffers[!m_CurrentBuffer], ' ', m_Size.X * m_Size.Y, Vec2(0, 0), &USELESS);
	FillConsoleOutputAttribute(m_Buffers[!m_CurrentBuffer],0x0000, m_Size.X * m_Size.Y, Vec2(0, 0), &USELESS);
}

/*
TO DO LIST:


*/