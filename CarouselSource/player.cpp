#include "player.h"
#include "polygon.h"
#include "target.h"

GLUquadricObj *sphere=NULL;

double radian(double a){
       return (a*3.1415)/180;
       }

float distance(float x1, float x2, float z1, float z2) {
	return sqrt((x1-x2)*(x1-x2) + (z1-z2)*(z1-z2));
	}	


float CPlayer::CalculateResult(float targetx, float targetz)
{

	float x1 = -((-storedx / 800.0f) + -0.03f + 1.48f*cos(radian(20.0f + startingAngle)));
	float z1 = -(1.48f*sin(radian(20.0f + startingAngle)));


	return sqrt((x1 - targetx)*(x1 - targetx) + (z1 - targetz) * (z1 - targetz));

}
void CPlayer::Draw()
{

	glTranslatef(position.x, position.y, position.z);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);	
	glBindTexture(GL_TEXTURE_2D, playerTex->texID); 
	
    gluSphere(sphere, 0.10, 15, 50);
   
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix();

}

// Animate()

void CPlayer::Animate(scalar_t deltaTime) 
{
	glPushMatrix();

	// wyznaczanie pozycji od której zacz¹³ siê skok
	glRotated(startingAngle, 0, 1, 0);
	glTranslatef(-0.03f, 2.42f, 0.0f);

	glTranslatef(1.48f*cos(radian(20.0f)), 0.0f, 1.48f*sin(radian(20.0f)));

	
	// ruch 

	if (deltaTime < 0) 
		deltaTime = 360 + deltaTime;

	float x = ((velocity*20) * (deltaTime)) * cos(radian(startingAberration));
	float y = (velocity*10) * (deltaTime) * sin(radian(startingAberration)) - ((9.81 * (deltaTime) * (deltaTime))/2.0);

	if (visible)
	{
		y = storedy;
		x = storedx;
	}
	else
	if (y / 10000.0f < -0.7)
	{
		storedy = y;
		isFalling = false;

		storedx = x;

		
		// koniec upadku, pokazujemy wci¹¿ pi³kê i liczymy wynik, ale ju¿ nie jest w trakcie spadku
		visible = true;
	}

	glTranslatef(0, y / 5000.0f, -x / 800.0f);

	//glRotatef(-110, 0.0f, 1.0f, 0.0f);
	glRotated(startingAberration,1,0,0);
	glTranslatef(0.0f, -0.2f -1.1f*cos(radian(5.0f)),-0.1);	
	glTranslatef(0.01f, 0.1f, 0.1f);


	Draw();
	glPopMatrix();
}

// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CPlayer::SetupTexture()
{
     glGenTextures(1, &playerTex->texID);
     glBindTexture(GL_TEXTURE_2D, playerTex->texID);
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_FILL);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_FILL);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, playerTex->width , playerTex->height , 
		 GL_RGB, GL_UNSIGNED_BYTE, playerTex->image->data);

}


// Load()
// opis: inicjuje atrybuty obiektu
void CPlayer::Load()
{

	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
 gluQuadricTexture(sphere, TRUE);
 gluQuadricNormals(sphere, GLU_SMOOTH);
	 playerTex = new CTexture;
     playerTex->LoadTexture("images/stripes.bmp");

	 SetupTexture();
	 auxCreateFont();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CPlayer::Unload()
{
    playerTex->Unload();
}