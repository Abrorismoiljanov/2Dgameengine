#include "UIElements.h"
#include "colors.h"
#include <string.h>
#include <SDL_render.h>
#include <SDL_surface.h>

UIElements::~UIElements(){

} 

container::container(float x, float y, float width, float height, Color background, Color border)
    :x(x), y(y), width(width), height(height), background(background), border(border){}

void container::update(float deltatime){
        for (auto& chld: children) {
            chld->update(deltatime);
        }
}
void container::render(SDL_Renderer* renderer, float px, float py){

    SDL_Rect rect = {
    static_cast<int>(x + px),
    static_cast<int>(y + py),
    static_cast<int>(width),
    static_cast<int>(height)
    };
    
    SDL_SetRenderDrawColor(renderer, border.r, border.g, border.b, border.a);
    SDL_RenderFillRect(renderer, &rect);
        for (auto& chld: children) {
            chld->render(renderer, x, y);
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
void textbox::render(SDL_Renderer* renderer, float px, float py){
    if (!textready){
    TextInit(renderer);
    textready = true;
    }

    SDL_Rect border = {
            static_cast<int>(x + px),
            static_cast<int>(y + py),
            static_cast<int>(width),
            static_cast<int>(height)
                    };

    int borderl = width / 100 * 2;

    SDL_Rect rect = {
            static_cast<int>(x + borderl + px),
            static_cast<int>(y + borderl + py),
            static_cast<int>(width - borderl * 2),
            static_cast<int>(height - borderl * 2)
                    };

    SDL_SetRenderDrawColor(renderer,background.r, background.g + 110, background.b, background.a);
    SDL_RenderFillRect(renderer, &border);

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
void textbox::update(float deltatime){

};
