#include <iostream>
#include <list>
#include <vector>
#include "plot.cpp"

using namespace std;

class Ploter{
    private:
        vector<Plot> plots;

    public:
        int w, h;

        void addPlot(Plot p){
            plots.push_back(p);
        };

        void draw(){
            for (auto p : plots){
                p.draw();
            };
        }
};