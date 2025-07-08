#include "error.h"
#include "UIElements.h"
#include "colors.h"
#include "events.h"
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
#include <string>

void Errormessage(std::string message, SDL_Window* window, SDL_Renderer* renderer){

    SDL_Window* errorwindow = SDL_CreateWindow("Eror", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 300, SDL_WINDOW_SHOWN);
    SDL_Renderer* errorrenderer = SDL_CreateRenderer(errorwindow, -1, SDL_RENDERER_ACCELERATED);
    InputManager input;

    textbox messagebox(message, 0, 0, 600, 250, Colors::Gray, Colors::Black, 24);
    textbox Okbox("Ok!", 290, 240, 300, 50, Colors::Black, Colors::White, 24);
    bool pressOKpls = true;
    while (pressOKpls) {
    
    SDL_SetRenderDrawColor(errorrenderer, Colors::Gray.r, Colors::Gray.g, Colors::Gray.b, Colors::Gray.a);
    SDL_RenderClear(errorrenderer);


    input.update();
    if (input.Keypressed(SDL_SCANCODE_ESCAPE)) {
        pressOKpls = false;
    }
    if (input.wannaQuit()) {
    pressOKpls = false;
    }

    messagebox.Render(errorrenderer);
    Okbox.Render(errorrenderer);
    SDL_RenderPresent(errorrenderer);
    SDL_Delay(16);
    }
     
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(errorrenderer);
    SDL_DestroyWindow(errorwindow);
    SDL_Quit();
    TTF_Quit();
}
