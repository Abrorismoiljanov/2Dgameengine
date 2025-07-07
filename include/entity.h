#pragma once

#include <SDL2/SDL_render.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include "Components.h"
#include "colors.h"
class entity{
private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> Components;
public:
    entity() = default;

    template<typename T, typename... Args>
    T* addComponent(Args&&... args){
    static_assert(std::is_base_of<Component, T>::value, "T must derive form component");
    auto comp = std::make_unique<T>(std::forward<Args>(args)...);
    T* ptr = comp.get();
    Components[typeid(T)] = std::move(comp);
    return ptr;
    }

    template<typename T>
    T* getComponent(){
        auto it = Components.find(typeid(T));
        if (it != Components.end()) {
            return dynamic_cast<T*>(it -> second.get());
        }
        return nullptr;
    }


    void update(float deltatime);
    void DrawnEntity(SDL_Renderer* renderer);
    virtual ~entity() = default;
};

class textbox{
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
    void DrawnEntity(SDL_Renderer* renderer);
    ~textbox();
};

