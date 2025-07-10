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
#include <string>
#include <vector>
using namespace Colors;

void Game::GameInit(){
    TTF_Init();    
    IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG);

    window = SDL_CreateWindow("Hello", 100, 100, 1920, 1080, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   
///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    objects.push_back(std::make_unique<entity>());
    entity* dude = objects.back().get();
    objects.push_back(std::make_unique<entity>());
    entity* ns = objects.back().get();

    TransformComponent* dudetransform = dude->addComponent<TransformComponent>(100, 150, 45, 1, 1);
    TextureComponent* dudetexture = dude->addComponent<TextureComponent>("./girlslasttour.jpg", renderer);
    dudetexture->setTransform(dudetransform);

    TransformComponent* nstransform = ns->addComponent<TransformComponent>(600, 150, 360,0.1,0.1);
    TextureComponent* nstexture = ns->addComponent<TextureComponent>("../../../Pictures/Msdos-1730606937.png", renderer);
    nstexture->setTransform(nstransform);

///////////////////////////////////////////////
    elements.push_back(std::make_unique<container>(900, 200, 500, 500, Blue, Red));
    container* ObjectList = static_cast<container*>(elements.back().get());
    
    for ( int i = 0; i < 5; i++) {
    ObjectList->addChildren<textbox>("box1", 0,i * 100, 200, 100, Gray, Red, 24);
    }
/////////////////////////////////////////////////
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
    for (auto& obj: objects) {
        obj->update(16);
    }
    for (auto& elm: elements){
        elm->update(16);
    }
}

void Game::Render(){
    
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
  
    for (auto& obj : objects) {
        obj ->DrawnEntity(renderer);
    }

    for (auto& elm : elements) {
        elm->render(renderer);
    }       

    SDL_RenderPresent(renderer);
}

