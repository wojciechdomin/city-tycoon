#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <math.h>
using namespace sf;
using namespace std;



const int MAX_N = 100;

class vec3{
public:
    float x,y,z;
    vec3(float _x, float _y, float _z){
        x = _x; y = _y; z = _z;
    }
    vec3 operator+(vec3& b){
        return vec3(x+b.x, y+b.y, z+b.z);
    }
};

class Camera{
    public:
    float offsetx;
    float offsety;
    float originx;
    float originy;
    float focus; 
    Camera(){
        offsetx = offsety = 0.0; focus = 10.0;
        originx = 0.0;
        originy = 700.0;
    }
    Vector2f transform(vec3 o){
        float x,y,z;
        x = o.x; y = o.y; z = o.z;
        x-=offsetx;
        y-=offsety;
        x*=focus; y*=focus; z*=focus;
        return Vector2f(originx+x+y,originy-0.5*y+z);
    }

    void drawQuad(vec3 o, vec3 a, vec3 b, Color color, RenderWindow &window){
        VertexArray quad(PrimitiveType::TriangleStrip, 4);
        quad[0].position = transform(o);
        quad[1].position = transform(o+a);
        quad[2].position = transform(o+b);
        quad[3].position = transform(o+a+b);
        quad[0].color = quad[1].color = quad[2].color = quad[3].color = color;
        window.draw(quad);
    }




};

class Game{
    public:
    Camera camera;
    Color tileColor[MAX_N][MAX_N];
    bool dragState;
    Vector2i first_click;

    Game(){
        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < MAX_N; j++){
                tileColor[i][j] = Color(rand()%255,rand()%255,rand()%255,100);
            }
        }
        dragState = false;
    }
    void drawScene(RenderWindow &window){
        for(int i = 0; i < MAX_N; i++){
            for(int j = 0; j < MAX_N; j++){
               /* VertexArray quad(PrimitiveType::TriangleStrip, 4);
                quad[0].position = Vector2f(5.0*i    , 5.0*j    );
                quad[1].position = Vector2f(5.0*i+5.0, 5.0*j    );
                quad[2].position = Vector2f(5.0*i    , 5.0*j+5.0);
                quad[3].position = Vector2f(5.0*i+5.0, 5.0*j+5.0);
                quad[0].color = tileColor[i][j];
                quad[1].color = tileColor[i][j];
                quad[2].color = tileColor[i][j];
                quad[3].color = tileColor[i][j];
                window.draw(quad);*/
                camera.drawQuad(vec3(i*1.0,j*1.0,0.0),vec3(1.0,0.0,0.0),vec3(0.0,1.0,0.0),tileColor[i][j],window);

            }
        }
        if(dragState){

            VertexArray quad(PrimitiveType::TriangleStrip, 4);
            Vector2i second_click = Mouse::getPosition(window);
            //std::cout<<first_click.x<<","<<first_click.y<<","<<second_click.x<<","<<second_click.y<<"\n";
            quad[0].position = Vector2f(first_click.x*1.0  ,  first_click.y *1.0);
            quad[1].position = Vector2f(second_click.x*1.0 , first_click.y*1.0 );
            quad[2].position = Vector2f(first_click.x *1.0 , second_click.y*1.0);
            quad[3].position = Vector2f(second_click.x *1.0 ,  second_click.y*1.0);
            quad[0].color = quad[1].color = quad[2].color = quad[3].color = Color(0,0,255,125);
            window.draw(quad);

        }
    }
    void endDrag(Event &event){
        Vector2i second_click(event.mouseButton.x,event.mouseButton.y);
        for(int i = max(0,min(first_click.x,second_click.x)/5); i <= min(MAX_N-1, max(first_click.x,second_click.x)/5); i++){
            for(int j = max(0,min(first_click.y,second_click.y)/5); j <= min(MAX_N-1, max(first_click.y,second_click.y)/5); j++){
                tileColor[i][j] = Color(0,0,80,125);

            }
        }


    }

};



int main(){


    RenderWindow window(VideoMode({1200,900}),"Okno",Style::Close);
    RenderTexture offscene; 
    offscene.create(1200,900);
    window.setFramerateLimit(60);

    Game* gra = new Game(); 

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event :: Closed){
                window.close();
            }
            if(event.type == Event::KeyPressed){
                //std::cout<<"Pressed: "<<event.key.code<<"\n";
            }
            if(event.type == Event::KeyReleased){
                //std::cout<<"Released: "<<event.key.code<<"\n";
            }
            if(event.type == Event::MouseMoved){
                //std::cout<<"MouseMoved: "<<event.mouseMove.x<<","<<event.mouseMove.y<<"\n";
                int x = event.mouseMove.x;
                int y = event.mouseMove.y;
                if(x >= 0 && y >= 0 && x < 500 && y < 500){
                    gra->tileColor[x/5][y/5] = Color(rand()%255,0,0);
                }
            }
            if(event.type == Event::MouseButtonPressed){
                gra->dragState = true;
                gra->first_click = Vector2i(event.mouseButton.x,event.mouseButton.y);
                std::cout<<"Event::MouseButtonPressed\n";
            }
            if(event.type == Event::MouseButtonReleased){
                gra->dragState = false;
                gra->endDrag(event);
            }
        }
        static float f = 0.0;
        f+=0.01;
        window.clear(Color(100+100*sin(f),100,180));
        gra->drawScene(window);
        window.display();
    }
}