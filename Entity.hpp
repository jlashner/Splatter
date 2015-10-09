//
//  Entity.hpp
//  Splatter
//
//  Created by Jacob Lashner on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "Engine.h"

class Entity {
public:
    int x, y, vx, vy;
    
    virtual void Init(Engine* game) = 0;
    
    virtual void Update(Engine* game) = 0;
    
    virtual void Draw(Engine* game) = 0 ;
    
    void HandleEvents(Engine* game, SDL_Event event);

protected:
    Entity(){};
};

#endif /* Entity_hpp */
