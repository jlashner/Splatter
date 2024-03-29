 //
//  LTexture.cpp
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/6/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#include "LTexture.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <sys/stat.h>


using namespace std;

LTexture::LTexture(){
    TTF_Init();

    
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
    font_path = "SourceSansPro-Regular.otf";
    
    font = TTF_OpenFont(font_path.c_str(), 32);

}

LTexture::~LTexture(){
    free();
}

bool LTexture::loadFromFile(std::string path, SDL_Renderer* renderer){
    
    free();
    
    SDL_Texture* newTexture = NULL;
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        printf("Unable to load image %s, SDL error: %s\n", path.c_str(), IMG_GetError());
    else{
        
//        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 255, 255, 255 ) );
        
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        } else{
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    
    mTexture = newTexture;
    return mTexture != NULL;
}

void LTexture::loadRectangle(SDL_Rect rect, SDL_Renderer *renderer, SDL_Color color){
    mTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
    mWidth = rect.w;
    mHeight = rect.h;
    
    SDL_SetRenderTarget(renderer, mTexture);
//    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
//    SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b,0);
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_SetRenderTarget(renderer, NULL);
    
    
}





bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer* renderer)
{
    //Get rid of preexisting texture
    free();
    
    //Render text surface
    
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        
        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return mTexture != NULL;
}




void LTexture::free(){
    if (mTexture != NULL){
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{ 
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::setFontSize(int size){
    font = TTF_OpenFont(font_path.c_str(), size);
}


void LTexture::render(int x, int y, SDL_Renderer* renderer,SDL_Rect* clip, SDL_Rect* dest, double angle,
                      SDL_Point* center, SDL_RendererFlip flip, bool printErrors){
    
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};

    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    if (dest != NULL)
        renderQuad = {dest->x, dest->y, dest->w, dest->h};
    
    
    if(mTexture != NULL){
        if (SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad,angle,center,flip)==-1 && true){
            printf("SDL Error: %s\n", SDL_GetError());}}
    else{
        printf("Texture is null\n");
    }
}

int LTexture::getWidth(){return mWidth;}
int LTexture::getHeight(){return mHeight;}