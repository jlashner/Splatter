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
    height = 40;
    width = 40;


    show_hitbox = true;
    
    hit_rad = 10;

    rot = 0;
    maxvel = 200;
    
//    SDL_Rect rect = {(int)x, (int)y, width, height};
//    SDL_Color color = {255,255,255,255};
    
    
    sprite.loadFromFile("assets/Player.png", game->renderer);
//    sprite.loadRectangle(rect, game->renderer, color);
    

}

void Player::Update(Engine* game) {
    float newx = x + (vx * game->getDelta());
    float newy = y + (vy * game->getDelta());
    
    if (newx < map.x) {
        x = map.x;
    } else if (newx > (map.x + map.w)) {
        x = map.x + map.w;
    } else {
        x = newx;
    }
    
    if (newy < map.y) {
        y = map.y;
    } else if (newy > (map.y + map.h)) {
        y = map.y + map.h;
    } else {
        y = newy;
    }
    
    float adj = mousex - x;
    float opp = mousey - y;
    
    rot = atan2f(opp, adj);
    
}

void Player::Draw(Engine *game) {
    
    SDL_Rect sprite_rect = {(int)(x - width/2),(int)(y - height/2),width,height};
        
    
    if (!is_dead)
        sprite.render((int)(x -width/2),(int)(y - height/2), game->renderer, NULL, &sprite_rect, rot * (180.0 / M_PI));
    
    
    
    if (show_hitbox){
        DrawHitbox(game);
    }
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

void Player::Destroy(){
    is_dead = true;
}
