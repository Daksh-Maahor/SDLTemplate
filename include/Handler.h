#ifndef HANDLER_H_
#define HANDLER_H_

#include "Window.h"
#include "State.h"
#include "InputManager.h"

class Handler
{
private:
    Window* window;
    State* currentState;
    InputManager* inputManager;
public:
    Handler(Window* win, InputManager* im) : window(win), inputManager(im) {};

    void SetCurrentState(State* state)
    {
        currentState = state;
    }

    InputManager* GetInputManager()
    {
        return inputManager;
    }

    State* GetCurrentState()
    {
        return currentState;
    }

    Window* GetWindow()
    {
        return window;
    }
};

#endif
