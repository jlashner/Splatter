//
//  Enemy.hpp
//  Splatter
//
//  Created by Jacob Lashner on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "Player.hpp"
#include "LTexture.h"

enum AI_STATE {
    Chase
};

class Enemy : public Entity {
public:
    double vx, vy;
    int width, height;
    double maxvel = 80;
    
    
    
    double rot;
    
    AI_STATE ai;
    
    bool is_dead = false;
    
    Entity* target;
    
    void Init(Engine* game){}
    void Init(Engine* game, double x, double y, Player* p);
    
    
    void Update(Engine* game);
    
    void Draw(Engine* game);
    
    void HandleEvents(Engine* game, SDL_Event event);
    
    void Destroy();
    
    Enemy(){};
    
private:
    LTexture sprite = LTexture();
};



#endif /* Enemy_hpp */
