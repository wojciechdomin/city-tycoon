#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
using namespace sf;


struct vec3{
    float x,y,z;
    vec3(float _x, float _y, float _z){
        x = _x; y = _y; z = _z;
    }
    vec3 operator+(vec3& b){
        return vec3(x+b.x, y+b.y, z+b.z);
    }
    vec3 operator-(vec3& b){
        return vec3(x-b.x, y-b.y, z-b.z);
    }

};

vec3 operator*(float f, vec3& a){
    return vec3(f*a.x,f*a.y,f*a.z);
}

struct color{
    float r,g,b,a;
    color(float _r, float _g, float _b){
        r = _r; g = _g; b = _b; a = 1.f;
    }
};


void drawTriangle(vec3 origin, vec3 first, vec3 second, color color){
    glBegin(GL_TRIANGLES);
    auto makeVertex = [&](vec3 a){glVertex3f(a.x,a.y,a.z);};
    glColor3f(color.r,color.g,color.b);
    makeVertex(origin);
    makeVertex(origin+first);
    makeVertex(origin+second);
    glEnd();
}

void drawParallelogram(vec3 origin, vec3 first, vec3 second, color color){
          drawTriangle(origin, first, second,color);
          drawTriangle(origin+first+second, (-1.0)*first, (-1.0)*second,color);
}

int main(){

    //obrzydliwe
    int mousex = 0;
    int mousey = 0;


    //


    Window window(VideoMode({600,800}),"Okno",Style::Default);
    window.setVerticalSyncEnabled(true);

    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* vendor   = glGetString(GL_VENDOR);
    const GLubyte* glsl     = glGetString(GL_SHADING_LANGUAGE_VERSION);

    std::cout << "OpenGL Version: " << version << "\n";
    std::cout << "Renderer: " << renderer << "\n";
    std::cout << "Vendor: " << vendor << "\n";
    std::cout << "GLSL Version: " << glsl << "\n";


    window.setFramerateLimit(60);

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 800, 600);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -0.75, 0.75, 1.0, 100.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event :: Closed){
                window.close();
            }
            if(event.type == Event::KeyPressed){
                std::cout<<"Pressed: "<<event.key.code<<"\n";
            }
            if(event.type == Event::KeyReleased){
                std::cout<<"Released: "<<event.key.code<<"\n";
            }
            if(event.type == Event::MouseMoved){
                std::cout<<"MouseMoved: "<<event.mouseMove.x<<","<<event.mouseMove.y<<"\n";
                mousex = event.mouseMove.x;
                mousey = event.mouseMove.y;
            }
        }
        glClearColor(0.13f, 0.23f, 0.45f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        vec3 a(1.0,1.0,1.0);
        vec3 b(10.0,0.0,0.0);
        vec3 c(0.0,10.0,0.0);
        color red(1.0,0.0,0.0);
        drawParallelogram(a,b,c,red);



        //window.clear(Color::White);
        window.display();
    }
}