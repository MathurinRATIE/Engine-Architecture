#pragma once
#include "SDL_events.h"

class IInputListener
{
public:
	virtual ~IInputListener() = default;
	virtual void OnNotifyInput(SDL_Event& pEvent) = 0;
};
