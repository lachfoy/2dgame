#ifndef FIREBALLEXPLOSION_H
#define FIREBALLEXPLOSION_H

#include "BaseProjectile.h"

class FireballExplosion : public BaseProjectile
{
public:
    FireballExplosion(float x, float y, SDL_Texture* texture);

    void destroy(ProjectileManager& projectileManager) override {}
    void render(SDL_Renderer* renderer) override;
    
};

#endif