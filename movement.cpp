#include "movement.hpp"

Action::Action(Type_Block type):
  type1(type),x1(3), y1(0), goc(0){}
void Action::draw(SDL_Renderer* renderer){
    switch (type1)
    {
      case I:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        break;
      case L_Reverse:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xBF, 0xF0, 0xFF);
        break;
      case L:
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        break;
      case Square:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
        break;
      case N_Reverse:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        break;
      case T:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
        break;
      case N:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xA5, 0x00, 0xFF);
        break;
    }
  for (int x = 0; x < 4; ++x)
  {
      for (int y = 0; y < 4; ++y)
      {
          if (checkBlock(x, y))
          {
        //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
            SDL_Rect fillRect = {(x+x1)*40+1, (y+y1)*40+1, 38, 38};
            SDL_RenderFillRect(renderer, &fillRect);
          }
      }
  }
}
void Action::rotation(){
    goc = (goc+3)%4;
}
void Action::move(int dx, int dy){
  x1 += dx;
  y1 += dy;
}
int Action::x() const{
  return x1;
}
int Action::y() const{
  return y1;
}
bool Action::checkBlock(int x, int y) const{
  static const char *Tetris[][4] = {
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
  return Tetris[type1][goc][x+y*4] == '#';
}

