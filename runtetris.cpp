#include "runtetris.hpp"
Init::Init():block{{0}}{}

void Init::draw(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 133, 0, 0, 133);
  for(int x = 0;x < W;++x)
  {
    for(int y = 0;y < H;++y)
    {
      if(block[x][y] == 1)
      {
        SDL_Rect fillRect = { x*40+1, y*40+1, 36, 36};
        SDL_RenderFillRect(renderer, &fillRect);
      }
      else if(block[x][y] != 1) SDL_RenderDrawPoint(renderer, x*40+20, y*40+20);
    }
  }
}


bool Init::checkCollision(const Action &t) const
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
void Init::deleteRow(const Action &t)
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
        }
      }
}
