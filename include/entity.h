#pragma once

#include <SDL2/SDL_render.h>
#include <SDL_ttf.h>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include "Components.h"
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

