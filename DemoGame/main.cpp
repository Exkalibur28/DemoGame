#include"Libs/glew.h"
#include"Libs/glut.h"
#include"simple_quad_mesh.h"
#include"timer.h"
#include<Windows.h>
#include<iostream>

using namespace std;

quad_mesh* q;
camera cam = camera(16, 9);
matrix4x4 model;

void glut_loop() {
	glClearColor(1, 0.2, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	q->draw(model,cam.get_mat());
	glutSwapBuffers();
}

void glut_keyinput(unsigned char key, int x, int y)
{
	cout << "Key: '" << key << "', x: " << x << ", y: " << y << "\n";
}

void glut_mouseinput(int button, int state, int x, int y)
{
	cout << "Button: " << button << ", State: " << state << ", x: " << x << ", y: " << y << "\n";
}

void glut_mousemotion(int x, int y)
{
	cout << "x: " << x << ", y: " << y << "\n";
}

void glut_passivemousemotion(int x, int y)
{
	cout << "x: " << x << ", y: " << y << "\n";
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
	glutKeyboardFunc(glut_keyinput);
	glutMouseFunc(glut_mouseinput);
	glutMotionFunc(glut_mousemotion);
	glutPassiveMotionFunc(glut_passivemousemotion);
	glutMainLoop();
	delete q;
}