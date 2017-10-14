#ifndef TREE_H
#define TREE_H
#include <windows.h>

#include <gl/GL.h>
#include <gl/GLU.h>
#include <assert.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <SOIL.h>

#define IMAGE_NAME "stone.jpg"

/*----------------------------------------------------------------------------------------------------------*/
void GenerateTree();
void DrawTree();
void DrawLeaves();
int LoadTexture(char* textureFile);
bool ReadTreeData();

typedef struct
{
   GLfloat angle;
   GLfloat x;
   GLfloat y;
   GLfloat z;
} TreeData;

#endif
