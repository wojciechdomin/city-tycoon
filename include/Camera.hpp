#pragma once
#include "all.hpp"
using namespace sf;
using namespace std;

class Camera{
    public:
    float offsetx;
    float offsety;
    float originx;
    float originy;
    float focus;
    Camera();
    Vector2f transform(vec3 o);

    vec3 transformBack(Vector2f r);
    //now implement off-screen color picking...

    void drawQuad(vec3 o, vec3 a, vec3 b, Color color, RenderWindow &window);
    void drawQuadOffscreen(vec3 o, vec3 a, vec3 b, unsigned int id, RenderTexture &offscren);




};
