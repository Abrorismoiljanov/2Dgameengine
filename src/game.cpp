#include "game.h"
#include "Components.h"
#include "UIElements.h"
#include "colors.h"
#include "events.h"
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_scancode.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
#include <asm-generic/errno.h>
#include "entity.h"
#include "error.h"
#include "Components.h"
#include <memory>
#include <vector>
using namespace Colors;

void Game::GameInit(){
    TTF_Init();    
    IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG);

    window = SDL_CreateWindow("Hello", 100, 100, 1920, 1080, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//////////////////////////////////////////////////////////////////////////////////////
    elements.push_back(
    std::make_unique<textbox>("Text", 100, 100, 200, 70, Gray, Black,24)
            );
///////////////////////////////////////////////////////////////////////////////////////////////////////

    entity* dude = new entity();
    entity* ns = new entity();
    TransformComponent* dudetransform = dude->addComponent<TransformComponent>(100, 150, 45, 1, 1);
    TextureComponent* dudetexture = dude->addComponent<TextureComponent>("./girlslasttour.jpg", renderer);
    dudetexture->setTransform(dudetransform);
    objects.push_back(dude);

    TransformComponent* nstransform = ns->addComponent<TransformComponent>(600, 150, 360,0.1,0.1);
    TextureComponent* nstexture = ns->addComponent<TextureComponent>("../../../Pictures/Msdos-1730606937.png", renderer);
    nstexture->setTransform(nstransform);
    objects.push_back(ns);

}
void Game::RunGame(){
    while (gamerun) {
    Update();
    Render();
    }
}

void Game::Update(){
    input.update();
    if (input.wannaQuit()) {
    gamerun = false;
    }
    if (input.Keypressed(SDL_SCANCODE_ESCAPE)) {
        gamerun = false;
    }
}

void Game::Render(){
    
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
  
    for (entity* obj : objects) {
        obj ->DrawnEntity(renderer);
    }

    for (auto& elm: elements) {
        elm->Render(renderer);
    }       

    SDL_RenderPresent(renderer);
}

