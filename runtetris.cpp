#include "runtetris.hpp"
Ahihi::Ahihi():block{{0}}{}

void Ahihi::draw(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
  for(int x = 0;x < W;++x)
  {
    for(int y = 0;y < H;++y)
    {
      if(block[x][y] == 1)
      {
        //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_Rect fillRect = { x*40+1, y*40+1, 38, 38};
        SDL_RenderFillRect(renderer, &fillRect);
      }
      else SDL_RenderDrawPoint(renderer, x*40+20, y*40+20);
    }
  }
}


bool Ahihi::check(const Action &t) const
{
  for(int x = 0;x < 4;++x)
  {
    for(int y = 0;y < 4;++y)
    {
        if(t.checkBlock(x, y) == 1)
        {
            if(block[t.x()+x][t.y()+y]) return true;
            if(t.x() + x < 0 || t.x() + x >= W || t.y() + y < 0 || t.y() + y >= H) return true;
        }
    }
  }
  return false;
}
void Ahihi::deleteLastRow(const Action &t)
{
      for(int x = 0;x < 4;++x)
      {
          for(int y = 0;y < 4;++y)
          {
              if(t.checkBlock(x, y)) block[t.x() + x][t.y() + y] = 1;
          }
      }
      int kt = 0;
      for(int y = H - 1;y >= 0;--y)
      {
        kt = 1;
        for(int x = 0;x < W;++x)
        {
            if(!block[x][y])
            {
                kt = 0;
                break;
            }
        }
        if(kt == 1)
        {
            for(int y2 = y - 1;y2 >= 0;--y2)
                for(int x = 0;x < W;++x) block[x][y2 + 1] = block[x][y2];
            for(int x = 0;x < W;++x) block[x][0] = 0;
        }
      }
}
