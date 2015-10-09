//
//  Player.hpp
//  Splatter
//
//  Created by Grant Addis on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Engine.h"

class Player {
public:
    float x, y, vx, vy, rot;
    int maxvel, height, width;
    SDL_Rect map;
    void Init(Engine* engine);
    void Update(Engine* engine);
    void Draw(Engine* engine);
    void HandleEvents(Engine* game, SDL_Event event);
    Player(){};
};

#endif