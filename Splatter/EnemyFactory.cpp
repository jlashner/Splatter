//
//  EnemyFactory.cpp
//  Splatter
//
//  Created by Grant Addis on 10/10/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "EnemyFactory.hpp"

void EnemyFactory::addEnemy(Engine* game, double x, double y, Player *player, LTexture *tex) {
    playerKilled = false;
    Enemy newEnemy;
    newEnemy.Init(game, x, y, player, tex);
    enemies.push_back(newEnemy);
}

void EnemyFactory::updateEnemies(Engine *game, Player* p) {
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Update(game);
        if (p->HasCollided(&enemies[i])){
            p->Destroy();
            
            enemies.erase(enemies.begin() + i);
            i--;
            
            playerKilled = true;
        }
    }
}

void EnemyFactory::drawEnemies(Engine *game) {
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Draw(game);
    }
}

bool EnemyFactory::bulletDidHidEnemy(Bullet *bullet) {
    for (int i = 0; i < enemies.size(); i++) {
        if (bullet->HasCollided(&enemies[i])) {
            enemies[i].Destroy();
            enemies.erase(enemies.begin() + i);
            i--;
            if (enemies.size() == 0) {
                wave++;
            }
            return true;
        }
    }
    return false;
}

void EnemyFactory::despawnAll() {
    enemies.clear();
}