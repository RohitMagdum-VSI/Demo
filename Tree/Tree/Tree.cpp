#include <iostream>
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <assert.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <SOIL.h>

using namespace std;

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#define IMAGE_NAME "../images/stone.jpg"

/*----------------------------------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void display(void);
void DrawTree(GLfloat base, GLfloat height);
void DrawBranch(GLfloat base, GLfloat height);
void DrawLeaves();
void ChooseLeafColor();

/*----------------------------------------------------------------------------------------------------------*/
//Global variable declarations
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = {sizeof(WINDOWPLACEMENT)};

bool gbActiveWindow = false;
bool gbEscapeKeyIsPressed = false;
bool gbFullscreen = false;

GLUquadric* quadric = NULL;
GLfloat angle, sceneAngle = 360.0f;

GLuint dlTree = -1, dlLeaves = -1;
float x, y, z;
int i = -1;

GLint level = 0, maxLevels = 0, nBranches = 9000;
GLfloat baseStart = 0.3f, heightStart = 3.0f;

GLfloat baseDrop   = 0.6f;   /* drop in the branch thickness */
GLfloat heightDrop = 0.68f;  /* drop in the branch height    */
GLfloat endHeight  = 0.3f;

typedef struct
{
   GLfloat angle;
   GLfloat x;
   GLfloat y;
   GLfloat z;
} TreeData;

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
   FILE* fp = fopen("C:/tree.dat", "r");
   
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
      fscanf(fp, "%f,%f,%f,%f\n", &tdata[i].angle, &tdata[i].x, &tdata[i].y, &tdata[i].z);
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
void DisplayListRefresh()
{
   level = 0;
   i = -1;
   glDeleteLists(dlTree, 1);

   dlTree = glGenLists(1);
   glNewList(dlTree, GL_COMPILE);

   DrawTexturedCylinder();

   DrawTree(baseStart, heightStart);

   glEndList();
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
void DrawTree(GLfloat base, GLfloat height)
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

         DrawTree(base * baseDrop, height * heightDrop);
         glPopMatrix();
      }
      else {
         glCallList(dlLeaves);
      }
   }
}

/*----------------------------------------------------------------------------------------------------------*/
void IncrementAngle()
{
   sceneAngle += 0.9f;
   if(sceneAngle > 360.0f)
      sceneAngle = 0.0f;
}

/*----------------------------------------------------------------------------------------------------------*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
   //function prototype
   void initialize(void);
   void uninitialize(void);

   //variable declaration
   WNDCLASSEX wndclass;
   HWND hwnd;
   MSG msg;
   TCHAR szClassName[] = TEXT("RTROGL");
   bool bDone = false;

   //code
   //initializing members of struct WNDCLASSEX
   wndclass.cbSize = sizeof(WNDCLASSEX);
   wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
   wndclass.cbClsExtra = 0;
   wndclass.cbWndExtra = 0;
   wndclass.hInstance = hInstance;
   wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
   wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
   wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
   wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
   wndclass.lpfnWndProc = WndProc;
   wndclass.lpszClassName = szClassName;
   wndclass.lpszMenuName = NULL;

   //Registering Class
   RegisterClassEx(&wndclass);

   //Create Window
   hwnd = CreateWindowEx(WS_EX_APPWINDOW,
                         szClassName,
                         TEXT("Sachin Chaudhary (ID: 38): Tree"),
                         WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
                         0,
                         0,
                         WIN_WIDTH,
                         WIN_HEIGHT,
                         NULL,
                         NULL,
                         hInstance,
                         NULL);

   ghwnd = hwnd;

   //initialize
   initialize();

   ShowWindow(hwnd, SW_SHOW);
   SetForegroundWindow(hwnd);
   SetFocus(hwnd);

   //Message Loop
   while(bDone == false) {
      if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
         if(msg.message == WM_QUIT)
            bDone = true;
         else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
         }
      }
      else {
         // GAME LOOP
         if(gbActiveWindow == true) {
            if(gbEscapeKeyIsPressed == true)
               bDone = true;

            // render the scene
            display();

            IncrementAngle();
         }
      }
   }

   uninitialize();

   return((int) msg.wParam);
}

/*----------------------------------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
   //function prototype
   void resize(int, int);
   void ToggleFullscreen(void);
   void uninitialize(void);

   //code
   switch(iMsg) {
   case WM_ACTIVATE:
      if(HIWORD(wParam) == 0)
         gbActiveWindow = true;
      else
         gbActiveWindow = false;
      break;

      //case WM_ERASEBKGND:
      //	return(0);

   case WM_SIZE:
      resize(LOWORD(lParam), HIWORD(lParam));
      break;

   case WM_CHAR:
      switch(wParam) {
      case VK_ESCAPE:
         gbEscapeKeyIsPressed = true;
         break;

      case 'f':
      case 'F':
         if(gbFullscreen == false) {
            ToggleFullscreen();
            gbFullscreen = true;
         }
         else {
            ToggleFullscreen();
            gbFullscreen = false;
         }
         break;

      case 'B':
         nBranches--;
         if(nBranches < 0)
            nBranches = 0;
         DisplayListRefresh();
         break;

      case 'b':
         nBranches++;
         if(nBranches > 9555)
            nBranches = 9555;
         DisplayListRefresh();
         break;

      default:
         break;
      }
      break;

   case WM_LBUTTONDOWN:
      break;

   case WM_DESTROY:
      PostQuitMessage(0);
      break;

   default:
      break;
   }

   return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

/*----------------------------------------------------------------------------------------------------------*/
void ToggleFullscreen(void)
{
   //variable declarations
   MONITORINFO mi;

   //code
   if(gbFullscreen == false) {
      dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
      if(dwStyle & WS_OVERLAPPEDWINDOW) {
         mi = {sizeof(MONITORINFO)};
         if(GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi)) {
            SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
            SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
         }
      }
      ShowCursor(FALSE);
   }

   else {
      //code
      SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
      SetWindowPlacement(ghwnd, &wpPrev);
      SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

      ShowCursor(TRUE);
   }
}

/*----------------------------------------------------------------------------------------------------------*/
void SetProjectionMatrix(GLfloat w, GLfloat h)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   gluPerspective(45.0f, (w / h), 0.1f, 100.0f);
}

/*----------------------------------------------------------------------------------------------------------*/
void initialize(void)
{
   //function prototypes
   void resize(int, int);

   if(!ReadTreeData()) {
      /* issue warning and exit */
      printf("Unable to read the data from the specified file");
      /*exit(0);*/
   }

   //variable declarations
   PIXELFORMATDESCRIPTOR pfd;
   int iPixelFormatIndex;

   //code
   ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

   //Initialization of structure 'PIXELFORMATDESCRIPTOR'
   pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
   pfd.nVersion = 1;
   pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
   pfd.iPixelType = PFD_TYPE_RGBA;
   pfd.cColorBits = 32;
   pfd.cRedBits = 8;
   pfd.cGreenBits = 8;
   pfd.cBlueBits = 8;
   pfd.cAlphaBits = 8;
   pfd.cDepthBits = 32;

   ghdc = GetDC(ghwnd);

   iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
   if(iPixelFormatIndex == 0) {
      ReleaseDC(ghwnd, ghdc);
      ghdc = NULL;
   }

   if(SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE) {
      ReleaseDC(ghwnd, ghdc);
      ghdc = NULL;
   }

   ghrc = wglCreateContext(ghdc);
   if(ghrc == NULL) {
      ReleaseDC(ghwnd, ghdc);
      ghdc = NULL;
   }

   if(wglMakeCurrent(ghdc, ghrc) == FALSE) {
      wglDeleteContext(ghrc);
      ghrc = NULL;
      ReleaseDC(ghwnd, ghdc);
      ghdc = NULL;
   }

   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);

   SetProjectionMatrix(WIN_WIDTH, WIN_HEIGHT);

   quadric = gluNewQuadric();


   glEnable(GL_TEXTURE_2D);
   LoadTexture(IMAGE_NAME);

   DrawLeaves();
   DisplayListRefresh();


   /* let the resize call be made once, so that the projection matrix is set in the resize handler */
   //resize(WIN_WIDTH, WIN_HEIGHT);
}

/*----------------------------------------------------------------------------------------------------------*/
void display(void)
{
   //code
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   /* view transform for better viewing */
   gluLookAt(0.0f, 5.0f, -15.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

   glTranslatef(0.0f, -5.5f, 0.0f);
   glRotatef(sceneAngle, 0.0f, 1.0f, 0.0f);
   //DisplayListRefresh();
   //nBranches++;
   glCallList(dlTree);
   
   //static int counter = 0;
   //static int divisor = 15;

   //counter++;
   //if(counter % divisor == 0) {
   //   nBranches++;
   //   DisplayListRefresh();

   //   //if(counter % 1500)
   //   //   divisor--;

   //   //if(divisor == 0)
   //   //   divisor = 1;
   //}
   //else
   //   glCallList(dlTree);

   SwapBuffers(ghdc);
}

/*----------------------------------------------------------------------------------------------------------*/
void resize(int width, int height)
{
   //code
   if(height == 0)
      height = 1;

   glViewport(0, 0, (GLsizei) width, (GLsizei) height);
   SetProjectionMatrix(width, height);
}

/*----------------------------------------------------------------------------------------------------------*/
void uninitialize(void)
{
   //UNINITIALIZATION CODE

   if(gbFullscreen == true) {
      dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
      SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
      SetWindowPlacement(ghwnd, &wpPrev);
      SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

      ShowCursor(TRUE);
   }

   wglMakeCurrent(NULL, NULL);

   wglDeleteContext(ghrc);
   ghrc = NULL;

   ReleaseDC(ghwnd, ghdc);
   ghdc = NULL;

   DestroyWindow(ghwnd);
   ghwnd = NULL;

   /* cleanup the quadric */
   gluDeleteQuadric(quadric);

   delete[] tdata;
}
