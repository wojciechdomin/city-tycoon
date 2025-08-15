#include "all.hpp"

Camera::Camera(){
    offsetx = offsety = 0.0; focus = 50.0;
    originx = 0.0;
    originy = 700.0;
}

Vector2f Camera::transform(vec3 o){
    float x,y,z;
    x = o.x; y = o.y; z = o.z;
    x-=offsetx;
    y-=offsety;
    x*=focus; y*=focus; z*=focus;
    return Vector2f(originx+x+y,originy-0.5*y-z);
}

vec3 Camera::transformBack(Vector2f r){
    r.x -= originx; r.y-=originy;
    r.y*=(-2.0); r.x-=r.y;
    r.x/=focus; r.y/=focus;
    r.x+=offsetx; r.y+=offsety;
    return vec3(r.x,r.y,0);
}

void Camera::drawQuad(vec3 o, vec3 a, vec3 b, Color color, RenderWindow &window){
    VertexArray quad(PrimitiveType::TriangleStrip, 4);
    quad[0].position = transform(o);
    quad[1].position = transform(o+a);
    quad[2].position = transform(o+b);
    quad[3].position = transform(o+a+b);
    quad[0].color = quad[1].color = quad[2].color = quad[3].color = color;
    window.draw(quad);
}
