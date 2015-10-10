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

void Enemy::Init(Engine *game, double x, double y, Player* player){
    this->x = x;
    this->y = y;
    
    target = player;
    
    vx = 3;
    vy = 0;
    width = 40, height = 40;
    
    hit_rad = 40;
    
    rot = 0;
    maxvel = 100;
    ai = Chase;
    
    sprite.loadFromFile("assets/Enemy.png", game->renderer);

}



void Enemy::Update(Engine* game){
    float tx = 0;
    float ty = 0;
    float vx0, vy0;
    
    
    switch(ai){
        case Chase:
            tx =  target->x + (game->getDelta() * 30) * target->vx;
            ty = target->y + (game->getDelta() * 30) * target->vy;
            
            vx0 = tx - x;
            vy0 = ty - y;
            
            vx = vx0/sqrt((vx0 * vx0 + vy0 * vy0)) * maxvel;
            vy = vy0/sqrt((vx0 * vx0 + vy0 * vy0)) * maxvel;
            
            rot = atan2f(vy, vx);

            x += vx * game->getDelta();
            y += vy * game->getDelta();
            
            
            break;
            
    }

}

void Enemy::Destroy(){
    is_dead = true;
}

void Enemy::Draw(Engine *game){
    SDL_Rect sprite_rect = {(int)x - width/2,(int)y - height/2,width,height};
    if (!is_dead)
        sprite.render((int)(x -width/2),(int)(y - height/2), game->renderer, NULL, &sprite_rect, rot* 180 /  M_PI);


    
    
}

