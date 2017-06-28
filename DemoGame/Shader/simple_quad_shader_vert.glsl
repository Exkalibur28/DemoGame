#version 330 core

layout(location = 0) in vec2 in_pos;

out vec4 vert_col;

uniform mat4 model, view;

void main(){
	gl_Position = view*model*vec4(in_pos,0.5,1);
}