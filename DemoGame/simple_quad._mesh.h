#pragma once

#include<utility>
#include"Libs/glew.h"
#include"Libs/glut.h"

typedef std::pair<float, float> point;

class quad_mesh {
public:
	quad_mesh(point a, point b, point c, point d);
	void set_color(float r, float g, float b, float a);
	void draw();

private:
	float r, g, b, a;
	GLuint vb, vao;
};