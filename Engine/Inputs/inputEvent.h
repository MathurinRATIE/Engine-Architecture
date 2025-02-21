#pragma once
#include <vector>
#include "IInputListener.h"

class InputEvent
{
public:
	~InputEvent();
	
	void Subscribe(IInputListener* pListener);
	void Unsubscribe(IInputListener* pListener);
	void NotifyListeners(SDL_Event& pEvent) const;

private:
	std::vector<IInputListener*> mListeners;
};
