#pragma once
#include"rendering_utilities.h"

class mesh {
public:
	virtual void draw(matrix4x4 model = matrix4x4(), matrix4x4 view = matrix4x4()) {}
	virtual ~mesh() {}
};