#include"Libs/glew.h"
#include"Libs/glut.h"
#include<Windows.h>

void glut_loop() {
	glClearColor(1, 0.2, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Denise ist doof");
	glewInit();

	glutDisplayFunc(glut_loop);
	glutIdleFunc(glut_loop);
	glutMainLoop();
}