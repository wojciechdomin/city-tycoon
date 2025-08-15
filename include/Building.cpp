#include "all.hpp"
using namespace sf;
using namespace std;


Building::Building(int _x, int _y, Game* gra){
    static int _id = 0;
    _id++; id = _id;
    gra->buildingList.push_back(this);
    x = _x; y = _y;
    sizex = 1+rand()%6; sizey = 1+rand()%6; sizez = 1+rand()%12;
    color = Color(255,255,255,255);
    type = BuildingType::road;
    exists = true;
    for(int i = max(0,x); i < min(x+sizex, MAX_N); i++){
        for(int j = max(0,y); j < min(y+sizey,MAX_N); j++){
            if(gra->tileBuilding[i][j]!=nullptr) return;
        }
    }
    for(int i = max(0,x); i < min(x+sizex, MAX_N); i++){
        for(int j = max(0,y); j < min(y+sizey,MAX_N); j++){
            gra->tileBuilding[i][j] = this;
        }
    }
}

Building::~Building(){
    for(int i = max(0,x); i < min(x+sizex, MAX_N); i++){
        for(int j = max(0,y); j < min(y+sizey,MAX_N); j++){
            gra->tileBuilding[i][j] = nullptr;
        }
    }
    exists = false;



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
