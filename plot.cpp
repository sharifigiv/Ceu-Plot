#include <iostream>
#include <SDL2/SDL.h>
#include <functional>

using namespace std;

class Plot{
    public:
        int color[4];

        function<float(float)> solver = NULL;
        SDL_Renderer *ren = NULL;

        void draw(){
            float y = 0.1;

            while (y < 720){
                float res = solver(y);
                
                SDL_RenderDrawPoint(ren, int(res), int(y));

                y += 0.1;
            };
        };
};