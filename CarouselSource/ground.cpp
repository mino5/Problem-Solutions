#include "ground.h"

#define TERRAIN_WIDTH 8
#define TERRAIN_LENGTH 8
#define X 8
void CGround::Draw()
{
	glTranslatef(position.x, position.y, position.z);

	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);			

	glEnable(GL_TEXTURE_2D);			
	glDisable (GL_DEPTH_TEST);			

	glBindTexture(GL_TEXTURE_2D, groundTex->texID);

    glBegin(GL_QUADS);

	    glTexCoord2f(0, 0); 
	    glVertex3f(-TERRAIN_WIDTH, 0.0f,  TERRAIN_LENGTH);
        glTexCoord2f(X, 0); 
	    glVertex3f( TERRAIN_WIDTH, 0.0f,  TERRAIN_LENGTH);
        glTexCoord2f(X, X); 
	    glVertex3f( TERRAIN_WIDTH, 0.0f, -TERRAIN_LENGTH);
     	glTexCoord2f(0, X); 
		glVertex3f(-TERRAIN_WIDTH, 0.0f, -TERRAIN_LENGTH);

    glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glPopMatrix(); 
}

// Animate()
// opis: wyznacza równania ruch  (których brak w przypadku lodowiska)
void CGround::Animate(scalar_t deltaTime) {}

// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CGround::SetupTexture()
{
     // konfiguruje teksturê
     glGenTextures(1, &groundTex->texID);
     glBindTexture(GL_TEXTURE_2D, groundTex->texID);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, groundTex->width, groundTex->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, groundTex->image->data);

     
}

// Load()
// opis: inicjuje atrybuty obiektu
void CGround::Load()
{
	 groundTex = new CTexture;
     // ³aduje i inicjuje teksturê
     groundTex->LoadTexture("images/kostka.bmp");
     SetupTexture();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CGround::Unload()
{
     groundTex->Unload();
}