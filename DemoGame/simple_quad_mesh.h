#pragma once

#include<utility>
#include"Libs/glew.h"
#include"Libs/glut.h"
#include"rednering_utilities.h"

typedef std::pair<float, float> point;

/*
Handhabt ein Viereck mit den Eckpunkten a,b,c,d.
model und view optional. (Zum direkten Rendern in View- & Modelspace)
*/

class quad_mesh {
public:
	quad_mesh(point a, point b, point c, point d);
	~quad_mesh();
	void set_color(float r, float g, float b, float a);
	void draw(matrix4x4 model = matrix4x4(), matrix4x4 view = matrix4x4());

private:
	float r, g, b, a;
	GLuint vb, vao;
};