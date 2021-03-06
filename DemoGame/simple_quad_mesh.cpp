#include"simple_quad_mesh.h"
#include"shader_loader.h"
#include<iostream>

static GLuint shader = -1;

static void init_shader() {
	if (shader == -1) {
		shader = LoadShaders("Shader/simple_quad_shader_vert.glsl", "Shader/simple_quad_shader_frag.glsl");
	}
}

quad_mesh::quad_mesh(point a, point b, point c, point d) {
	init_shader();
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	float vb_data[8];
	vb_data[0] = a.first;
	vb_data[1] = a.second;
	vb_data[2] = b.first;
	vb_data[3] = b.second;
	vb_data[4] = c.first;
	vb_data[5] = c.second;
	vb_data[6] = d.first;
	vb_data[7] = d.second;
	glBufferData(GL_ARRAY_BUFFER, sizeof(vb_data), vb_data, GL_DYNAMIC_DRAW);
	glGenBuffers(1, &vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao);
	unsigned int vao_data[] = { 1,0,2,3 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vao_data), vao_data, GL_DYNAMIC_DRAW);
	this->r = 1;
	this->g = 1;
	this->b = 0;
	this->a = 1;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void quad_mesh::set_color(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void quad_mesh::draw(matrix4x4 model , matrix4x4 view) {
	int loc = glGetUniformLocation(shader, "vert_col");
	glUniform4f(loc, this->r, this->g, this->b, this->a);
	using namespace std;
	loc = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(loc,1,false,model.get_data());
	loc = glGetUniformLocation(shader, "view");
	glUniformMatrix4fv(loc, 1, false, view.get_data());
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vao);
	glUseProgram(shader);
	//glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glDrawElements(GL_TRIANGLE_STRIP,4,GL_UNSIGNED_INT,NULL);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

quad_mesh::~quad_mesh() {
	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &vb);
}