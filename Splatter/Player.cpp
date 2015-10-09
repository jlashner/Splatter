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
    height = 30;
    width = 30;
    rot = 0;
    maxvel = 200;
}

void Player::Update(Engine* game) {
    float newx = x + (vx * game->getDelta());
    float newy = y + (vy * game->getDelta());
    
    if (newx < map.x) {
        x = map.x;
    } else if (newx > (map.x + map.w - width)) {
        x = map.x + map.w - width;
    } else {
        x = newx;
    }
    
    if (newy < map.y) {
        y = map.y;
    } else if (newy > (map.y + map.h - height)) {
        y = map.y + map.h - height;
    } else {
        y = newy;
    }
}

void Player::Draw(Engine *game) {
  SDL_Rect rect = {(int) x, (int) y , 30, 30};
    
  SDL_SetRenderDrawColor( game->renderer, 0, 0, 255, 0xFF );
    
  SDL_RenderDrawRect(game->renderer, &rect);
}

void Player::HandleEvents(Engine *game, SDL_Event event){
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    vy = -maxvel;
                    break;
                case SDLK_s:
                    vy = maxvel;
                    break;
                case SDLK_a:
                    vx = -maxvel;
                    break;
                case SDLK_d:
                    vx = maxvel;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    vy = 0;
                    break;
                case SDLK_d:
                    vx = 0;
                    break;
                case SDLK_a:
                    vx = 0;
                    break;
                case SDLK_s:
                    vy = 0;
                    break;
            }
            break;
    }
}
