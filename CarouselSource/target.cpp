#include "target.h"

GLUquadricObj *circletarget=NULL;

void CTarget::Draw()
{

	glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
	glEnable(GL_TEXTURE_2D);	
	glBindTexture(GL_TEXTURE_2D, targetTex->texID); 
	glRotatef(90, 1, 0, 0);
    gluDisk(circletarget, 0, 0.5, 50, 10);

	glDisable(GL_TEXTURE_2D);			
	glPopMatrix();
}

// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CTarget::SetupTexture()
{
     glGenTextures(1, &targetTex->texID);
     glBindTexture(GL_TEXTURE_2D, targetTex->texID);
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_FILL);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_FILL);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, targetTex->width , targetTex->height , 
		 GL_RGB, GL_UNSIGNED_BYTE, targetTex->image->data);

}


// Load()
// opis: inicjuje atrybuty obiektu
void CTarget::Load()
{

	circletarget = gluNewQuadric();
	gluQuadricDrawStyle(circletarget, GLU_FILL);
	gluQuadricTexture(circletarget, TRUE);
    gluQuadricNormals(circletarget, GLU_SMOOTH);
    targetTex = new CTexture;
    targetTex->LoadTexture("images/target.bmp");

	SetupTexture();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CTarget::Unload()
{
    targetTex->Unload();
}