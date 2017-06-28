#include"Libs/glew.h"
#include"Libs/glut.h"
#include"simple_quad._mesh.h"
#include<Windows.h>

quad_mesh* q;

void glut_loop() {
	glClearColor(1, 0.2, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	q->draw();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Denise ist doof");
	glewInit();

	q = new quad_mesh(point(-0.5, -0.5), point(-0.5, 0.5), point(0.5, 0.5), point(0.5, -0.5));
	q->set_color(0,1,0,1);

	glutDisplayFunc(glut_loop);
	glutIdleFunc(glut_loop);
	glutMainLoop();
	delete q;
}