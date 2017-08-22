#include "level.h"
#include "wall_block.h"
#include <vector>

level::level(std::vector<wall_block> walls, point spawn)
{
	this->walls = walls;
	pl = new player(spawn.first, spawn.second);
}

void level::render(matrix4x4 view)
{
	for (int i = 0; i < walls.size(); i++)
	{
		walls[i].render(view);
	}
	pl->render(view);
}

void level::update(int tickDelta)
{
	pl->update(tickDelta);
	for (int i = 0; i < walls.size(); i++)
	{
		if (walls[i].checkCollision(*pl))
		{

		}
	}
}

level::~level()
{
	delete pl;
}