#include <math.h>
#include <GL/glut.h> // Header File For The GLUT Library

/* A general OpenGL initialization function. Sets all of the initial parameters. */
void InitGL(int Width, int Height) // We call this right after our OpenGL window is created.
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // This Will Clear The Background Color To Black
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

void ReSizeGLScene(int Width, int Height)
{
	if (Height==0) 
	{
		Height=1;
	}
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f); 	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,50, 0,50,0, 0,1,0);
}
float line(int i,float lineLength,float x0,float y0){
	glBegin(GL_LINES); 
	if(i%2)
	{
		glVertex2f(x0,y0); 
		x0=x0+lineLength;
		glVertex2f(x0,y0); 	

	}
	else
	{
		glVertex2f(x0,y0); 
		y0=y0+lineLength;
		glVertex2f(x0,y0); 	
	}
	glEnd();
	i++;
	if(i<20)
	{
	line(i,lineLength/2,x0,y0);
	line(i,-lineLength/2,x0,y0);
	}
	return 0; 
}
void DrawGLScene()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); 
	glColor3f(0.0f,1.0f,0.0f);
	int i=0;
	float x0=0.0f,y0=0.0f,lineLength=40.0f;
	line(i,lineLength,x0,y0);
	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Drzewko rekurencyjne");
	glutDisplayFunc(&DrawGLScene);
	glutIdleFunc(&DrawGLScene);
	glutReshapeFunc(&ReSizeGLScene);
	InitGL(640, 480);
	glutMainLoop();
	return 0;
}
