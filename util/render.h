#ifndef _RENDER_H
#define _RENDER_H
#pragma once

#include <iostream>
#include <SDL.h>
#include "types.h"

int Render_Rect(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color);
float Render_Rect(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Color color);
int Render_Line(SDL_Renderer* renderer, Vec2f start, Vec2f end);
void Render_Texture(SDL_Texture* texture, SDL_Renderer* renderer, Vec2f xy);

#endif // _RENDER_H