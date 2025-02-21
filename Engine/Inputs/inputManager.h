#pragma once
#include <map>
#include "InputEvent.h"

struct KeyEvent;

class InputManager
{
public:
	InputManager() = default;
	~InputManager();
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	void HandleInputs(SDL_Event& pEvent);
	void SubscribeTo(SDL_Keycode pKeyCode, IInputListener* pListener);

	static InputManager& Instance();

private:
	std::map<SDL_Keycode, InputEvent*> mInputEvents;
};