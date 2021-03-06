#ifndef SWORDSLASH_H
#define SWORDSLASH_H

#include "BaseMeleeWeapon.h"

class BaseDamageable;

class SwordSlash : public BaseMeleeWeapon
{
public:
    SwordSlash(float x, float y, float offsetX, float offsetY, SDL_Texture* texture, BaseDamageable* wielder);

    void destroy(ProjectileManager& projectileManager) override {}
    void render(SDL_Renderer* renderer) override;
    
};

#endif