#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

uniform mat4 pr_matrix = mat4(1.0);
uniform mat4 tr_matrix = mat4(1.0);

out vec4 aColor;

void main(){
	gl_Position = tr_matrix * pr_matrix * vec4(aPos, 1);
	aColor = color;
}