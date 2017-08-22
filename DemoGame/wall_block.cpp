#include "wall_block.h"
#include "player.h"

static const float hr = 1.0, hg = 0.0, hb = 0.0, ha = 1.0;
static const float sr = 0.0, sg = 1.0, sb = 0.0, sa = 1.0;

wall_block::wall_block(point p1, point p2, point p3, point p4)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
}

void wall_block::render(matrix4x4 view)
{
	quad_mesh* quad = new quad_mesh(p1, p2, p3, p4);
	quad->set_color(r, g, b, a);
	quad->draw(view);
}

bool wall_block::checkCollision(player pl)
{
	
	return false;
}

void wall_block::set_color(float r, float g, float b, float a)
{
	this->r;
	this->g;
	this->b;
	this->a;
}