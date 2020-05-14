#include "game.hpp"
#include <iostream>
#include<SDL.h>
#define width 800/2
#define height 800
using namespace std;
Play::Play():
    tetromino{static_cast<Action::Type_Block>(rand() % 7)},
    moveTime(SDL_GetTicks())
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) cout << "Couldn't initialize" << "\n" << SDL_GetError();
        else
        {
            SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS, &window, &renderer);
        }
    }
Play::~Play(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
void Play::tick(){
  bool quit = false;
  SDL_Event e;
            while(!quit)
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if( e.type == SDL_KEYDOWN )
                    {
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_s:
                            {
                                Action t = tetromino;
                                t.move(0, 1);
                                if (!well_.checkCollision(t))
                                  tetromino = t;
                            }
                            break;
                            case SDLK_d:
                              {
                                Action t = tetromino;
                                t.move(1, 0);
                                if (!well_.checkCollision(t))
                                  tetromino = t;
                              }
                              break;
                            case SDLK_a:
                              {
                                Action t = tetromino;
                                t.move(-1, 0);
                                if (!well_.checkCollision(t))
                                  tetromino = t;
                              }
                              break;
                            case SDLK_SPACE:
                              {
                                Action t = tetromino;
                                t.rotation();
                                if (!well_.checkCollision(t))
                                  tetromino = t;
                              }
                              break;
                        }
                    }
                }
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
              SDL_RenderClear(renderer);
              well_.draw(renderer);
              tetromino.draw(renderer);
              if(SDL_GetTicks() > moveTime)
              {
                  moveTime += 700;
                  Action t = tetromino;
                  t.move(0, 1);
                  if(well_.checkCollision(t))
                  {
                        well_.deleteRow(tetromino);
                        tetromino = Action{static_cast<Action::Type_Block>(rand()%7)};
                        if(well_.checkCollision(tetromino))
                        {
                            //well_ = Ahihi();
                            //return false;
                            //cout << "You Lose";
                            //exit(0);
                            //SDL_Window* window = NULL;
                            //SDL_Renderer* renderer = NULL;
                            window = NULL; renderer = NULL;
                            SDL_Surface* tempSurface = NULL;
                            SDL_Texture* texture = NULL;
                            SDL_Event mainEvent;
                            SDL_Rect sourceRect;
                            SDL_Rect desRect;
                            bool isRunning = true;
                            window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
                            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                            tempSurface = SDL_LoadBMP("aaaaaa.bmp");
                            texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
                            SDL_FreeSurface(tempSurface);

                            SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);

                            sourceRect.x = 0;
                            sourceRect.y = 0;
                            sourceRect.w = sourceRect.w / 1.79;
                            sourceRect.h = sourceRect.h / 2;

                            desRect.x = 200;
                            desRect.y = 200;
                            desRect.w = sourceRect.w;
                            desRect.h = sourceRect.h;
                            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                            while (isRunning)
                            {
                                SDL_RenderClear(renderer);
                                while (SDL_PollEvent(&mainEvent))
                                {
                                    switch (mainEvent.type)
                                    {
                                        case SDL_QUIT:
                                        {
                                            isRunning = false;
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                    }
                                }
                                SDL_RenderCopy(renderer, texture, &sourceRect, NULL);
                                SDL_RenderPresent(renderer);
                            }
                            SDL_DestroyWindow(window);
                            SDL_DestroyRenderer(renderer);
                            SDL_Quit();
                        }
                   }
                    else tetromino = t;
              }
              SDL_RenderPresent(renderer);
            }
};
