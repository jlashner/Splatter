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
#include "Engine.h"
#include "GameState.h"

class RunState : public GameState
{
public:
    void Init(Engine* game);
    void Cleanup();
    
    void Pause();
    void Resume();
    
    void HandleEvents(Engine* game, SDL_Event event);
    void Update(Engine* game);
    void Draw(Engine* game);
    
    static RunState* Instance() {
        return &m_RunState;
    }
    
protected:
    RunState() { }
    
private:
    static RunState m_RunState;
    
};


#endif /* RunState_hpp */
