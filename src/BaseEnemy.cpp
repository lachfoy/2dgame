#include "BaseEnemy.h"

#include "UiManager.h"
#include "ProjectileManager.h"
#include "Player.h"
#include "DynamicHealthbar.h"

BaseEnemy::BaseEnemy(float x, float y, ResourceManager* resourceManager, UiManager* uiManager, ProjectileManager* projectileManager, Player* player)
     : BaseDamageable(x, y, resourceManager, nullptr)
{
    this->uiManager = uiManager;
    this->projectileManager = projectileManager;
    this->player = player;

    uiManager->addDynamicHealthbar(44, 4, this);
}