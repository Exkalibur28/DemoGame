#pragma once

#include "wall_block.h"
#include <vector>

class level
{
public:
	level(std::vector<wall_block> walls, point spawn);
	void render(matrix4x4 view);
	void update(int tickDelta);
	~level();
private:
	std::vector<wall_block> walls;
	player* pl;
	float sr, sg, sb, sa;
};