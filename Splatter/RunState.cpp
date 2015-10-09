//
//  RunState.cpp
//  Splatter
//
//  Created by Jacob Lashner on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "RunState.hpp"
#include "Player.hpp"


RunState RunState::m_RunState;

void RunState::Init(Engine *game){
    this->game = game;
    
    map = {0, 0, 1024, 600};
    
    p = Player();
    p.Init(game);
    p.map = map;
    
    vector <Bullet> bullets (50);
    enemies.push_back(Enemy());
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Init(game);
        enemies[i].SetPlayer(&p);
    }
}

void RunState::Cleanup(){}

void RunState::Pause(){}
void RunState::Resume(){}

void RunState::HandleEvents(Engine *game, SDL_Event event){
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_SPACE:
                Bullet bullet;
                
                
                
                bullet.Init(game, p.x + 30 * cos(p.rot), p.y + 30 * sin(p.rot), p.rot, map);
                bullets.push_back(bullet);
                break;
        }
        break;
    }
    
    p.HandleEvents(game, event);
}

void RunState::Update(Engine *game){
    p.Update(game);
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Update(game);

    }
    
    for (int i = 0; i < bullets.size(); i++){
        bullets[i].Update(game);
        
        if ((bullets[i].x - p.x) * (bullets[i].x - p.x) + (bullets[i].y- p.y) * (bullets[i].y - p.y) < p.rad * p.rad){
            bullets[i].Destroy();
            p.Destroy();
            
        }
        
    }
}

void RunState::Draw(Engine *game){
    
    SDL_SetRenderDrawColor( game->renderer, 0, 0, 0, 0xFF );
    SDL_RenderClear(game->renderer); // Fill render with color

    p.Draw(game);
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Draw(game);
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].Draw(game);
    }
}


