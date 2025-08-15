#include "all.hpp"
using namespace sf;
using namespace std;

Game::Game(){
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            tileColor[i][j] = Color(rand()%255,rand()%255,rand()%255,100);
        }
    }
    dragState = false;
}
void Game::drawScene(RenderWindow &window){
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
        vec3 second_click = camera.transformBack(Vector2f(Mouse::getPosition(window).x,Mouse::getPosition(window).y));
        //std::cout<<first_click.x<<","<<first_click.y<<","<<second_click.x<<","<<second_click.y<<"\n";
        quad[0].position = camera.transform(vec3(first_click.x*1.0  ,  first_click.y *1.0,0.0));
        quad[1].position = camera.transform(vec3(second_click.x*1.0 , first_click.y*1.0,0.0 ));
        quad[2].position = camera.transform(vec3(first_click.x *1.0 , second_click.y*1.0,0.0));
        quad[3].position = camera.transform(vec3(second_click.x *1.0 ,  second_click.y*1.0,0.0));
        quad[0].color = quad[1].color = quad[2].color = quad[3].color = Color(0,0,255,125);
        window.draw(quad);

    }
}
void Game::endDrag(Event &event){
    vec3 second_click = camera.transformBack(Vector2f(event.mouseButton.x,event.mouseButton.y));
    for(int i = max(0,(int)min(first_click.x,second_click.x)); i <= min(MAX_N-1, (int)max(first_click.x,second_click.x)); i++){
        for(int j = max(0,(int)min(first_click.y,second_click.y)); j <= min(MAX_N-1, (int)max(first_click.y,second_click.y)); j++){
            tileColor[i][j] = Color(0,0,80,125);

        }
    }
}