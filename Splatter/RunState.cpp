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
    p = Player();
    p.Init(game);
    
    enemies.push_back(Enemy());
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Init(game);
    }
}

void RunState::Cleanup(){}

void RunState::Pause(){}
void RunState::Resume(){}

void RunState::HandleEvents(Engine *game, SDL_Event event){
    p.HandleEvents(game, event);
}

void RunState::Update(Engine *game){
    p.Update(game);
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Update(game);
    }
}

void RunState::Draw(Engine *game){
    
    SDL_SetRenderDrawColor( game->renderer, 0, 255, 0, 0xFF );
    SDL_RenderClear(game->renderer); // Fill render with color

    p.Draw(game);
    
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].Draw(game);
    }
}


