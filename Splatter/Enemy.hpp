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

class Enemy : public Entity {
public:
    int x, y, vx, vy;

    void Init(Engine* game);
    
    void Update(Engine* game);
    
    void Draw(Engine* game);
    
    void HandleEvents(Engine* game, SDL_Event event);
    
    
    Enemy(){};
};



#endif /* Enemy_hpp */
