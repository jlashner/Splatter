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

enum AI_STATE {
    Chase
};

class Enemy : public Entity {
public:
    double x, y, vx, vy;
    double maxvel = 80;
    AI_STATE ai;
    
    Entity* target;
    
    void Init(Engine* game);
    
    void Update(Engine* game);
    
    void Draw(Engine* game);
    
    void HandleEvents(Engine* game, SDL_Event event);
    
    void SetTarget(Entity *t){target = t;}
    
    
    
    Enemy(){};
};



#endif /* Enemy_hpp */
