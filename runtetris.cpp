#include "runtetris.hpp"
Ahihi::Ahihi():block{{0}}{}

void Ahihi::draw(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  for (int x = 0; x < W; ++x)
  {
    for (int y = 0; y < H; ++y)
    {
      if (block[x][y])
      {
        //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_Rect fillRect = { x , y , 31, 31};
        SDL_RenderFillRect(renderer, &fillRect);
      }
      else
        SDL_RenderDrawPoint(renderer, x , y);
    }
  }
}


bool Ahihi::check(const Action &t) const
{
  for (int x = 0; x < 4; ++x)
  {
    for (int y = 0; y < 4; ++y)
    {
        if (t.checkBlock(x, y))
        {
            int ddx = t.x() + x;
            int ddy = t.y() + y;
            if (block[ddx][ddy]) return 1;
            if (ddx < 0 || ddx >= W || ddy < 0 || ddy >= H) return 1;
        }
    }
  }
  return 0;
}

void Ahihi::unite(const Action &t)
{
  for (int x = 0; x < 4; ++x)
  {
      for (int y = 0; y < 4; ++y)
      {
          if (t.checkBlock(x, y)) block[t.x() + x][t.y() + y] = 1;
      }
  }

  for (int y = H - 1; y >= 0; --y)
  {
    int kt = 1;
    for (int x = 0; x < W; ++x)
    {
        if (!block[x][y])
        {
            kt = 0;
            break;
        }
        if (kt)
        {
            for (int y2 = y - 1; y2 >= 0; --y2)
                for (int x = 0; x < W; ++x) block[x][y2 + 1] = block[x][y2];
            for (int x = 0; x < W; ++x) block[x][0] = 0;
        }
    }
  }
}
