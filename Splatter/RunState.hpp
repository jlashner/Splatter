//
//  RunState.hpp
//  Splatter
//
//  Created by Jacob Lashner on 10/9/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef RunState_hpp
#define RunState_hpp

#include <stdio.h>
#include <vector>
#include "Engine.h"
#include "GameState.h"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "EnemyFactory.hpp"

using namespace std;

class RunState : public GameState
{
public:
    
    RunState() { }
    
    void Init(Engine* game);
    void Reset();
    void Cleanup();
    
    void Pause();
    void Resume();
    
    void HandleEvents(Engine* game, SDL_Event event);
    void Update(Engine* game);
    void Draw(Engine* game);
    
    static RunState* Instance() {
        return &m_RunState;
    }
    


    
private:
    Engine* game;
    static RunState m_RunState;
    SDL_Rect map;
    Player p;
    vector<Bullet> bullets;
    EnemyFactory enemyFactory;
};


#endif /* RunState_hpp */
