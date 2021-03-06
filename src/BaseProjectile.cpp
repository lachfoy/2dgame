#include "BaseProjectile.h"

#include "BaseDamageable.h"

BaseProjectile::BaseProjectile(float x, float y, float velX, float velY, SDL_Texture* texture, ParticleManager* particleManager)
    : BaseObject(x, y)
{
    this->velX = velX;
    this->velY = velY;
    this->texture = texture;
    this->particleManager = particleManager;
    
    collider = AABB(posX, posY, colliderW, colliderH);
}

void BaseProjectile::updateLifetime(float dt)
{
    if (lifeTime <= 0.0f)
        removable = true;
    else
        lifeTime -= dt;
}

void BaseProjectile::updatePosition(float dt)
{
    // update the internal position
    posX += velX * moveSpeed * dt;
    posY += velY * moveSpeed * dt;

    // move the collider as well
    collider.upperBoundX = posX - (colliderW / 2);
    collider.upperBoundY = posY - (colliderH / 2);
    collider.lowerBoundX = posX + (colliderW / 2);
    collider.lowerBoundY = posY + (colliderH / 2);
}

void BaseProjectile::renderCollider(SDL_Renderer* renderer)
{
    // draw collider
    collider.debugRender(renderer);
}
