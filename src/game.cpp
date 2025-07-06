#include "game.h"
#include "colors.h"
#include "events.h"
#include <SDL_render.h>
#include <SDL_scancode.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
#include <asm-generic/errno.h>
#include <string>
#include "entity.h"
#include "error.h"
#include <vector>
using namespace Colors;

void Game::GameInit(){
    TTF_Init();    

    window = SDL_CreateWindow("Hello", 100, 100, 1280, 1080, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    objects.emplace_back(new textbox("Hello", 50, 50, 100, 50, Gray, Black, 24));
    
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
    Errormessage("Gachi muchi!", window, renderer);
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

    SDL_RenderPresent(renderer);
}

