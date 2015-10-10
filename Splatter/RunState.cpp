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
    
    enemyFactory.addEnemy(game, 800, 100, &p);
    
}

void RunState::Reset(){
    enemyFactory.despawnAll();
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
    
    enemyFactory.updateEnemies(game);
    
    for (int i = 0; i < bullets.size(); i++){
        bullets[i].Update(game);
        
            if (enemyFactory.bulletDidHidEnemy(&bullets[i])) {
                bullets.erase(bullets.begin() + i);
                i--;
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
    
    enemyFactory.drawEnemies(game);
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].Draw(game);
    }
}


