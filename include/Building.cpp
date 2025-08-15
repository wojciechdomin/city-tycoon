#include "all.hpp"
using namespace sf;
using namespace std;


Building::Building(int _x, int _y){
    x = _x; y = _y;
    sizex = 2; sizey = 3; sizez = 5;
    color = Color(255,255,255,255);
    type = BuildingType::road;
}

void Building::drawBuilding(Camera& camera, RenderWindow& window){
    //camera.drawQuad(vec3(x,y,0),vec3(sizex,0,0),vec3(0,sizey,0),color,window);
    camera.drawQuad(vec3(x,y,0),vec3(sizex,0,0),vec3(0,0,sizez),Color(255,0,255,105),window);//pink
    //camera.drawQuad(vec3(x,y,0),vec3(0,sizey,0),vec3(0,0,sizez),Color(255,0,0,255),window);
    camera.drawQuad(vec3(x,y,sizez),vec3(sizex,0,0),vec3(0,sizey,0),Color(0,0,0,105),window);//black
    camera.drawQuad(vec3(x+sizex,y,0),vec3(0,sizey,0),vec3(0,0,sizez),Color(255,255,0,105),window);//yellow


}