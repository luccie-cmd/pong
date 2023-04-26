#ifndef _TYPES_H
#define _TYPES_H
#pragma once

class Vec2f {
    public:
        Vec2f(float x, float y);
        Vec2f(int x, int y);
        Vec2f();
        float getX();
        float getY();
    private:
        float x, y;
};

///////////////////////////////

class Vec4f {
    public:
        Vec4f(float x, float y, float w, float h);
        Vec4f(int x, int y, int w, int h);
        Vec4f();
        float getX();
        float getY();
        float getW();
        float getH();
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