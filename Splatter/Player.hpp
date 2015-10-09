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
#include <math.h>
#include "Engine.h"
#include "Entity.hpp"
#include "LTexture.h"

class Player : public Entity {
public:
    float rot, mousex, mousey;
    int maxvel, height, width;
    
    LTexture sprite = LTexture();
    
    SDL_Rect map;
    void Init(Engine* engine);
    void Update(Engine* engine);
    void Draw(Engine* engine);
    void HandleEvents(Engine* game, SDL_Event event);
    Player(){};
    

};

#endif