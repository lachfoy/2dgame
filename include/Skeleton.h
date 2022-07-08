#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

#include "BaseEnemy.h"

class Skeleton : public BaseEnemy
{
public:
    Skeleton(float x, float y, UiManager* uiManager, ProjectileManager* projectileManager, EnemyManager* enemyManager, Player* player);
    ~Skeleton() {}

    void updateAI(float dt) override {};

    void render(SDL_Renderer* renderer) override;

private:
    //Player* player;
    bool thinking;
    float thinkingTime;
    float thinkingTimer;
};

#endif