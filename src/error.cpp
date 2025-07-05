#include "error.h"
#include "colors.h"
#include "entity.h"
#include "events.h"
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
#include <string>

void Errormessage(std::string message){

    SDL_Window* errorwindow = SDL_CreateWindow("Eror", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 100, SDL_WINDOW_SHOWN);
    SDL_Renderer* errorrenderer = SDL_CreateRenderer(errorwindow, -1, SDL_RENDERER_ACCELERATED);
    InputManager input;

    textbox messagebox(message, 0, 0, 300, 60, Colors::Gray, Colors::Black, 24);
    textbox Okbox("Ok!", 0, 0, 300, 60, Colors::Gray, Colors::Black, 24);
    bool pressOKpls = true;
    while (pressOKpls) {
    if (input.Keypressed(SDL_SCANCODE_ESCAPE)) {
        pressOKpls = false;
    }
    if (input.wannaQuit()) {
    pressOKpls = false;
    }

    messagebox.DrawnEntity(errorrenderer);
    Okbox.DrawnEntity(errorrenderer);
    SDL_RenderPresent(errorrenderer);
    }
    
    SDL_DestroyRenderer(errorrenderer);
    SDL_DestroyWindow(errorwindow);
    SDL_Quit();
    TTF_Quit();
}
