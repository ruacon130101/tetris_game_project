#include "movement.hpp"
#include <SDL.h>

class Init{
    public:
      Init();
      enum
      {
          W = 10, H = 20
      };
      void draw(SDL_Renderer *);
      bool checkCollision(const Action &t) const;
      void deleteRow(const Action &);
    private:
      bool block[W][H];
};
