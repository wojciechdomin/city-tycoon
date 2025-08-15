#include "all.hpp"
using namespace sf;
using namespace std;

vec3::vec3(){
    x = y = z = 0.0;
}

vec3::vec3(float _x, float _y, float _z){
    x = _x; y = _y; z = _z;
}

vec3 vec3::operator+(vec3& b){
    return vec3(x+b.x, y+b.y, z+b.z);
}