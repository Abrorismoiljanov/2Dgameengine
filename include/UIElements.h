#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "colors.h"

using namespace  Colors;

class UIElements{
public:
    UIElements() = default;

    virtual void Render(SDL_Renderer* renderer) = 0;
    void update();
    void ONClick();
    void Hover();

    virtual ~UIElements();
};


class textbox: public UIElements{
private:
    bool textready = false;
    std::string text;
    float x,y;
    float width, height;
    float fontsize;
    Color textcolor;
    Color background;
    TTF_Font* font = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = nullptr;
public:
    textbox(std::string text = "",float x = 0, float y = 0, float width = 50, float height = 50, Color background = Colors::Gray, Color textcolor = Colors::White, float fontsize = 12);
    void TextInit(SDL_Renderer* renderer);
    void Render(SDL_Renderer* renderer) override;
    ~textbox();
};

