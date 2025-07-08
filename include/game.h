#pragma once

#include "UIElements.h"
#include "events.h"
#include <SDL_render.h>
#include <SDL_video.h>
#include <memory>
#include <vector>
#include "entity.h"
class Game{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool gamerun = true;
    InputManager input;
    std::vector<std::unique_ptr<UIElements>> elements;
    std::vector<entity*> objects;
public:
    void GameInit();
    void RunGame();
    void Update();
    void Render();
};

