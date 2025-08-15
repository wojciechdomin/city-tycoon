#include "all.hpp"
using namespace sf;
using namespace std;


Building::Building(int _x, int _y, Game* gra){
    static int _id = 0;
    _id++; id = _id;
    x = _x; y = _y;
    sizex = 2; sizey = 3; sizez = 5;
    color = Color(255,255,255,255);
    type = BuildingType::road;
}

void Building::drawBuilding(Camera& camera, RenderWindow& window, RenderTexture& offscreen){
    //camera.drawQuad(vec3(x,y,0),vec3(sizex,0,0),vec3(0,sizey,0),color,window);
    auto drawBoth = [&](vec3 o, vec3 a, vec3 b, Color color){
        camera.drawQuad(o,a,b,color,window);
        camera.drawQuadOffscreen(o,a,b,id,offscreen);
    };
    drawBoth(vec3(x,y,0),vec3(sizex,0,0),vec3(0,0,sizez),Color(255,0,255,255)); //pink
    drawBoth(vec3(x,y,sizez),vec3(sizex,0,0),vec3(0,sizey,0),Color(0,0,0,255)); //black
    drawBoth(vec3(x+sizex,y,0),vec3(0,sizey,0),vec3(0,0,sizez),Color(255,255,0,255)); //yellow
}