#pragma once
#include <SDL.h>
#ifndef domain_base_h
#define domain_base_h

enum modeType {IN, OUT, T_IN, T_OUT, NONE};

class domain_base {
public:
	void setup(int x, int y, int w, int h, int mode);
	void setXY(int x, int y);
	void move(int x, int y);
	void restrictIn(SDL_Rect rect, int *deltaX, int *deltaY);
	void restrictOut(SDL_Rect *rect);
	void restrictTeleportIn(SDL_Rect *rect);
	void restrictTeleportOut(SDL_Rect *rect);
	void restrictBounceIn(SDL_Rect rect);
	void restrictBounceOut(SDL_Rect rect);
	int restrictMode;
	SDL_Rect dstrect;
};
#endif