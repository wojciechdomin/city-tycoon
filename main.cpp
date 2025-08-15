#include "include/all.hpp"
using namespace sf;
using namespace std;













int main(){


    RenderWindow window(VideoMode({1200,900}),"Okno",Style::Close);
    RenderTexture offscene; 
    offscene.create(1200,900);
    window.setFramerateLimit(60);

    Game gra; 

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event :: Closed){
                window.close();
            }
            if(event.type == Event::KeyPressed){
                if(event.key.code == int('w'-'a')){
                    gra.camera.originy+= gra.camera.focus;
                }
                if(event.key.code == int('s'-'a')){
                    gra.camera.originy-= gra.camera.focus;
                }
                if(event.key.code == int('a'-'a')){
                    gra.camera.originx+= gra.camera.focus;
                }
                if(event.key.code == int('d'-'a')){
                    gra.camera.originx-= gra.camera.focus;
                }
                //std::cout<<"Pressed: "<<event.key.code<<"\n";
            }
            if(event.type == Event::KeyReleased){
                //std::cout<<"Released: "<<event.key.code<<"\n";
            }
            if(event.type == Event::MouseMoved){
                //std::cout<<"MouseMoved: "<<event.mouseMove.x<<","<<event.mouseMove.y<<"\n";
                //int x = event.mouseMove.x;
                //int y = event.mouseMove.y;
               
            }
            if(event.type == Event::MouseButtonPressed){
                gra.dragState = true;
                gra.first_click = gra.camera.transformBack(Vector2f(event.mouseButton.x,event.mouseButton.y));
                std::cout<<"Event::MouseButtonPressed\n";
            }
            if(event.type == Event::MouseButtonReleased){
                gra.dragState = false;
                gra.endDrag(event);
            }
        }
        static float f = 0.0;
        f+=0.01;
        window.clear(Color(100+100*sin(f),100,180));
        gra.onTick();
        gra.drawScene(window);
        window.display();
    }
}