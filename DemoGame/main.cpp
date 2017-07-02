#include"Libs/glew.h"
#include"Libs/glut.h"
#include"simple_quad_mesh.h"
#include"timer.h"
#include"key_memorizer.h"
#include<Windows.h>
#include<iostream>

using namespace std;


timer cam_timer;

quad_mesh *q , *g;
/*
Debug Kamera; Steuerung mit WASD
*/
camera cam = camera(16, 9);
matrix4x4 model;

void update_camera() {
	int i = cam_timer.look();
	float x = cam.get_x();
	float y = cam.get_y();
	if(mem_key_state('d'))
		x += ((float)i)/300;
	if (mem_key_state('a'))
		x -= ((float)i) / 300;
	if (mem_key_state('w'))
		y += ((float)i) / 300;
	if (mem_key_state('s'))
		y -= ((float)i) / 300;
	cam.set_pos(x,y);
	cam_timer.restart();
}

void glut_loop() {
	update_camera();
	glClearColor(0.75, 0.75, 0.85, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	q->draw(model,cam.get_mat());
	g->draw(model, cam.get_mat());
	glutSwapBuffers();
}

void glut_keyinput(unsigned char key, int x, int y)
{
	mem_key_event(key, true);
	cout << "Key: '" << key << "', x: " << x << ", y: " << y << "\n";
}

void glut_keyup(unsigned char key, int x, int y)
{
	mem_key_event(key, false);
	cout << "Key: '" << key << "', x: " << x << ", y: " << y << " up \n";
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
	g = new quad_mesh(point(-100, -1), point(-100, -0.5), point(100, -0.5), point(100, -1));
	q->set_color(0,1,0,1);
	g->set_color(0.2, 0.2, 0.2, 1);

	glutDisplayFunc(glut_loop);
	glutIdleFunc(glut_loop);
	glutKeyboardFunc(glut_keyinput);
	glutKeyboardUpFunc(glut_keyup);
	glutMouseFunc(glut_mouseinput);
	glutMotionFunc(glut_mousemotion);
	glutPassiveMotionFunc(glut_passivemousemotion);
	cam_timer.start();
	glutMainLoop();
	delete q;
}