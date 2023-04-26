#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include "render.h"
#include "types.h"
#include "keys.h"
#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 150
#define PLAYER_OFFSET 30
#define PLAYER_SPEED 10
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class Paddle {
    public:
        Paddle(vec4f xywh, SDL_Texture* texture) {
            Paddle::x = xywh.getX();
            Paddle::y = xywh.getY();
            Paddle::w = xywh.getW();
            Paddle::h = xywh.getH();
            Paddle::texture = texture;
            Paddle::color = {0, 0, 0, 0};
        }
        Paddle(vec4f xywh, vec4f color){
            Paddle::x = xywh.getX();
            Paddle::y = xywh.getY();
            Paddle::w = xywh.getW();
            Paddle::h = xywh.getH();
            Paddle::texture = NULL;
            Paddle::SetColor(color);
        }
        void update(SDL_Renderer* renderer){
            Paddle::Draw(renderer);
        }
        void Handle_Key_Press(key key, bool left){
            if (left){
                switch(key){
                    case KEY_W: {
                        Paddle::setY(Paddle::y - PLAYER_SPEED);
                    } break;
                    case KEY_S: {
                        Paddle::setY(Paddle::y + PLAYER_SPEED);
                    } break;
                    default: {
                        std::cout << key << std::endl;
                        exit(1);
                    } break;
                }
            }
            else if(!left) {
                switch(key){
                    case KEY_W: break;
                    case KEY_S: break;
                    case SDLK_UP: {
                        Paddle::setY(Paddle::y - PLAYER_SPEED);
                    } break;
                    case SDLK_DOWN: {
                        Paddle::setY(Paddle::y + PLAYER_SPEED);
                    } break;
                    default: {
                        std::cout << key << std::endl;
                        exit(1);
                    } break;
                }
            }
        }
    private:
        void SetColor(vec4f color){
            Paddle::color.r = color.getX();
            Paddle::color.g = color.getY();
            Paddle::color.b = color.getW();
            Paddle::color.a = color.getH();
        }
        void Draw(SDL_Renderer* renderer){
            if(Paddle::texture == NULL) {
                Render_Rect(renderer, Paddle::x, Paddle::y, Paddle::w, Paddle::h, Paddle::color);
            }
            else{
                Render_Texture(Paddle::texture, renderer, vec2f(Paddle::x, Paddle::y));
            }
        }
        void setY(float y){
            Paddle::y = y;
        }
        SDL_Texture* texture;
        SDL_Color color;
        float x, y;
        float w, h;
        player_velocity velocity;
        player_speed speed;
};

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Paddle l_paddle(vec4f(PLAYER_OFFSET, ((WINDOW_HEIGHT/2)-(PLAYER_HEIGHT/2)), PLAYER_WIDTH, PLAYER_HEIGHT), vec4f(255, 0, 0, 255));
    Paddle r_paddle(vec4f(WINDOW_WIDTH-PLAYER_WIDTH-PLAYER_OFFSET, ((WINDOW_HEIGHT/2)-(PLAYER_HEIGHT/2)), PLAYER_WIDTH, PLAYER_HEIGHT), vec4f(0, 0, 255, 255));
    bool quit = false;
    while(!quit){
        SDL_Event evs;
        while(SDL_PollEvent(&evs)){
            switch(evs.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN: {
                    l_paddle.Handle_Key_Press(evs.key.keysym.sym, true);
                    r_paddle.Handle_Key_Press(evs.key.keysym.sym, false);
                } break;
            }
        }
        SDL_RenderClear(renderer);
        l_paddle.update(renderer);
        r_paddle.update(renderer);
        SDL_RenderPresent(renderer);
    }
    return 0;
}