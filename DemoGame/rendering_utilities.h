#pragma once

/*
Mag wer sinnvolle(*, ==) Overloads bauen?
get_data() nur zum Export in openGl verwenden!
Schreiben/lesen ausschlie�lich �ber row_col! 
*/
class matrix4x4 {
public:
	matrix4x4();
	const float* get_data();
	float& row_col(unsigned int row, unsigned int col);
	void set_unity();
private:
	float data[16];
};

/*
Die Kamera mappt ihren Sichtbereich orthographisch auf [-1,1]. 
Die Mitte des Sichtbereichs liegt bei pos.
near = -1, far = 1
*/
class camera {
public:
	camera(float width, float height);
	void set_pos(float x, float y);
	matrix4x4 get_mat();
private:
	void build();
	float width, height, posx, posy;
	matrix4x4 mat;
};
