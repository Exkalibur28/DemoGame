#include "rendering_utilities.h"

matrix4x4::matrix4x4() {
	set_unity();
}

void matrix4x4::set_unity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) this->row_col(i, j) = 1;
			else this->row_col(i, j) = 0;
		}
	}
}

float& matrix4x4::row_col(unsigned int row, unsigned int col) {
	return data[row + col * 4];
}

const float* matrix4x4::get_data() {
	return this->data;
}

camera::camera(float width, float height) {
	this->width = width;
	this->height = height;
	this->posx = 0;
	this->posy = 0;
	build();
}

void camera::build() {
	float right = posx + width / 2;
	float left = posx - width / 2;
	float top = posy + height / 2;
	float bottom = posy - height / 2;
	float near = -1;
	float far = 1;
	mat.set_unity();
	mat.row_col(0,0) = 2 / (right-left);
	mat.row_col(1,1) = 2 / (top - bottom);
	mat.row_col(2, 2) = -2 / (far - near);
	mat.row_col(0, 3) = -(right + left) / (right - left);
	mat.row_col(1, 3) = -(top + bottom) / (top - bottom);
	mat.row_col(2, 3) = -(far + near) / (far - near);
}

matrix4x4 camera::get_mat() {
	return mat;
}

void camera::set_pos(float x, float y) {
	this->posx = x;
	this->posy = y;
	build();
}

float camera::get_x() {
	return this->posx;
}

float camera::get_y() {
	return this->posy;
}