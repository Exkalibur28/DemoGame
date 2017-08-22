#pragma once

#include "simple_quad_mesh.h"
#include "player.h"

class wall_block
{
public:
	wall_block(point p1, point p2, point p3, point p4);
	void render(matrix4x4 view);
	bool checkCollision(player pl);
	void set_color(float r, float g, float b, float a);
private:
	point p1, p2, p3, p4;
	float r, g, b, a;
};