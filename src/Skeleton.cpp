#include "Skeleton.h"

#include "AABB.h"
#include "Player.h"
#include "UiManager.h"
#include "EnemyManager.h"

Skeleton::Skeleton(float x, float y, UiManager* uiManager, ProjectileManager* projectileManager, EnemyManager* enemyManager, Player* player)
    : BaseEnemy(x, y, uiManager, projectileManager, enemyManager, player)
{
    // initialize everything
    name = "Skeleton";
    
    width = 30;
    height = 60;

    colliderW = 50;
    colliderH = 50;

    maxHealth = 80;
    health = maxHealth;

    immuneTime = 0.1f; // how many seconds of iframes
    immuneTimer = immuneTime;

    moveSpeed = 10.0f; // slowww

    damage = 6;

    thinkingTime = 2.0f;
    thinkingTimer = thinkingTime;
}

void Skeleton::updateAI(float dt)
{
    // do thinking. this is really messy :/
    thinkingTimer -= dt;
    if (thinkingTimer <= 0.0f)
    {
        printf("Skeleton had a thought...\n");
        targetX = player->posX;
        targetY = player->posY;
        
        thinkingTimer = thinkingTime;  // reset to the starting value
    }

    velX = ((targetX - posX) > 0.0f) ? 1 : -1;
    velY = ((targetY - posY) > 0.0f) ? 1 : -1;
}

void Skeleton::render(SDL_Renderer* renderer)
{
    // create rect representing the enemy
    SDL_Rect enemy_rect;
    enemy_rect.x = (int)posX - (width / 2);
    enemy_rect.y = (int)posY - height;
    enemy_rect.w = width;
    enemy_rect.h = height;
    
    // set draw color
    SDL_Color enemy_color = { 0xb1, 0xb1, 0xb1, 0xff }; // grey

    // set alpha depending on damageable status
    if (!damageable)
    {
        enemy_color.a = 0x65;
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    }
    else SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    
    // draw enemy
    SDL_SetRenderDrawColor(renderer, enemy_color.r, enemy_color.g, enemy_color.b, enemy_color.a);
    SDL_RenderFillRect(renderer, &enemy_rect);

    // draw the origin position representing the actual x and y positions
    SDL_Rect debug_point_pos;
    debug_point_pos.w = 4;
    debug_point_pos.h = 4;
    debug_point_pos.x = (int)posX - (debug_point_pos.w / 2);
    debug_point_pos.y = (int)posY - (debug_point_pos.h / 2);
    SDL_SetRenderDrawColor(renderer, 0xeb, 0xd5, 0x17, 0xff); // #ebd517 yellow
    SDL_RenderFillRect(renderer, &debug_point_pos);

    // draw collider
    collider->debugRender(renderer);
}
