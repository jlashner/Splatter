//
//  Player.cpp
//  Splatter
//
//  Created by Grant Addis on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "Player.hpp"
#include <SDL2/SDL.h>

void Player::Init(Engine* game) {
  x = 0;
  y = 0;
  vx = 0;
  vy = 0;
    mousex = 0;
    mousey = 0;
    height = 30;
    width = 30;
    rot = 0;
    maxvel = 200;
    acceleration = 1.2;
    
    SDL_Rect rect = {(int)x, (int)y, width, height};
    SDL_Color color = {255,255,255,255};
    
    sprite.loadRectangle(rect, game->renderer, color);
    
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
    
    float adj = mousex - x;
    float opp = mousey - y;
    
    rot = atan2f(opp, adj);
    
}

void Player::Draw(Engine *game) {
  SDL_SetRenderDrawColor( game->renderer, 0, 0, 255, 0xFF );
    
    sprite.render((int)x,(int)y, game->renderer, NULL, NULL, rot * (180.0 / M_PI));
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
                    if (vy < 0) vy = 0;
                    break;
                case SDLK_d:
                    if (vx > 0) vx = 0;
                    break;
                case SDLK_a:
                    if (vx < 0) vx = 0;
                    break;
                case SDLK_s:
                    if (vy > 0) vy = 0;
                    break;
            }
            break;
        case SDL_MOUSEMOTION:
            mousex = event.motion.x;
            mousey = event.motion.y;
            break;
    }
}
