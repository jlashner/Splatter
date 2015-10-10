//
//  RunState.cpp
//  Splatter
//
//  Created by Jacob Lashner on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#include "RunState.hpp"
#include "Player.hpp"
#include "GameOverState.hpp"


RunState RunState::m_RunState;

void RunState::Init(Engine *game){
    this->game = game;
    
    map.w = game->getWidth()*.8;
    map.h = game->getHeight()* .8;
    map.x = game->getWidth()/2 - map.w/2;
    map.y = game->getHeight()/2 - map.h/2;
    
    
    p = Player();
    p.Init(game);
    
    p.map = map;
    
    vector <Bullet> bullets (50);

    enemies.push_back(Enemy());
    enemies[0].Init(game, 800, 100, &p);
    enemies.push_back(Enemy());
    enemies[1].Init(game, 800, map.y + map.h - 40, &p);
    enemies.push_back(Enemy());
    enemies[2].Init(game, map.x + 30,  map.y + map.h - 40, &p);

    
  
    

}

void RunState::Reset(){
    enemies.clear();
    bullets.clear();
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
                
                bullet.Init(game, p.x + (p.hit_rad + 10) * cos(p.rot), p.y + (p.hit_rad + 10) * sin(p.rot), p.rot, map);
                bullets.push_back(bullet);
                break;
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
                Bullet bullet;
            
                bullet.Init(game, p.x + (p.hit_rad + 10) * cos(p.rot), p.y + (p.hit_rad + 10) * sin(p.rot), p.rot, map);
                bullets.push_back(bullet);
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
        

        
        for (int j = 0; j < enemies.size(); j++){

            if (bullets[i].HasCollided(&enemies[j])){
                enemies[j].Destroy();
                
                enemies.erase(enemies.begin() + j - 1);
                j--;
                
                bullets.erase(bullets.begin() + i);
                i--;
                
                enemies.push_back(Enemy());
                
                for (int i = 0; i < enemies.size(); i ++){
                    enemies[i].Init(game, 800, 100, &p);
                }

            }
        }
//
        if (p.HasCollided(&bullets[i])){
            p.Destroy();
            
            bullets.erase(bullets.begin() + i);
            i--;
            
            GameOverState *gos = GameOverState::Instance();
            gos->setRunState(this);
            ChangeState(game, GameOverState::Instance() );
        }
        
    }

}

void RunState::Draw(Engine *game){
    
    SDL_SetRenderDrawColor( game->renderer, 0, 0, 0, 0xFF );
    SDL_RenderClear(game->renderer); // Fill render with color
    
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(game->renderer, &map);

    p.Draw(game);
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Draw(game);
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].Draw(game);
    }
}


