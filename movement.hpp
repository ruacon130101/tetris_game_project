#pragma once
#include <SDL.h>

class Action{
    public:
      enum Type { I , L, J, S, T, Z, O };
      Action(Type);
      void draw(SDL_Renderer *);
      void move(int dx, int dy);
      int checkBlock(int x, int y) const;
      int x() const;
      int y() const;
    private:
      Type type1;
      int x1;
      int y1;
};
