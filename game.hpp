#pragma once
#include <SDL.h>
#include "runtetris.hpp"
#include "movement.hpp"
class Play{
    public:
      Play();
      bool tick();
    private:
      Play(const Play &);
      Play &operator=(const Play &);
      SDL_Window* window;
      SDL_Renderer* renderer;
      Ahihi well_;
      Action tetromino;
      Uint32 moveTime;
      void check(const Action &);
};
