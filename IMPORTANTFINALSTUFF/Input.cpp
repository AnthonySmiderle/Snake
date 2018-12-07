#include "Input.h"
#include <Windows.h>

bool isEvent(unsigned char event)
{
	return GetAsyncKeyState(event);//determines whether or not the key we provide is up or down, then returns false or true respectively
}
