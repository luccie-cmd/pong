#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include "render.h"
#include "types.h"
#include "keys.h"
#include "check.h"
#include "settings.h"

class Paddle {
    public:
        Paddle(vec4f xywh, SDL_Texture* texture) {
            Paddle::x = xywh.getX();
            Paddle::y = xywh.getY();
            Paddle::w = xywh.getW();
            Paddle::h = xywh.getH();
            Paddle::pos = xywh;            
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
            this->Draw(renderer);
        }
        void Handle_Key_Press(key key, bool left){
            if (left){
                if(key == KEY_W){
                    std::cout << Ceiling_Collision(pos) << std::endl;;
                    this->setY(this->y - PLAYER_SPEED);
                }
                else if(key == KEY_S){
                    this->setY(this->y + PLAYER_SPEED);
                }
            }
            else if(!left) {
                if(key == KEY_UP){
                    this->setY(this->y - PLAYER_SPEED);
                }
                else if(key == KEY_DOWN){
                    this->setY(this->y + PLAYER_SPEED);
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
            if(this->texture == NULL) {
                Render_Rect(renderer, this->x, this->y, this->w, this->h, this->color);
            }
            else{
                Render_Texture(this->texture, renderer, vec2f(this->x, this->y));
            }
        }
        void setY(float y){
            Paddle::y = y;
        }
        SDL_Texture* texture;
        SDL_Color color;
        float x, y;
        float w, h;
        vec4f pos;
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