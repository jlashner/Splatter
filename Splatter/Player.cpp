//
//  Player.cpp
//  Splatter
//
//  Created by Grant Addis on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "Player.hpp"
#include <SDL2/SDL.h>

void Player::Init(Engine* engine) {
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
}

void Player::Update(Engine* game) {
    x += vx;
    y += vy;
}

void Player::Draw(Engine *game) {
    SDL_Rect rect = {x, y , 30, 30};
    
    SDL_SetRenderDrawColor( game->renderer, 0, 0, 255, 0xFF );
    
    SDL_RenderDrawRect(game->renderer, &rect);
}