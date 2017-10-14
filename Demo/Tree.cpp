#include <iostream>
#include "tree.h"

using namespace std;

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

void DrawTreeInstance(GLfloat base, GLfloat height);
extern GLUquadric* quadric;

/*----------------------------------------------------------------------------------------------------------*/
GLuint dlTree = -1, dlLeaves = -1;
float x, y, z;
int i = -1;

GLint level = 0, maxLevels = 0, nBranches = 0;
GLfloat baseStart = 0.3f, heightStart = 3.0f;

GLfloat baseDrop = 0.6f;   /* drop in the branch thickness */
GLfloat heightDrop = 0.68f;  /* drop in the branch height    */
GLfloat endHeight = 0.3f;

TreeData* tdata;

GLuint texture;

/*----------------------------------------------------------------------------------------------------------*/
int LoadTexture(char* textureFile)
{
   GLvoid* image;
   int iRetVal = 0;
   int width, height;
   /* load an image file directly as a new OpenGL texture */
   image = SOIL_load_image
   (
      textureFile,
      &width,
      &height,
      0,
      SOIL_LOAD_RGB
   );

   if(image == NULL)
      return -1;

   glGenTextures(1, &texture);
   //glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, texture);

   // Typical Texture Generation Using Data From The Bitmap
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

   return 0;
}


/*----------------------------------------------------------------------------------------------------------*/
void DrawTexturedCylinder()
{
   int nPoints = 900;
   GLfloat radius = 0.98f;

   glColor3f(1.0, 1.0, 1.0);
   glPushMatrix();
   glTranslatef(0.0, 0.5, 0.0);
   glRotatef(90.0, 1.0, 0.0, 0.0);
   for(float z = 0.0f; z < 1.0f; z += 0.0004f) {
      glBegin(GL_POINTS);
      for(int i = 0; i < nPoints; i++) {
         glTexCoord2f(1.0 - z, i * 1.0f / nPoints);
         glVertex3f(cos(2 * M_PI * i / nPoints) * radius, sin(2 * M_PI * i / nPoints) * radius, z);
      }
      glEnd();
   }
   glPopMatrix();
}

/*----------------------------------------------------------------------------------------------------------*/
bool ReadTreeData()
{
	FILE* fp;
	fopen_s(&fp, "tree.dat", "r");
   
   if(!fp)
      return false;

   /* get the number of data lines in the file */
   char line[1024];
   int lineCount = 0;
   while(!feof(fp)) {
      fgets(line, 1024, fp);
      lineCount++;
   }

   /* allocate and read the data in */
   if(lineCount > 0)
      tdata = new TreeData[lineCount];
   else {
      fclose(fp);
      return false;
   }

   int i = 0;
   rewind(fp);
   while(!feof(fp)) {
      fscanf_s(fp, "%f,%f,%f,%f\n", &tdata[i].angle, &tdata[i].x, &tdata[i].y, &tdata[i].z);
      i++;
   }

   assert(i == (lineCount - 1));
   fclose(fp);

   return true;
}

/*----------------------------------------------------------------------------------------------------------*/
GLdouble random(GLfloat lower = 0.0, GLfloat upper = 1.0)
{
   return (((double) rand() / RAND_MAX) * (upper - lower)) + lower;
}

/*----------------------------------------------------------------------------------------------------------*/
void GenerateTree()
{
   level = 0;
   i = -1;
   glDeleteLists(dlTree, 1);

   dlTree = glGenLists(1);
   glNewList(dlTree, GL_COMPILE);

   //DrawTexturedCylinder();

   DrawTreeInstance(baseStart, heightStart);

   glEndList();
}

/*----------------------------------------------------------------------------------------------------------*/
void DrawTree()
{
   glCallList(dlTree);
}

/*----------------------------------------------------------------------------------------------------------*/
void ChooseLeafColor()
{
   static GLfloat color[3];
   static int i;

   int iOption = rand() % 3;

   switch(iOption) {
   case 0:
      color[0] = 30.0f;
      color[1] = 147.0f;
      color[2] = 45.0f;
      break;

   case 1:
      color[0] = 103.0f;
      color[1] = 148.0f;
      color[2] = 30.0f;
      break;

   case 2:
      color[0] = 34.0f;
      color[1] = 139.0f;
      color[2] = 34.0f;
      break;
   }

   for(i = 0; i < 3; i++)
      color[i] /= 255.0f;

   glColor3f(color[0], color[1], color[2]);
}

/*----------------------------------------------------------------------------------------------------------*/
void DrawParambi()
{
   glColor3f(85 / 255.0, 53 / 255.0, 10 / 255.0);
   glPushMatrix();
   glLoadIdentity();
   glRotatef(90.0f, 0.0, 0.0, 1.0);
   gluCylinder(quadric, 0.001, 0.001, 6.5, 15, 15);
   glPopMatrix();
}


/*----------------------------------------------------------------------------------------------------------*/
void DrawBranch(GLfloat base, GLfloat height)
{
   glColor3f(85 / 255.0, 53 / 255.0, 10 / 255.0);
   glPushMatrix();
   glRotatef(-90.0f, 1.0, 0.0, 0.0);
   gluCylinder(quadric, base, base * baseDrop, height, 15, 15);
   glPopMatrix();
}

/*----------------------------------------------------------------------------------------------------------*/
void DrawLeafPair(GLfloat offset)
{
   glPushMatrix();
   ChooseLeafColor();
   glPushMatrix();
   glRotatef(-90.0f, 0.0, 0.0, 1.0);
   glTranslatef(offset, 0.01f, 0.0f);
   glRotatef(rand() % 90, 0.0, 1.0, 0.0);
   glScalef(1.0f, 2.6f, 0.25f);
   gluSphere(quadric, 0.05f, 15, 15);
   glPopMatrix();

   ChooseLeafColor();
   glPushMatrix();
   glRotatef(-90.0f, 0.0, 0.0, 1.0);
   glTranslatef(offset, -0.01f, 0.0f);
   glRotatef(-(rand() % 90), 0.0, 1.0, 0.0);
   glScalef(1.0f, 2.6f, 0.25f);
   gluSphere(quadric, 0.05f, 15, 15);
   glPopMatrix();

   glPopMatrix();
}

/*----------------------------------------------------------------------------------------------------------*/
void DrawLeaves()
{
   glDeleteLists(dlLeaves, 1);
   dlLeaves = glGenLists(1);
   glNewList(dlLeaves, GL_COMPILE);
      for(GLfloat i=0.0f; i<1.5f; i += 1.5f)
         DrawLeafPair(i);
   glEndList();
}

/*----------------------------------------------------------------------------------------------------------*/
void DrawTreeInstance(GLfloat base, GLfloat height)
{
   i++;
   if(i > nBranches)
      return;

   level = log(base / baseStart) / (log(baseDrop));

   DrawBranch(base, height);
   glTranslatef(0.0f, height, 0.0f);

   GLfloat angle;
   int end = (level == 0) ? 3 : 3;
   for(int a = 0; a < end; a++) {
      angle = tdata[i].angle;

      if(height > endHeight) {
         glPushMatrix();

         GLfloat x = tdata[i].x, y = tdata[i].y, z = tdata[i].z;
         glRotatef(angle, x, y, z);

         if(level == 0)
            glRotatef(-90.0, 0.0f, 0.0f, 1.0f);

         DrawTreeInstance(base * baseDrop, height * heightDrop);
         glPopMatrix();
      }
      else {
         glCallList(dlLeaves);
      }
   }
}
