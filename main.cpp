#include <iostream>
#include <SDL2/SDL.h>
#include "ploter.cpp"
#include "plot.cpp"

using namespace std;

int main(){
    const int window_width = 1080;
    const int window_height = 720;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("MPloter",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width,
        window_height, SDL_WINDOW_SHOWN);

    SDL_Renderer *ren = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;

    Ploter plt = Ploter();
    plt.w = 600; plt.h = 400;    

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

        // Update the Ploter & Draw It

        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(ren);
    };

};