#include <iostream>
#include "types.h"
#include "settings.h"

bool Collision(vec4f pos1, vec4f pos2){
    float a_x, a_y, b_x, b_y, a_width, a_height, b_width, b_height;
    a_x = pos1.getX();
    a_y = pos1.getY();
    a_width = pos1.getW();
    a_height = pos1.getH();
    b_x = pos2.getX();
    b_y = pos2.getY();
    b_width = pos2.getW();
    b_height = pos2.getH();
    std::cout << a_x << " " << a_y << " " << a_width << " " << a_height << " " << b_x << " " << b_y << " " << b_width << " " << b_height << " " << std::endl;
    return (a_x + a_width > b_x) && (a_x < b_x + b_width) && (a_y + a_height > b_y) && (a_y < b_y + b_height);
}
bool Ceiling_Collision(vec4f pos){
    float a_x, a_y, a_width, a_height;
    a_x = pos.getX();
    a_y = pos.getY();
    a_width = pos.getW();
    a_height = pos.getH();
    std::cout << true << std::endl;
    if(a_y <= 0){
        return true;
    }
    if(a_x <= 0){
        return true;
    }
    if(a_x + a_width >= WINDOW_WIDTH){
        return true;
    }
    if(a_y + a_height >= WINDOW_HEIGHT){
        return true;
    }
    return false;
}