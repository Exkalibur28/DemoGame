#version 330 core

layout(location = 0) in vec2 in_pos;

out vec4 vert_col;

void main(){
	gl_Position = vec4(in_pos,0.5,1);
}