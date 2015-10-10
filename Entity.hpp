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
    float  x, y;
    float vx, vy;
    
    float hit_rad;
    
    bool show_hitbox = false;
    
    virtual void Init(Engine* game) = 0;
    
    virtual void Update(Engine* game) = 0;
    
    virtual void Draw(Engine* game) = 0 ;
    
    void HandleEvents(Engine* game, SDL_Event event);
    
    bool HasCollided(Entity* e){

        float dist = pow((this->x - e->x), 2) + pow((this->y - e->y), 2);
        
        return dist < pow(hit_rad + e->hit_rad, 2 );
        
    }

protected:
    Entity(){};
    
private:
    
};

#endif /* Entity_hpp */
