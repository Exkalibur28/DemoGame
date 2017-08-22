#pragma once

#include "rendering_utilities.h"
#include "simple_quad_mesh.h"

class player
{
public:
	player(float x, float y);
	void update(int tickDelta);
	void render(matrix4x4 view = matrix4x4());

private:
	quad_mesh* quad = NULL;
	float x, y;
};