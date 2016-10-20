#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <GL/glut.h>
#include <gl/glaux.h>
#include <time.h>
#include "ground.h"
#include "sky.h"
#include "polygon.h"
#include "stand.h"
#include "start.h"
#include "target.h"


GLfloat lookupdown = 0.0f;
GLfloat	yrot, yrot2;				// Y Rotation
GLfloat walkbias = 0;
GLfloat walkbiasangle = 0;
GLfloat	z=0.0f;				// Depth Into The Screen
const float piover180 = 0.0174532925f;
float heading, heading2;
float xpos;
float zpos;
float speed;

// kamera
bool gameStarted = false;
bool cameraFromSide = true;

// wpó³rzêdne po³o¿enia obserwatora
GLdouble eyex = 0;
GLdouble eyey = -1.0;
GLdouble eyez = 9.0;

// wspó³rzêdne punktu w którego kierunku jest zwrócony obserwator,
GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = - 100;


CGround* ground;
CSky* sky;
CPolygon* polygon;
CStand* stand;
CStart* start;
CTarget* target;


void display(void)
{
    
    // czyszczenie bufora koloru
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glDisable(GL_CULL_FACE);

    // wybór macierzy modelowania
    glMatrixMode( GL_MODELVIEW );
    
    glLoadIdentity();



    // odchylenie
	float aberration = polygon->countAngle(atan((polygon->velocity*polygon->velocity)/(1.48f*9.81)));

	// widok "z boku"
	if (!gameStarted || cameraFromSide)
	{
    // ustawienie obserwatora
		gluLookAt( eyex, eyey , eyez, centerx, centery, centerz, 0, 1.0, 0 );

	
		GLfloat x_m, y_m, z_m, u_m, v_m;
		GLfloat xtrans = -xpos;
		GLfloat ztrans = -zpos;
		GLfloat ytrans = -walkbias-0.25f;

		if (!gameStarted) yrot = yrot2;
		else 
		{
			yrot = heading;
			yrot2 = 0.0f;
			heading2 = 0.0f;
		}
		GLfloat sceneroty = 360.0f - yrot;


		glRotatef(lookupdown,1.0f,0,0);
		glRotatef(sceneroty,0,1.0f,0);
		glTranslatef(xtrans, ytrans, ztrans - 1.0f);

	}

	// pod¹¿anie za graczem
	else 
	{
		// góra

		glRotated(aberration, 0, 1 ,0);
		glTranslatef(0.0, 2.42f, 0.0f);

		glTranslatef(0.0f, -0.2f -1.1f*cos(polygon->radian(5.0f)), -0.1f);

	    //glRotated(aberration,1 ,0, 0);
	
		float x = 1.3f*sin(polygon->radian(aberration));
		float y = 1.3f*cos(polygon->radian(aberration));

		gluLookAt(1.48f*cos(polygon->radian(0.0f)) + x, (1.3f - y), 1.48f*sin(polygon->radian(0.0f)) - x, 1.48f*cos(polygon->radian(40.0f)) + x, (1.3f - y), 1.48f*cos(polygon->radian(40.0f)), 0.0,1.0 , 0.0);	

		glRotatef(aberration, 1.0, 0.0, 0.0); 
		glRotatef(-110.0f, 0, 1, 0);
		glRotatef(-polygon->angle, 0, 1, 0);
	}

		sky->Draw();
		ground->position.y = -3.0f;
	    ground->Draw();

		polygon->velocity = speed * 1.48f; // prêdkoœæ liniowa = prêdkoœæ k¹towa * promieñ
		polygon->position.x = 0.0f;
		polygon->position.y = 0.0f;
		polygon->position.z = 0.0f;

		polygon->Draw();


		stand->position.x = 0.0f;
		stand->position.y = 0.4f;
		stand->position.z = 0.0f;

		stand->Draw();



	// START
	if (!gameStarted)
	{
		glPushMatrix();
		glLoadIdentity();
		gluLookAt( 0, -1.5f , 6.0f, 0.0, 0.0, -100.0, 0, 1.0, 0 );

		start->position.x = 0.0f;
		start->position.y = -1.4f;
		start->position.z = 4.0f;

		start->Draw();

		glPopMatrix();

		heading2 += 0.15f;	
		yrot2 = heading2;
	}
	else
	{
		target->position.x = 3.0f;
		target->position.z = 2.0f;
		target->position.y = -0.5f;
		target->Draw();
		speed += 0.001f;
	}


   glFlush();
   glutSwapBuffers();

}


void reshape(GLint width, GLint height)
{


	if (height<=0) { height=1; }

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}

void keySpecial(int key, int x, int y)
{
	switch( key )
    {
        // kursor w lewo
    case GLUT_KEY_LEFT:

		heading += 1.0f;	
		yrot = heading;
        break;
        
        // kursor w górê
    case GLUT_KEY_UP:
		xpos -= (float)sin(heading*piover180) * 0.05f;
					zpos -= (float)cos(heading*piover180) * 0.05f;
					if (walkbiasangle >= 359.0f)
					{
						walkbiasangle = 0.0f;
					}
					else
					{
						walkbiasangle+= 10;
					}
					walkbias = (float)sin(walkbiasangle * piover180)/20.0f;

        break;
        
        // kursor w prawo
    case GLUT_KEY_RIGHT:

		heading -= 1.0f;
		yrot = heading;
        break;
        
        // kursor w dó³
    case GLUT_KEY_DOWN:


		xpos += (float)sin(heading*piover180) * 0.05f;
					zpos += (float)cos(heading*piover180) * 0.05f;
					if (walkbiasangle <= 1.0f)
					{
						walkbiasangle = 359.0f;
					}
					else
					{
						walkbiasangle-= 10;
					}
					walkbias = (float)sin(walkbiasangle * piover180)/20.0f;

        break;

    }

	glutPostRedisplay();
}

void init(void)
{
   speed = 0.0f;

   glClearColor(0.0, 0.0, 0.0, 0.0);


	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);							
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);							
	glDepthFunc(GL_LEQUAL);								
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	//glFrontFace (GL_CCW);								
													
	glCullFace(GL_BACK);							
													
	glEnable(GL_CULL_FACE);

    ground = new CGround;
    ground->Load();

	sky = new CSky;
	sky->Load();

	polygon = new CPolygon;
	polygon->Load();

	stand = new CStand;
	stand->Load();

	start = new CStart;
	start->Load();

	target = new CTarget;
	target->Load();

	polygon->target = target;
}

void keyboard(unsigned char key, int x, int y)
{
    if( key == '+' )
         eyez -= 0.1;
    else
    
    // klawisz -
    if( key == '-' )
         eyez += 0.1;

	if (key == 'w')
		 eyey -= 0.1;

	if (key == 's')
		 eyey += 0.1;

	if (key == 'a')
		 eyex += 0.1;

	if (key == 'd')
		 eyex -= 0.1;

	if (key == ']')
		speed += 0.1f;

	if (key == '[')
		speed -= 0.1f;

	if (key == 13)
	{
		gameStarted = true;
		cameraFromSide = false;
		polygon->camera = true;
		polygon->angle = 0.0f;
		polygon->play->visible = false;
	    speed = 0.0f;
	}

	if (key == 'r')
	{
		gameStarted = false;
		cameraFromSide = true;
		polygon->camera = false;
		polygon->play->visible = false;
	}

	if (key == '1')
	{
		cameraFromSide = true; 
		polygon->camera = true;
	}

	if (key == '2')
	{
		cameraFromSide = false;
		polygon->camera = false;
	}
    
	if (key == 27) // ESC
	{
		ground->Unload();
		sky->Unload();
		polygon->Unload();
		stand->Unload();
		start->Unload();
		exit(0);
	}

	if (key == 32) // SPACE - spadamy
	{
		cameraFromSide = true;
		polygon->camera = true;
		polygon->AnimatePlayer(0.0);
	}

    glutPostRedisplay();
}

void idle()
{
	if (polygon != NULL)
	{
		polygon->angle += speed;

		if (polygon->angle >= 360.0f)
			polygon->angle = 0.0f;
		else if (polygon->angle <= -360.0f)
			polygon->angle = 0.0f;
	}

    glutPostRedisplay();
}

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);


    glutCreateWindow(argv[0]);
	//	glutFullScreen();
	init();
    glutReshapeFunc(reshape);
	glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	// specjalne klawisze PRAWO, LEWO
	glutSpecialFunc(keySpecial);

    glutMainLoop();


    return 0;
}
