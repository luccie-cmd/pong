#ifndef _TYPES_H
#define _TYPES_H
#pragma once

class Vec2f {
    public:
        Vec2f(float x, float y){
            Vec2f::x = x;
            Vec2f::y = y;
        }
        Vec2f(int x, int y){
            Vec2f::x = x;
            Vec2f::y = y;
        }
        Vec2f(){
            Vec2f::x = 0;
            Vec2f::y = 0;
        }
        float getX(){
            return Vec2f::x;
        }
        float getY(){
            return Vec2f::y;
        }
    private:
        float x, y;
};

///////////////////////////////

class Vec4f {
    public:
        Vec4f(float x, float y, float w, float h){
            Vec4f::x = x;
            Vec4f::y = y;
            Vec4f::w = w;
            Vec4f::h = h;
        }
        Vec4f(int x, int y, int w, int h){
            Vec4f::x = x;
            Vec4f::y = y;
            Vec4f::w = w;
            Vec4f::h = h;
        }
        Vec4f(){
            Vec4f::x = 0;
            Vec4f::y = 0;
            Vec4f::w = 0;
            Vec4f::h = 0;
        }
        float getX(){
            return Vec4f::x;
        }
        float getY(){
            return Vec4f::y;
        }
        float getW(){
            return Vec4f::w;
        }
        float getH(){
            return Vec4f::h;
        }
    private: 
        float x, y;
        float w, h;
};

///////////////////////////////

typedef Vec2f vec2f;
typedef Vec4f vec4f;
typedef Vec2f player_velocity;
typedef Vec2f player_speed;
typedef int key;

#endif // _TYPES_H