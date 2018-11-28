#pragma once
#include <ctime>

#define Static_Timer Timer::

class Timer
{
public:
	static void InitializeDeltaTime()
	{
		Last = (float)(std::clock() / 1000);
	}

	static void CalculateDeltaTime()
	{
		float timeCycle = (float)std::clock() / 1000.0f;
		m_DeltaTime = timeCycle - Last;
		Last = timeCycle;
	};

	static float GetDeltaTime()
	{
		return m_DeltaTime;
	}

private:
	static float Last;
	static float m_DeltaTime;
};

// initialize the static variables