#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

extern GLUquadric* quadric;

enum customColor { red, blue, green, yellow, white, purple, cyan, brown, gray, orange, black };
void customGlColor3f(customColor color);
void drawBoy(GLfloat x, GLfloat y, GLfloat z, customColor shirtColor, customColor pantColor);
void drawGirl(GLfloat x, GLfloat y, GLfloat z, customColor shirtColor, customColor pantColor);