#include "types.h"

Vec2f::Vec2f(float x, float y){
    Vec2f::x = x;
    Vec2f::y = y;
}
Vec2f::Vec2f(int x, int y){
    Vec2f::x = x;
    Vec2f::y = y;
}
Vec2f::Vec2f(){
    Vec2f::x = 0;
    Vec2f::y = 0;
}
float Vec2f::getX(){
    return this->x;
}
float Vec2f::getY(){
    return this->y;
}

Vec4f::Vec4f(float x, float y, float w, float h){
    Vec4f::x = x;
    Vec4f::y = y;
    Vec4f::w = w;
    Vec4f::h = h;
}
Vec4f::Vec4f(int x, int y, int w, int h){
    Vec4f::x = x;
    Vec4f::y = y;
    Vec4f::w = w;
    Vec4f::h = h;
}
Vec4f::Vec4f(){
    Vec4f::x = 0;
    Vec4f::y = 0;
    Vec4f::w = 0;
    Vec4f::h = 0;
}
float Vec4f::getX(){
    return this->x;
}
float Vec4f::getY(){
    return this->y;
}
float Vec4f::getW(){
    return this->w;
}
float Vec4f::getH(){
    return this->h;
}