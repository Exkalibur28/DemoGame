#include "player.h"
#include "key_memorizer.h"

static const float width = 20;
static const float speed = 20;

player::player(float x, float y)
{
	this->x = x;
	this->y = y;
	quad = quad_mesh(point(-width / 2, -width / 2), point(width / 2, -width / 2), point(width / 2, width / 2), point(-width / 2, width / 2));
}

void player::render(matrix4x4 view)
{
	matrix4x4 m;
	m.row_col(0, 3) = x;
	m.row_col(1, 3) = y;
	quad.draw(m, view);
}

void player::update(int tickDelta)
{
	float velX = 0, velY = 0;
	if (mem_key_state('j'))
	{
		velX -= speed;
	}
	if (mem_key_state('l'))
	{
		velX += speed;
	}
	if (mem_key_state('i'))
	{
		velY -= speed;
	}
	if (mem_key_state('k'))
	{
		velY += speed;
	}
	x += (velX / 1000) * (float)tickDelta;
	y += (velY / 1000) * (float)tickDelta;
}