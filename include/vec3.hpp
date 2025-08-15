#pragma once
#include "all.hpp"
using namespace sf;
using namespace std;

class vec3{
public:
    float x,y,z;
    vec3();
    vec3(float _x, float _y, float _z);
    vec3 operator+(vec3& b);
};
