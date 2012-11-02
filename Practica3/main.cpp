#include <gl\glut.h>

void dibujar_figuras ();
int angle = 0; 
const GLfloat red[3] = {1,0,0};
const GLfloat green[3] = {0,1,0};

void init()
{
	glEnable(GL_DEPTH_TEST); 
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	

}
void reshape (int w, int h)
{
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(60, (GLsizei)w/(GLsizei)h, 1, 300); 
	gluLookAt(0,0,1,0,0,0,0,1,0);

	glMatrixMode(GL_MODELVIEW); 
}
void display ()
{
	glClearDepth(1); 
	glClearColor(0,0,0,1); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glLoadIdentity();
	dibujar_figuras(); 
	glutSwapBuffers(); 
	angle++;
}

void dibujar_figuras ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();		
	
	glTranslatef(-1.5f,0.0f,-6.0f);		
	glRotatef(angle/5, 0.0,1.0,0.0);

	//Se define la piramide
	glBegin(GL_TRIANGLES);								
		glColor3f(1.0f,0.0f,0.0f);						
		glVertex3f( 0.0f, 1.0f, 0.0f);					
		glColor3f(0.0f,1.0f,0.0f);						
		glVertex3f(-1.0f,-1.0f, 1.0f);					
		glColor3f(0.0f,0.0f,1.0f);						
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f( 1.0f,-1.0f, -1.0f);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f( 1.0f,-1.0f, -1.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(-1.0f,-1.0f, -1.0f);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
	glEnd();		
	
	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-7.0f);	
	glRotatef(angle/5,1.0f,1.0f,1.0f);
	//Se define el cubo
	glBegin(GL_QUADS);	
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f( 1.0f, 1.0f,-1.0f);
		glVertex3f(-1.0f, 1.0f,-1.0f);	
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		glColor3f(1.0f,0.5f,0.0f);		
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f( 1.0f,-1.0f,-1.0f);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glColor3f(1.0f,1.0f,0.0f);
		glVertex3f( 1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f, 1.0f,-1.0f);
		glVertex3f( 1.0f, 1.0f,-1.0f);
		glColor3f(0.0f,0.0f,1.0f);		
		glVertex3f(-1.0f, 1.0f, 1.0f);	
		glVertex3f(-1.0f, 1.0f,-1.0f);	
		glVertex3f(-1.0f,-1.0f,-1.0f);	
		glVertex3f(-1.0f,-1.0f, 1.0f);	
		glColor3f(1.0f,0.0f,1.0f);		
		glVertex3f( 1.0f, 1.0f,-1.0f);	
		glVertex3f( 1.0f, 1.0f, 1.0f);	
		glVertex3f( 1.0f,-1.0f, 1.0f);	
		glVertex3f( 1.0f,-1.0f,-1.0f);	
	glEnd();	
	glPopMatrix();
}

int main (int argc, char **argv) {
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_DOUBLE); 
	glutInitWindowSize (500, 500); 
	glutCreateWindow ("Practica 3 - a"); 
	init();
	
	glutDisplayFunc (display); 
	glutIdleFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop ();
	return 0;
}