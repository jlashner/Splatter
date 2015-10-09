//
//  Enemy.cpp
//  Splatter
//
//  Created by Jacob Lashner on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "Enemy.hpp"
#include "Player.hpp"

void Enemy::HandleEvents(Engine *game, SDL_Event event){}

void Enemy::Init(Engine *game){
    x = 50, y = 50;
    vx = 3;
    vy = 0;
    maxvel = 100;
    ai = Chase;
}

void Enemy::SetPlayer(Player* p){
    target = p;
}

void Enemy::Update(Engine* game){
    float tx = 0;
    float ty = 0;
    float vx0, vy0;
    
    float vxnorm, vynorm;
//
//    x += vx * game->getDelta();
//    y += vy * game->getDelta();
    
    switch(ai){
        case Chase:
            tx =  target->x + (game->getDelta() * 30) * target->vx;
            ty = target->y + (game->getDelta() * 30) * target->vy;
            
            vx0 = tx - x;
            vy0 = ty - y;
            
            vx = vx0/sqrt((vx0 * vx0 + vy0 * vy0)) * maxvel;
            vy = vy0/sqrt((vx0 * vx0 + vy0 * vy0)) * maxvel;
            
            printf("%f\n", vx* vx + vy * vy);

//            printf("%f, %f, %f\n", tx ,ty, theta);
//            vx = maxvel * cos(theta);
//            vy = maxvel * sin(theta);
            
            x += vx * game->getDelta();
            y += vy * game->getDelta();
            
            
            break;
            
    }

}

void Enemy::Draw(Engine *game){
    SDL_Rect rect = {(int)x,(int)y,20,20};
    
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(game->renderer, &rect);
}

