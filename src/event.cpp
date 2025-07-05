#include "event.h"
#include "events.h"
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_scancode.h>

InputManager::InputManager()
    : gottaquit(false) 
{  
    keystate = SDL_GetKeyboardState(NULL);
}

void InputManager::update(){
    gottaquit = false;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            gottaquit = true;
        }
    }
};

bool InputManager::Keypressed(SDL_Scancode key){
    return keystate[key];
};

bool InputManager::wannaQuit() const{
    return gottaquit;
};
