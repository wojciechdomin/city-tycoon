#pragma once
#include "all.hpp"
using namespace sf;
using namespace std;



class Game{
    public:
    Camera camera;
    Color tileColor[MAX_N][MAX_N];
    Building* tileBuilding[MAX_N][MAX_N];
    bool dragState;
    vec3 first_click;
    Game();
    void onTick();
    void drawScene(RenderWindow &window, RenderTexture &offscreen);
    void endDrag(Event &event);

};
