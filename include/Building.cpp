#include "all.hpp"
using namespace sf;
using namespace std;


Building::Building(int _x, int _y){
    x = _x; y = _y;
    sizex = 2; sizey = 3; sizez = 5;
    type = BuildingType::road;
}