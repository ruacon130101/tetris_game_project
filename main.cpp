
#include "game.hpp"
#include "movement.hpp"
#include <iostream>
#include<string>
#include<ctime>
using namespace std;
const int SCREEN_WIDTH = 800/2;
const int SCREEN_HEIGHT = 800;
const char WINDOW_TITLE[] = "Mouse in SDL";
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //   SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
}
int main(int argc, char **argv) {
    srand(time(0));
    /*SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);*/
    SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* tempSurface = NULL;
	SDL_Texture* texture = NULL;
	SDL_Event mainEvent;
	SDL_Rect sourceRect;
	SDL_Rect desRect;
	bool isRunning = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Couldn't initialize %s\n", SDL_GetError());
		return -1;
	}
	window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Couldn't create window %s", SDL_GetError());
		return -1;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Couldn't create render %s", SDL_GetError());
		return -1;
	}
	tempSurface = SDL_LoadBMP("aa.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = sourceRect.w / 2;
	sourceRect.h = sourceRect.h / 2;

	desRect.x = 200;
	desRect.y = 200;
	desRect.w = sourceRect.w;
	desRect.h = sourceRect.h;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	Play game;
    SDL_Event e;
	while (isRunning)
	{
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&mainEvent))
		{
			switch (mainEvent.type)
			{
				case SDL_QUIT:
				{
					isRunning = false;
					break;
				}
				default:
				{
					break;
				}
			}
		}
		SDL_RenderCopy(renderer, texture, &sourceRect, NULL);
		SDL_RenderPresent(renderer);
		while(true)
        {
            if ( SDL_WaitEvent(&e) == 0) continue;
            if (e.type == SDL_QUIT) break;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;
            if (e.type == SDL_MOUSEBUTTONDOWN) game.tick();
        }
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

