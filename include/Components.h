#pragma once

#include <SDL2/SDL.h>
#include <SDL_render.h>
#include <string>

class Component{

public:
    virtual ~Component() = default;
    virtual void update(float deltatime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};


class TransformComponent : public Component{
private:
    float x,y;
    float rotation;
    float scaleX, scaleY;

public:
    TransformComponent(float x = 0, float y = 0,float rotation = 0, float scaleX = 1,float scaleY = 1);

    float getX() const { return x;};
    float getY() const { return y;};
    void setX(float nx){x = nx;};
    void setY( float ny){y = ny;};

    float getRotation() const { return rotation;};
    void setRotation(float nr){rotation = nr;};

    float getScaleX() const {return scaleX;};
    void setScaleX( float nsx){scaleX = nsx;};
    float getScaleY() const { return scaleY; };
    void setScaleY( float nsy) {scaleY = nsy;};

    void update(float deltatime) override;
    void render(SDL_Renderer* renderer) override;
};

class TextureComponent : public Component{
private:
    SDL_Texture* texture = nullptr;
    int width, height;
    std::string path;
    TransformComponent* transform = nullptr;
public:
    TextureComponent(const std::string& imagepath, SDL_Renderer* renderer);
    ~TextureComponent();

    void update(float deltatime) override;
    void render(SDL_Renderer* renderer) override;
    void render(SDL_Renderer* renderer, TransformComponent* transform);
    void setTransform(TransformComponent* t);
};














