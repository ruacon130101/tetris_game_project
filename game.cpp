#include "game.hpp"
#include <iostream>
#define width 660/2
#define height 660
using namespace std;
Play::Play():
  tetromino{static_cast<Action::Type>(rand() % 7)},
  moveTime(SDL_GetTicks())
{
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
}
void Play::quitSDL(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
bool Play::tick(){
  bool quit = 0;
  SDL_Event e;
            while(!quit)
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = 1;
                    }
                    else if( e.type == SDL_KEYDOWN )
                    {
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_s:
                            {
                                Action t = tetromino;
                                t.move(0, 1);
                                if (!well_.check(t))
                                  tetromino = t;
                            }
                            break;
                            case SDLK_d:
                              {
                                Action t = tetromino;
                                t.move(1, 0);
                                if (!well_.check(t))
                                  tetromino = t;
                              }
                              break;
                            case SDLK_a:
                              {
                                Action t = tetromino;
                                t.move(-1, 0);
                                if (!well_.check(t))
                                  tetromino = t;
                              }
                              break;
                            case SDLK_SPACE:
                              {
                                Action t = tetromino;
                                if (!well_.check(t))
                                  tetromino = t;
                              }
                              break;
                        }
                    }
                }
              SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x4f);
              SDL_RenderClear(renderer);
              well_.draw(renderer);
              tetromino.draw(renderer);
              SDL_RenderPresent(renderer);
            return true;
            }
};
