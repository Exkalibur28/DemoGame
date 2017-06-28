#pragma once
#include "Libs/glew.h"
#include "Libs/glut.h"


/*
Lädt und linkt ein Shaderprogramm.
*/
GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
