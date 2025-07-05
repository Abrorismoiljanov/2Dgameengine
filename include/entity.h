#pragma once

#include <SDL2/SDL_render.h>
#include <SDL_ttf.h>
#include <string>
#include "colors.h"
class entity{
protected:
    float x;
    float y;
    float velocityX, velocityY;
    Color color;
public:
    entity(float x = 0, float y = 0, Color color = {0,0,0,0});
    virtual void update(float deltatime);
    virtual void changeX(float value);
    virtual void changeY(float value);
    void setColor(Color newcolor);
    float getX();
    float getY();
    virtual void DrawnEntity(SDL_Renderer* renderer) = 0;
    virtual ~entity(){};
};

class textbox: public entity{
private:
    bool textready = false;
    std::string text;
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
    void DrawnEntity(SDL_Renderer* renderer) override;
    ~textbox();
};

