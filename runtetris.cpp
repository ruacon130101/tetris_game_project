#include "runtetris.hpp"
Ahihi::Ahihi():block{{0}}{}

void Ahihi::draw(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  for (int x = 0; x < W; ++x)
  {
    for (int y = 0; y < H; ++y)
    {
      if (block[x][y] == 1)
      {
        //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_Rect fillRect = { x , y , 31, 31};
        SDL_RenderFillRect(renderer, &fillRect);
      }
    }
  }
}


bool Ahihi::check(const Action &t) const
{
  for (int x = 0; x < 4; ++x)
  {
    for (int y = 0; y < 4; ++y)
    {
        if (t.checkBlock(x, y) == 1)
        {
            if (block[t.x()+x][t.y()+y]) return 1;
            if (t.x() + x < 0 || t.x() + x >= W || t.y() + y < 0 || t.y() + y >= H) return 1;
        }
    }
  }
  return 0;
}
void Ahihi::init(int x2, int y2)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fried[x2 + i][y2 + j] -= block[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fried[y2 + i][x2 + j] += block[i][j];
        }
    }
}
void Ahihi::unite(const Action &t)
{
  for (int x = 0; x < 4; ++x)
  {
      for (int y = 0; y < 4; ++y)
      {
          if (t.checkBlock(x, y)) block[t.x() + x][t.y() + y] = 1;
          else fried[t.x()+x][t.y()+y] = 1;
      }
  }
    int kt = 0;
  for (int y = H - 1; y >= 0; --y)
  {
    kt = 1;
    for (int x = 0; x < W; ++x)
    {
        if(!block[x][y]) kt = 0;
        if (kt == 1)
        {
            for (int y2 = y - 1; y2 >= 0; --y2)
                for (int x = 0; x < W; ++x) block[x][y2 + 1] = block[x][y2];
            for(int x = 0;x < W;++x) fried[x][0] = 0;
            for (int x = 0; x < W; ++x) block[x][0] = 0;
        }
    }
  }
}
