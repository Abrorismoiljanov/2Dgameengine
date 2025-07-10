#pragma once

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <memory>
#include <utility>
#include <vector>
#include "colors.h"

using namespace  Colors;

class UIElements{
public:
    UIElements() = default;

    virtual void render(SDL_Renderer* renderer, float px = 0, float py = 0) = 0;
    virtual void update(float deltatime) = 0;
    void ONClick();
    void Hover();

    virtual ~UIElements();
};

class container: public UIElements{
private:
    float x,y;
    float width, height;
    Color background;
    Color border;
    std::vector<std::unique_ptr<UIElements>> children;
public:
    container(float x, float y, float width, float height, Color background, Color border);

    template<typename T, typename... Args>
    T* addChildren(Args&&... args){
    static_assert(std::is_base_of<UIElements, T>::value, "T must derive form component");
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    T* ptr = child.get();
    children.push_back(std::move(child));
    return ptr;
    }

    void update(float deltatime) override;
    void render(SDL_Renderer* renderer, float px,float py) override;
    virtual ~container() = default;
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
    void update(float deltatime) override;
    void render(SDL_Renderer* renderer, float px, float py) override;
    ~textbox();
};

