#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SDL2/SDL.h>

#include "Point2f.h"
#include "Player.h"

// should probably inherit from a "BaseUIObject" or something like that.
class HealthBar
{
public:
    inline HealthBar(int x, int y);

    Point2f pos;

    inline void updateHealth(Player* player);
    inline void render(SDL_Renderer* renderer);

private:
    int length;
    int height;
    SDL_Rect bg_rect;
    SDL_Rect health_rect;

    enum
    {
        DEFAULT_LENGTH = 400,
        DEFAULT_HEIGHT = 16
    };

};

HealthBar::HealthBar(int x, int y)
{
    pos.x = x;
    pos.y = y;
    length = DEFAULT_LENGTH;
    height = DEFAULT_HEIGHT;

    bg_rect.x = pos.x;
    bg_rect.y = pos.y;
    bg_rect.w = length;
    bg_rect.h = DEFAULT_HEIGHT;

    health_rect.x = pos.x;
    health_rect.y = pos.y;
    health_rect.w = length;
    health_rect.h = DEFAULT_HEIGHT;
}

// it would be cool to have animated healthbars but I dont think I can be bothered yet
void HealthBar::updateHealth(Player* player)
{
    // prevent health rect from renderering a negative width
    if (player->health <= 0)
        health_rect.w = 0;
    else
        // update the healthbar width using the players health %
        health_rect.w = (int)(((float)player->health / player->maxHealth) * length);
}

void HealthBar::render(SDL_Renderer* renderer)
{
    // draw the bg
    SDL_SetRenderDrawColor(renderer, 0xaa, 0xaa, 0xaa, 0xff); // dark grey
    SDL_RenderFillRect(renderer, &bg_rect);

    // draw the actual health bar over the bg
    SDL_SetRenderDrawColor(renderer, 0xd1, 0x15, 0x15, 0xff); // #d11515 darkish red
    SDL_RenderFillRect(renderer, &health_rect);
}

#endif