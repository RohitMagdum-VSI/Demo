#include "students.h"

void customGlColor3f(customColor color)
{
	switch (color)
	{
	case customColor::red:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case customColor::green:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case customColor::blue:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case customColor::yellow:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case customColor::white:
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	case customColor::black:
		glColor3f(0.0f, 0.0f, 0.0f);
		break;
	case customColor::purple:
		glColor3f(1.0f, 0.0f, 1.0f);
		break;
	case customColor::cyan:
		glColor3f(0.0f, 1.0f, 1.0f);
		break;
	case customColor::orange:
		glColor3f(1.0f, 0.550f, 0.50f);
		break;
	case customColor::brown:
		glColor3f(1.0f, 0.50f, 0.0f);
		break;
	case customColor::gray:
		glColor3f(0.50f, 0.50f, 0.5f);
		break;
	default:
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	}
}

void drawBoy(GLfloat x, GLfloat y, GLfloat z, customColor shirtColor, customColor pantColor)
{
	//Face	
	glTranslatef(x + 0.0f, y + 0.25f, z + (-2.0f));

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//quadric = gluNewQuadric();
	glColor3f(0.2f, 0.20f, 0.20f);
	glScalef(0.58f, 0.70f, 0.20f);
	gluSphere(quadric, 0.2, 80, 80);

	//ears
	glLoadIdentity();
	glTranslatef(x + (-0.12f), y + 0.27f, z + (-2.0f));

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	glColor3f(0.80f, 0.60f, 0.40f);
	glScalef(0.40f, 1.0f, 0.20f);
	gluSphere(quadric, 0.028, 80, 80);

	glLoadIdentity();
	glTranslatef(x + 0.12f, y + 0.27f, z + (-2.0f));

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	glColor3f(0.80f, 0.60f, 0.40f);
	glScalef(0.40f, 1.0f, 0.20f);
	gluSphere(quadric, 0.028, 80, 80);

	//shirt
	glLoadIdentity();
	glTranslatef(x + 0.0f, y + -0.14f, z + -2.0f);

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	//glColor3f(1.0f, 0.10f, 0.20f);
	customGlColor3f(shirtColor);
	glScalef(0.50f, 1.0f, 0.20f);
	gluSphere(quadric, 0.27, 80, 80);

	//Leg
	glLoadIdentity();
	glTranslatef(x + 0.0f, y + -0.35f, z + -2.0f);

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	//glColor3f(0.0f, 0.70f, 0.70f);
	customGlColor3f(pantColor);
	glScalef(0.80f, 0.50f, 0.20f);
	gluSphere(quadric, 0.23, 80, 80);

}
void drawGirl(GLfloat x, GLfloat y, GLfloat z, customColor shirtColor, customColor pantColor)
{
	glLoadIdentity();

	//Face	
	glTranslatef(x + 0.45f, y + 0.25f, z + -2.0f);

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	glColor3f(0.2f, 0.20f, 0.20f);
	glScalef(0.58f, 0.80f, 0.20f);
	gluSphere(quadric, 0.2, 80, 80);

	glLoadIdentity();
	glTranslatef(x + 0.45f, y + 0.20f, z + -2.0f);

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	glColor3f(0.2f, 0.20f, 0.20f);
	glScalef(0.68f, 0.45f, 0.70f);
	gluSphere(quadric, 0.2, 80, 80);

	//shirt
	glLoadIdentity();
	glTranslatef(x + 0.45f, y + -0.16f, z + (-2.0f));

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	//glColor3f(1.0f, 0.10f, 0.20f);
	customGlColor3f(shirtColor);
	glScalef(0.50f, 1.0f, 0.20f);
	gluSphere(quadric, 0.27, 80, 80);

	//Leg
	glLoadIdentity();
	glTranslatef(x + 0.45f, y + -0.33f, z + -2.0f);

	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	//glColor3f(0.0f, 0.70f, 0.70f);
	customGlColor3f(pantColor);

	glScalef(0.80f, 0.50f, 0.20f);
	gluSphere(quadric, 0.23, 80, 80);
}
