#include <iostream>
#include <SDL2/SDL.h>
#include "ploter.cpp"

using namespace std;

float solverr(float y){
    return y + 2;
}

int main(){

    const int window_width = 1080;
    const int window_height = 720;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
        cout << "Initialization failed" << endl;
    }

    SDL_Window *window = SDL_CreateWindow("MPloter",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width,
        window_height, SDL_WINDOW_SHOWN);

    SDL_Renderer *ren = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;

    Ploter plt = Ploter();
    plt.w = 600; plt.h = 400;  

    Plot p = Plot();
    p.ren = ren;
    
    p.solver = solverr;

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

        SDL_RenderDrawPoint(ren, 540, 360);

        // Update the Ploter & Draw It

        p.draw();

        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(ren);
    };

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
};

