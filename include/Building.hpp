#pragma once
#include "all.hpp"
using namespace sf;
using namespace std;

class Building{
    public:
    enum class BuildingType{
        road = 0,
        house = 1
    };
    bool exists;
    Game* gra;
    int x,y; int id;
    int sizex,sizey,sizez;
    Color color;
    BuildingType type;
    Building(int _x, int _y, Game* gra);
    ~Building();
    void drawBuilding(Camera& camera, RenderWindow& window, RenderTexture& offscreen);

};
