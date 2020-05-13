#pragma once
#include <SDL.h>

class Action{
    public:
      enum Type {I, J, L, O, S, T, Z};
      Action(Type);
      void draw(SDL_Renderer*);
      void rotation();
      void move(int dx, int dy);
      int x() const;
      int y() const;
      bool checkBlock(int x, int y) const;
    private:
      Type type1;
      int x1, y1, goc;
};
