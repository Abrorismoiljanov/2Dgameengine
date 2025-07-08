#include "entity.h"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_ttf.h>
#include <endian.h>
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

