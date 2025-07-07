#include "Components.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

TextureComponent::TextureComponent(const std::string& imagepath, SDL_Renderer* renderer)
        : path(imagepath){
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
    std::cout<<"surface didnt loaded" << '\n';
    return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    if (!texture) {
        std::cout<<"texture didnt worked" <<'\n';
    return;
    }
    width = surface ->w;
    height = surface->h;
};
TextureComponent::~TextureComponent(){
    SDL_DestroyTexture(texture);
};
void TextureComponent::render(SDL_Renderer* renderer, TransformComponent* transform){
    if (!transform || !texture) {
    return;
    }
    SDL_Rect dstrect;
    dstrect.x = static_cast<int>(transform->getX());
    dstrect.y = static_cast<int>(transform->getY());
    dstrect.w = static_cast<int>(width * transform->getScaleX());
    dstrect.h = static_cast<int>(height * transform->getScaleY());

    SDL_RenderCopyEx(renderer, texture, nullptr, &dstrect, transform->getRotation(), nullptr, SDL_FLIP_NONE);
};

void TextureComponent::setTransform(TransformComponent* t){
    transform = t;
}

void TextureComponent::update(float deltatime) {
    
}

void TextureComponent::render(SDL_Renderer* renderer) {
    if (transform && texture) {
        render(renderer, transform);
    }
}

TransformComponent::TransformComponent(float x, float y,float rotation, float scaleX,float scaleY)
    : x(x),y(y), rotation(rotation), scaleX(scaleX), scaleY(scaleY) {

}
void TransformComponent::update(float deltatime) {
    // empty or future logic
}

void TransformComponent::render(SDL_Renderer* renderer) {
    // TransformComponent doesn't draw anything directly
}


