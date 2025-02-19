#include "InputManager.h"
#include "Log.h"

InputManager::~InputManager()
{
    std::map<SDL_Keycode, InputEvent*>::iterator inputEventsIterator;
    for (inputEventsIterator = mInputEvents.begin(); inputEventsIterator != mInputEvents.end(); inputEventsIterator++)
    {
        delete (inputEventsIterator->second);
    }

    mInputEvents.clear();
}

InputManager& InputManager::Instance()
{
    static InputManager instance;
    return instance;
}

void InputManager::HandleInputs(SDL_Event& pEvent)
{
    std::map<SDL_Keycode, InputEvent*>::iterator inputEventsIterator = mInputEvents.find(pEvent.key.keysym.sym);
    if (inputEventsIterator != mInputEvents.end())
    {
        (*inputEventsIterator).second->NotifyListeners(pEvent);
    }
}

void InputManager::SubscribeTo(SDL_Keycode pKeyCode, IInputListener* pListener)
{
    size_t hasKey = mInputEvents.count(pKeyCode);
    if (hasKey == 0)
    {
        mInputEvents[pKeyCode] = new InputEvent();
    }

    mInputEvents[pKeyCode]->Subscribe(pListener);
}
