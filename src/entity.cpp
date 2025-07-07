#include "entity.h"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_ttf.h>
#include <endian.h>
#include <iostream>
#include <string>
#include "Components.h"
#include "colors.h"
#include "error.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace Colors;

void entity::update(float deltatime){
    for (auto& [type, comp] : Components) {
        comp->update(deltatime);
    }
}
void entity::DrawnEntity(SDL_Renderer* renderer){
    for (auto& [type, comp] : Components) {
    comp->render(renderer);
    }
}

textbox::textbox(std::string text, float x, float y, float width, float height, Color background, Color textcolor, float fontsize)
    : text(text),x(x), y(y), width(width), height(height), background(background), textcolor(textcolor), fontsize(fontsize){};
 
void textbox::TextInit(SDL_Renderer* renderer){


    font = TTF_OpenFont("../assets/Departure_mono_font/DepartureMonoNerdFont-Regular.otf", fontsize);
    if (!font) {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return;
    }

     surface = TTF_RenderText_Blended(font, text.c_str(), textcolor);
    if (!surface) {
        SDL_Log("Failed to create surface: %s", TTF_GetError());
        return;
    }

     texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
        return;
    }
}
void textbox::DrawnEntity(SDL_Renderer* renderer){
    if (!textready){
    TextInit(renderer);
    textready = true;
    }

    SDL_Rect rect = {
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height)
                    };


    SDL_SetRenderDrawColor(renderer,background.r, background.g, background.b, background.a);
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_Rect textrect;
    textrect.w = surface ->w;
    textrect.h = surface ->h;
    textrect.x = rect.x + (rect.w - textrect.w) / 2;
    textrect.y = rect.y + (rect.h - textrect.h) / 2;

    SDL_RenderCopy(renderer, texture, nullptr, &textrect);
}
textbox::~textbox(){
    if (texture) SDL_DestroyTexture(texture);
    if (surface) SDL_FreeSurface(surface);
    if (font) TTF_CloseFont(font);   
}

