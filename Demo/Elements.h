#ifndef _Elements_h
#define _Elements_h
#pragma once

typedef struct _position
{
	float x;
	float y;
	float z;
} POSITION;

typedef struct _color
{
	float r;
	float g;
	float b;
} EL_COLOR;

void drawMedicalIcon(POSITION position, EL_COLOR color);
void drawDramaIcon(POSITION position, EL_COLOR color);
void drawAstroIcon(POSITION position, EL_COLOR color);
void drawTeacherIcon(POSITION position, EL_COLOR color);
void drawWin32Icon(POSITION position, EL_COLOR color);
void drawUnixIcon(POSITION position, EL_COLOR color);
void drawAppleIcon(POSITION position, EL_COLOR color);
void drawiOSIcon(POSITION position, EL_COLOR color);
void drawAndroidIcon(POSITION position, EL_COLOR color);
void drawOpenGlIcon(POSITION position, EL_COLOR color);
void drawCUDAIcon(POSITION position, EL_COLOR color);
void drawARMIcon(POSITION position, EL_COLOR color);

void DrawElements(void);

#endif // !_Elements_h