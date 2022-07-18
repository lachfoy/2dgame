#include "Sword.h"

#include "BaseDamageable.h"
#include "ProjectileManager.h"

Sword::Sword(float x, float y, float offsetX, float offsetY, SDL_Texture* texture, BaseDamageable* wielder)
     : BaseMeleeWeapon(x, y, offsetX, offsetY, texture, wielder)
{
    name = "Sword";
    colliderW = 50;
    colliderH = 26;
    damage = {0};
    damage = { .standard = 11 };
    lifeTime = 0.1f;
}

void Sword::destroy(ProjectileManager& projectileManager)
{
    projectileManager.addSwordSlash(posX, posY, offsetX * 1.2f, offsetY, wielder);
}

void Sword::render(SDL_Renderer* renderer)
{
    // draw the origin position representing the actual x and y positions
    SDL_Rect sword_rect;
    sword_rect.w = 52;
    sword_rect.h = 28;
    sword_rect.x = (int)posX - (sword_rect.w / 2);
    sword_rect.y = (int)posY - (sword_rect.h / 2);

    // draw texture
    SDL_RenderCopy(renderer, texture, NULL, &sword_rect);


    // draw collider
    //collider.debugRender(renderer);
}