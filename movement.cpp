#include "movement.hpp"

Action::Action(Type type):
  type1(type),x1(3), y1(0){}

void Action::draw(SDL_Renderer* renderer)
{
  for (int x = 0; x < 4; ++x)
  {
      for (int y = 0; y < 4; ++y)
      if (checkBlock(x, y))
      {
        //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_Rect fillRect = {(x + x1) * 33 + 1, (y + y1) * 33 + 1, 31, 31};
        SDL_RenderFillRect(renderer, &fillRect);
      }
  }
}

void Action::move(int dx, int dy)
{
  x1 += dx;
  y1 += dy;
}
int Action::x() const
{
  return x1;
}
int Action::y() const
{
  return y1;
}
int Action::checkBlock(int x, int y) const
{
  const char *Shapes[][4] = {
    {
      " #  "
      " #  "
      " #  "
      " #  ",
      "    "
      "####"
      "    "
      "    ",
      " #  "
      " #  "
      " #  "
      " #  ",
      "    "
      "####"
      "    "
      "    ",
    },
    {
      "  # "
      "  # "
      " ## "
      "    ",
      "    "
      "#   "
      "### "
      "    ",
      " ## "
      " #  "
      " #  "
      "    ",
      "    "
      "    "
      "### "
      "  # ",
    },
    {
      " #  "
      " #  "
      " ## "
      "    ",
      "    "
      "### "
      "#   "
      "    ",
      " ## "
      "  # "
      "  # "
      "    ",
      "  # "
      "### "
      "    "
      "    ",
    },
    {
      "    "
      " ## "
      " ## "
      "    ",
      "    "
      " ## "
      " ## "
      "    ",
      "    "
      " ## "
      " ## "
      "    ",
      "    "
      " ## "
      " ## "
      "    ",
    },
    {
      "  # "
      " ## "
      " #  "
      "    ",
      "    "
      "##  "
      " ## "
      "    ",
      "  # "
      " ## "
      " #  "
      "    ",
      "    "
      "##  "
      " ## "
      "    ",
    },
    {
      " #  "
      " ## "
      " #  "
      "    ",
      "    "
      "### "
      " #  "
      "    ",
      " #  "
      "##  "
      " #  "
      "    ",
      " #  "
      "### "
      "    "
      "    ",
    },
    {
      " #  "
      " ## "
      "  # "
      "    ",
      "    "
      " ## "
      "##  "
      "    ",
      " #  "
      " ## "
      "  # "
      "    ",
      "    "
      " ## "
      "##  "
      "    ",
    },
  };
  return Shapes[type1][0][x + y * 4] == '#';
}
