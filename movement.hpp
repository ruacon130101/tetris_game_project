#pragma once
#include <SDL.h>

class Action{
    public:
      enum Type_Block
      {
          I, L_Reverse, L, Square, N_Reverse, T, N
      };
      Action(Type_Block);
      void draw(SDL_Renderer*);
      void rotation();
      void move(int dx, int dy);
      int x() const;
      int y() const;
      bool checkBlock(int x, int y) const;
    private:
      Type_Block type1;
      int x1, y1, goc;
};
