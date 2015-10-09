//
//  Bullet.hpp
//  Splatter
//
//  Created by Liza Woythaler on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "Engine.h"
#include "Entity.hpp"

class Bullet : public Entity {
    
    int x, y, vx, vy, rot;
    int height, width;
    
    void Init(Engine* game, float X, float Y, float Rot);
    
    void Update(Engine* game);
    
    void Draw(Engine* game);
    
    void HandleEvents(Engine* game, SDL_Event event);
    
};

#endif /* Bullet_hpp */
