#include "movement.hpp"
#include <SDL.h>

class Ahihi{
    public:
      Ahihi();
      enum
      {
          W = 10, H = 20
      };
      void draw(SDL_Renderer *);
      bool checkCollision(const Action &t) const;
      void deleteRow(const Action &);
      void init(int x2, int y2);
    private:
      bool block[W][H];
      bool fried[W][H];
};
