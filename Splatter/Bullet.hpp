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
#include "LTexture.h"

class Bullet : public Entity {
    
    int x, y, vx, vy, rot, vi;
    int height, width;
    
    LTexture sprite = LTexture();
    
    SDL_Rect map;
    
    void Init(Engine* game, float X, float Y, float Rot, SDL_Rect Map);
    void Update(Engine* game);
    void Draw(Engine* game);
    void HandleEvents(Engine* game, SDL_Event event);
    
};

#endif /* Bullet_hpp */
