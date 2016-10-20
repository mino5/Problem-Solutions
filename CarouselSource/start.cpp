#include "start.h"

GLUquadricObj *circle=NULL;




void CStart::Draw()
{

	glTranslatef(position.x, position.y, position.z);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);	
	glBindTexture(GL_TEXTURE_2D, startTex->texID); 
	
    gluDisk(circle, 0, 0.15, 50, 10);
   
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix();

}

// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CStart::SetupTexture()
{
     glGenTextures(1, &startTex->texID);
     glBindTexture(GL_TEXTURE_2D, startTex->texID);
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_FILL);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_FILL);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, startTex->width , startTex->height , 
		 GL_RGB, GL_UNSIGNED_BYTE, startTex->image->data);

}


// Load()
// opis: inicjuje atrybuty obiektu
void CStart::Load()
{

	circle = gluNewQuadric();
	gluQuadricDrawStyle(circle, GLU_FILL);
 gluQuadricTexture(circle, TRUE);
 gluQuadricNormals(circle, GLU_SMOOTH);
	 startTex = new CTexture;
     startTex->LoadTexture("images/start.bmp");

	 SetupTexture();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CStart::Unload()
{
    startTex->Unload();
}