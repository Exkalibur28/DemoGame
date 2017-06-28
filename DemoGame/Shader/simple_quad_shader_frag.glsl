#version 330 core

uniform vec4 vert_col;

out vec4 color;

void main(){
	color = vert_col;
}