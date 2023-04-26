#include "render.h"

int Render_Rect(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return 0;
}
float Render_Rect(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return 0.0;
}
int Render_Line(SDL_Renderer* renderer, Vec2f start, Vec2f end){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, start.getX(), start.getY(), end.getX(), end.getY());
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return 0;
}
void Render_Texture(SDL_Texture* texture, SDL_Renderer* renderer, Vec2f xy){
    int x, y, w, h;
    x = xy.getX(), y = xy.getY();
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect src = {
        0, 0, w, h
    };
    SDL_Rect dst = {
        x, y, w, h
    };
    SDL_RenderCopy(renderer, texture, &src, &dst);
}