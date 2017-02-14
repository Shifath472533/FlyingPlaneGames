#include<iostream>
#include <stdio.h>
#include<string>
#include<math.h>
#include <stdlib.h>
//#include<windows.h>
#include <GL/glut.h>
using namespace std;


void init();
void myDisplay();
void myInit();

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float cloudX = 300.0;
float treeX = 300.0;
bool cloudMoveRight = true;
float cloudspeed = 3.0;
float treespeed = 2.0;

void plane();
void background();
void box();

int planeX = 0;
int planeY = 0;
int planeX1 = 0;
int planeY1 = 0;
int planeX2 = 0;
int planeY2 = 0;
int planeX3 = 0;
int planeY3 = 0;
int pyMAX = 0;
int pyMIN = 0;


int boxX = 0;
int boxY = 0;
int boxXMAX = 0;
int boxXMIN = 0;
int boxYMAX = 0;
int boxYMIN = 0;

int axisX = 0;
int axisY = 0;

std::string scoring;
int Score = 0;


void score(const char *text)
{
	
	int x = 250, y = 350;

	glColor3f(1, 0, 0);
	glRasterPos2f(x, y);
	while (*text)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
		text++;
	}
}

/*void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1350, 0, 650);

	
}*/


void keyboard(unsigned char key, int x, int y)
{

	if (key == 'w')
	{
		
		 if (planeY1>boxYMIN && planeY1<boxYMAX && planeX1>boxXMIN && planeX1<boxXMAX)
		{
			boxX = boxX;
			boxY = boxY;
			//count_r++;
			//drawGameOverText();
		}
		else if (planeY2>boxYMIN && planeY2<boxYMAX && planeX2>boxXMIN && planeX2<boxXMAX)
		{
			boxX = boxX;
			boxY = boxY;
			//count_r++;
			//drawGameOverText();
		}
		else if (planeY3>boxYMIN && planeY3<boxYMAX && planeX3>boxXMIN && planeX3<boxXMAX)
		{
			boxX = boxX;
			boxY = boxY;
			//count_r++;
			//drawGameOverText();
		}
		else if (pyMAX<400)
		{
			planeY = planeY + 2;
			boxX = boxX - 8;
			if (boxX<-600)
			{
				boxX = 0;
				Score++;
				boxY = rand() % 365;
			}
		}

		else if (boxX<-600)
		{
			boxX = 0;
			Score++;
			boxY = rand() % 365;
		}
		else
		{
			boxX = boxX - 8;
		}

		glutPostRedisplay();
	}
	else if (key == 's')
	{

	  if (planeY1>boxYMIN && planeY1<boxYMAX && planeX1>boxXMIN && planeX1<boxXMAX)
		{
			boxX = boxX;
			boxY = boxY;
			//count_r++;
			//drawGameOverText();
		}
		else if (planeY2>boxYMIN && planeY2<boxYMAX && planeX2>boxXMIN && planeX2<boxXMAX)
		{
			boxX = boxX;
			boxY = boxY;
			//count_r++;
			//drawGameOverText();
		}
		else if (planeY3>boxYMIN && planeY3<boxYMAX && planeX3>boxXMIN && planeX3<boxXMAX)
		{
			boxX = boxX;
			boxY = boxY;
			//count_r++;
			//drawGameOverText();
		}

		else if (pyMIN>0)
		{
			planeY = planeY - 2;
			boxX = boxX - 8;
			if (boxX<-600)
			{
				boxX = 0;
				Score++;
				boxY = rand() % 365;
			}
		}

		else if (boxX<-600)
		{
			boxX = 0;
			Score++;
			boxY = rand() % 365;
		}
		else
		{
			boxX = boxX - 8;
		}

		glutPostRedisplay();
	}
	else if (key == 'r')
	{

		planeY = 0;
		boxX = 0;
		boxY = 0;
		//score = 0;
		glutPostRedisplay();
	}


}





void plane()
{
	planeX1 = 250 + planeX;
	planeX2 = 130 + planeX;
	planeX3 = 155 + planeX;
	planeY1 = 340 + planeY;
	planeY2 = 310 + planeY;
	planeY3 = 340 + planeY;
	pyMAX = 340 + planeY;
	pyMIN = 310 + planeY;


	glColor3f(1.747, 0.747, 0.747);
	glBegin(GL_POLYGON);
	glVertex2i(planeX2, pyMIN);
	glVertex2i(planeX1, planeY1);
	glVertex2i(155 + planeX, 340 + planeY);
	glEnd();

	glColor3f(0.847, 0.847, 0.847);
	glBegin(GL_POLYGON);
	glVertex2i(125+planeX, 330 + planeY);
	glVertex2i(planeX1, pyMAX);
	glVertex2i(planeX3, pyMAX);
	glEnd();


}

void sun()
{
	 
	glPushMatrix();
	glTranslatef(450.0,350.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 38;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

}
void cloud()
{   //cloud1
	glPushMatrix();
	glTranslatef(cloudX-35.0,340.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(cloudX+35.0,340.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(cloudX,360.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(cloudX,325.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	//cloud2
	glPushMatrix();
	glTranslatef(cloudX-190.0,315.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 28;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX-260.0,315.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 28;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX-230.0,300.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 28;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX-230.0,335.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 28;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
	
}
void tree()
{    //tree1
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(treeX -230.0, 70, 0.0);
	glVertex3f(treeX -210.0, 70, 0.0);
	glVertex3f(treeX -210,195 , 0.0);
	glVertex3f(treeX -230.0, 195, 0.0);
	 glEnd();

	glPushMatrix();
	glTranslatef(treeX-260.0,205.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX -255.0,235.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX -215.0,240.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 45;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX -215.0,225.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	

	glPushMatrix();
	glTranslatef(treeX -180.0,205.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX -180.0,230.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();


	//tree2

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(treeX+192.0, 70, 0.0);
	glVertex3f(treeX+208.0, 70, 0.0);
	glVertex3f(treeX+208.0,145 , 0.0);
	glVertex3f(treeX+192.0, 145, 0.0);
	 glEnd();

	glPushMatrix();
	glTranslatef(treeX+180.0,150.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX+220.0,150.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(treeX+200.0,168.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
	


	
}
void box()
{
	boxXMAX = 600 + boxX;
	boxXMIN = 550 + boxX;
	boxYMAX = 200 + boxY;
	boxYMIN = 0 + boxY;

	glColor3f(0.165, 0.012, 0.411);
	glBegin(GL_POLYGON);
	glVertex2i(boxXMIN, boxYMIN);
	glVertex2i(boxXMAX, boxYMIN);
	glVertex2i(600 + boxX, boxYMAX);
	glVertex2i(550 + boxX, boxYMAX);
	glEnd();

}

void sky()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 100, 0.0);
	glVertex3f(600, 100, 0.0);
	glVertex3f(600, 400, 0.0);
	glVertex3f(0, 400.0, 0.0);
	glEnd();
}

void grass()
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0.0);
	glVertex3f(600, 0, 0.0);
	glVertex3f(600, 100, 0.0);
	glVertex3f(0, 100.0, 0.0);
	glEnd();
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sky();
	grass();
	sun();
	
	
	
    cloud();
	tree();
	plane();
	box();
	
	scoring = " Score: " + std::to_string(Score);
    score(scoring.data());
	
	if (cloudX >= -100.0)
	{
		cloudMoveRight = true;
	}
	else
	{
		cloudX = 900;
	}

	if (treeX >= -250.0)
	{
		cloudMoveRight = true;
	}
	else
	{
		treeX = 900;
	}
	

	if (cloudMoveRight)
	{
		cloudX -= cloudspeed;
		treeX -= treespeed;
	}
	
	//background();
	
	glFlush();
	glutSwapBuffers();

}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 400.0);

	
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("paper plane");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keyboard);
	myInit();
	glutTimerFunc(25, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}

