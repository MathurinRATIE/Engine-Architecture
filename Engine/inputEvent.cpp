#include "inputEvent.h"

InputEvent::~InputEvent()
{
    mListeners.clear();
}

void InputEvent::Subscribe(IInputListener* pListener)
{
    mListeners.push_back(pListener);
}

void InputEvent::Unsubscribe(IInputListener* pListener)
{
    std::vector<IInputListener*>::iterator listenersIterator;
    if ((listenersIterator = std::find(mListeners.begin(), mListeners.end(), pListener)) != mListeners.end())
    {
        mListeners.erase(listenersIterator);
    }
}

void InputEvent::NotifyListeners(SDL_Event& pEvent) const
{
    for (IInputListener* listener : mListeners)
    {
        listener->OnNotify(pEvent);
    }
}
  