#include <SDL.h>
#include "laser_classes.h"
#include "../../engine/textures.h"
#include "../../engine/constants.h"
#include <iostream>

enum status {STOPPED, MOVING, COLLISION};

void standardLaser::initialize() {
	laser.setup(0, 0, 16, 32, laserSpritesheet_texture);

	laser.defFrame(0, 0, 160, 320, &moveCycle[0].srcrect);
	laser.defFrame(160, 0, 160, 320, &moveCycle[1].srcrect);
	laser.defFrame(320, 0, 160, 320, &moveCycle[2].srcrect);

	laser.rotate(90);

	copyRect(moveCycle[0].srcrect, &currentSRCRECT.srcrect);

	state = STOPPED;
}

void standardLaser::render(SDL_Renderer *renderer) {
	laser.render(renderer, &currentSRCRECT.srcrect);
}

void standardLaser::updateStates() {
	switch (state) {
	case STOPPED:
		break;
	case MOVING:
		copyRect(moveCycle[rand() % 3].srcrect, &currentSRCRECT.srcrect);
		break;
	case COLLISION:
		break;
	}
}

void standardLaser::update() {
	laser.move(&laser.movement.deltaX, &laser.movement.deltaY);

	state = MOVING;

	updateStates();
}