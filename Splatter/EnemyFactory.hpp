//
//  EnemyFactory.hpp
//  Splatter
//
//  Created by Grant Addis on 10/10/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef EnemyFactory_hpp
#define EnemyFactory_hpp

#include <stdio.h>
#include "Engine.h"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

class EnemyFactory {
public:
    void addEnemy(Engine* game, double x, double y, Player* player, LTexture* tex);
    void updateEnemies(Engine* game, Player* p);
    void drawEnemies(Engine* game);
    bool bulletDidHidEnemy(Bullet* bullet);
    void despawnAll();
    int wave = 1;
    bool playerKilled = false;

private:
    vector<Enemy> enemies;
};

#endif /* EnemyFactory_hpp */
