#pragma once

#include "events.h"
#include <SDL_render.h>
#include <SDL_video.h>
#include <vector>
#include "entity.h"
class Game{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool gamerun = true;
    InputManager input;
    std::vector<entity*> objects;
public:
    void GameInit();
    void RunGame();
    void Update();
    void Render();
};

