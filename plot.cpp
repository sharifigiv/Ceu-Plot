#include <iostream>
#include <SDL2/SDL.h>
#include <functional>

using namespace std;

class Plot{
    public:
        int color[4];

        function<float(float)> solver = NULL;

        void draw(){
            float y = 0.1;

            while (y < 500){
                float res = solver(y);
                
                y += 0.1;
            };
        };
};