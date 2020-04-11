
#include "game.hpp"
#include "movement.hpp"
#include <iostream>
#include<string>

/*void quitSDL(SDL_Window *window, SDL_Renderer *renderer){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}*/
int main(int argc, char *argv[]){
    Play game;
    while (game.tick());
}
