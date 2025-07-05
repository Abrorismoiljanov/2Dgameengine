#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_pixels.h>
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
#include <SDL2/SDL.h>
#include <SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

int main (int argc, char *argv[]) {

    Game game;
    game.GameInit();
    game.RunGame();

    
    return 0;
}
