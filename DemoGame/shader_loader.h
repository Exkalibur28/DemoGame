#pragma once
#include "Libs/glew.h"
#include "Libs/glut.h"


/*
L�dt und linkt ein Shaderprogramm.
*/
GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
