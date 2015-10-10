//
//  GameOverState.cpp
//  Splatter
//
//  Created by Jacob Lashner on 10/10/15.
//  Copyright © 2015 WesHack. All rights reserved.
//



#include "GameOverState.hpp"
#include "RunState.hpp"


GameOverState GameOverState::m_GameOverState;

void GameOverState::Init(Engine* game){

    box.w = game->getWidth() * .6;
    box.h = game->getHeight() * .5;
    box.x = game->getWidth()/2 - box.w/2;
    box.y = game->getHeight()/2 - box.h/2;

    cursor_pos = 0;
    
    game_over_tex.loadFromRenderedText("GAME OVER", black, game->renderer);
    score_tex.loadFromRenderedText("Your score was: 0", black, game->renderer);
    play_again_tex.loadFromRenderedText("Play Again", black , game->renderer);
    play_again_tex_sel.loadFromRenderedText("Play Again", light_blue , game->renderer);
    quit_tex.loadFromRenderedText("Quit", black, game->renderer);
    quit_tex_sel.loadFromRenderedText("Quit", light_blue, game->renderer);
}

void GameOverState::Cleanup(){
    game_over_tex.free();
    score_tex.free();
    play_again_tex.free();
    quit_tex.free();
}

void GameOverState::Pause(){}

void GameOverState::Resume(){}

void GameOverState::HandleEvents(Engine* game, SDL_Event event){
    int new_curs = cursor_pos;
    
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    if (!up_key_pressed){
                        new_curs += 1;
                        up_key_pressed =true;
                        down_key_pressed = false;
                    }
                    break;
                case SDLK_DOWN:
                    if (!down_key_pressed){
                        new_curs += 1;
                        up_key_pressed = false;
                        down_key_pressed = true;
                    }
                    break;
                case SDLK_SPACE:
                    switch (cursor_pos) {
                        case 0:
                            runstate->Reset();
                            runstate->Init(game);
                            game->PopState();
                            game->PopState();
                            ChangeState(game, runstate);
                            
                            break;
                        case 1:
                            game->Quit();
                            break;
                            
                        default:
                            break;
                    }
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    up_key_pressed = false;
                    break;
                case SDLK_DOWN:
                    down_key_pressed = false;
                    break;
                case SDLK_SPACE:
                    break;
            }
            break;
    }
    
    cursor_pos = new_curs % 2;
    printf("%d, %d\n", new_curs, cursor_pos);
    
}

void GameOverState::Update(Engine* game){}

void GameOverState::Draw(Engine* game){
    
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &box);
    
    play_again_tex.setColor(-light_blue.r, -light_blue.g, -light_blue.b);

    
    game_over_tex.render(box.x + box.w/2 - game_over_tex.getWidth()/2, box.y + 50, game->renderer);
    score_tex.render(box.x + box.w/2 - score_tex.getWidth()/2, box.y + 100, game->renderer);
    if (cursor_pos == 0){
        play_again_tex_sel.render(box.x + box.w/2 - play_again_tex.getWidth()/2, box.y + 150, game->renderer);
        quit_tex.render(box.x + box.w/2 - quit_tex.getWidth()/2, box.y + 200, game->renderer);
    }
    else{
        play_again_tex.render(box.x + box.w/2 - play_again_tex.getWidth()/2, box.y + 150, game->renderer);
        quit_tex_sel.render(box.x + box.w/2 - quit_tex.getWidth()/2, box.y + 200, game->renderer);

    }
    
    

}


