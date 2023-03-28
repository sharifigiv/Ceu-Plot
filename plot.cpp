#include <iostream>
#include <functional>

using namespace std;

class Plot{
    public:
        int color[4];

        function<int(int)> solver = NULL;

        void draw(){
            
        };
};