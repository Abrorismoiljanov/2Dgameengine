#pragma once

#include <SDL_events.h>
#include <SDL_stdinc.h>
class InputManager{
private:
    const Uint8* keystate;
    SDL_Event event;
public:
    InputManager();

    void update();
    bool Keypressed(SDL_Scancode key);
    bool wannaQuit() const;

private:
    bool gottaquit;
};

