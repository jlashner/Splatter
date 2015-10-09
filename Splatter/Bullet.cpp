//
//  Bullet.cpp
//  Splatter
//
//  Created by Liza Woythaler on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "Bullet.hpp"
#include "Entity.hpp"





void Bullet::Init(Engine* game, float X, float Y, float Rot, SDL_Rect Map)
{
    x = X;
    y = Y;
    rot = Rot;
    vi = 300;
    vx = vi*cos(rot);
    vy = vi*sin(rot);
    map = Map;
}

void Bullet::Update(Engine* game)
{
    float newx = x + (vx * game->getDelta());
    float newy = y + (vy * game->getDelta());
    
    if (newx < map.x) {
        x = map.x;
        vx = -vx;
    } else if (newx > (map.x + map.w - width)) {
        x = map.x + map.w - width;
        vx = -vx;
    } else {
        x = newx;
    }
    
    if (newy < map.y) {
        y = map.y;
        vy = -vy;
    } else if (newy > (map.y + map.h - height)) {
        y = map.y + map.h - height;
        vy = -vy;
    } else {
        y = newy;
    }
}

void Bullet::Draw(Engine* game)
{
    SDL_SetRenderDrawColor( game->renderer, 0, 0, 255, 0xFF );
    SDL_Rect bullet_rect = {x, y,10, 10};
    SDL_RenderFillRect(game->renderer, &bullet_rect);

}

void Bullet::HandleEvents(Engine* game, SDL_Event event)
{
    
}