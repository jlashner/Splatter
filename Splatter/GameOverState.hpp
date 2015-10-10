//
//  GameOverState.hpp
//  Splatter
//
//  Created by Jacob Lashner on 10/10/15.
//  Copyright © 2015 WesHack. All rights reserved.
//

#ifndef GameOverState_hpp
#define GameOverState_hpp

#include <stdio.h>
#include "Engine.h"
#include "GameState.h"
#include "LTexture.h"
#include "RunState.hpp"


class GameOverState : public GameState
{
public:
    
    LTexture game_over_tex = LTexture();
    LTexture score_tex = LTexture();
    LTexture play_again_tex = LTexture();
    LTexture play_again_tex_sel = LTexture();
    LTexture quit_tex = LTexture();
    LTexture quit_tex_sel = LTexture();

    SDL_Rect box;
    
    int cursor_pos;
    
    void Init(Engine* game);
    void Cleanup();
    
    void Pause();
    void Resume();
    
    void HandleEvents(Engine* game, SDL_Event event);
    void Update(Engine* game);
    void Draw(Engine* game);
    
    void setRunState(RunState* r){runstate = r;}
    
    static GameOverState* Instance() {
        return &m_GameOverState;
    }
    
    SDL_Color black = {0,0,0,255};
    SDL_Color white = {255,255,255,255};
    SDL_Color light_blue = {105, 217, 255,255};
    
    bool up_key_pressed = false, down_key_pressed = false;
    
protected:
    GameOverState() { }
    
private:

    
    Engine* game;
    static GameOverState m_GameOverState;
    RunState* runstate;
    
};


#endif /* GameOverState_hpp */
