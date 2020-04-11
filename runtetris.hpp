#include "movement.hpp"
#include <SDL.h>

class Ahihi{
    public:
      Ahihi();
      enum { W = 10, H = 20 };
      void draw(SDL_Renderer *);
      bool check(const Action &t) const;
      void unite(const Action &);
    private:
      bool block[W][H];
};
