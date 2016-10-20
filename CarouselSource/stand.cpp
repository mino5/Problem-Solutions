#include "stand.h"



void CStand::DrawStandPiece1(float heightDifference)
{
	
	glBegin(GL_QUADS);

			    glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.3f, heightDifference, -0.3f); // top right
				
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-0.5f, heightDifference, -0.3f); // top left

				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-0.5f, 0.0f, -0.3f ); // bottom left
				
		        glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.3f, 0.0f, -0.3f); // bottom right

	glEnd();

}

void CStand::DrawStandPiece2(float heightDifference)
{

	glBegin(GL_QUADS);

				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.3f, heightDifference, 0.3f); // top right
				
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-0.5f, heightDifference, 0.3f); // top left

				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-0.5f, 0.0f, 0.3f ); // bottom left
				
		        glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.3f, 0.0f, 0.3f); // bottom right


	glEnd();
}

void CStand::DrawStandPiece3(float heightDifference)
{
	glBegin(GL_QUADS);

	

				// prostk¹t pod k¹tem
	
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.5f, heightDifference, -0.1f); // top right

				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.3f, heightDifference, -0.3f); // top left

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.3f, 0.0f, -0.3f ); // bottom left

																
		        glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.5f, 0.0f, -0.1f); // bottom right

				// drugi pod k¹tem

				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.5f, heightDifference, 0.1f); // top right

				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.3f, heightDifference, 0.3f); // top left

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.3f, 0.0f, 0.3f ); // bottom left
																
		        glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.5f, 0.0f, 0.1f); // bottom right



	glEnd();

}

void CStand::DrawStandPiece4(float heightDifference)
{

	glBegin(GL_QUADS);
	// ostatni, krótki

				
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.5f, heightDifference, -0.1f); // top right
				
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.5f, heightDifference, 0.1f); // top left
	
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.5f, 0.0f, 0.1f); // bottom right

				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.5f, 0.0f, -0.1f ); // bottom left

	glEnd();

}

void CStand::DrawStandPiece5(float heightDifference)
{

	glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-0.5f, heightDifference, -0.3f); // top right
							
				
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-0.5f, heightDifference, 0.3f); // top left
								
		        glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-0.5f, 0.0f, 0.3f); // bottom right
				glTexCoord2f(1.0f, 0.0f);
				
				glVertex3f(-0.5f, 0.0f, -0.3f ); // bottom left
	glEnd();

}

void CStand::DrawStand(float heightDifference)
{


	DrawStandPiece1(heightDifference);
	DrawStandPiece2(heightDifference);
	DrawStandPiece3(heightDifference);
	DrawStandPiece4(heightDifference);
	DrawStandPiece5(heightDifference);
	
}


void CStand::Draw()
{

	glTranslatef(position.x, position.y, position.z);
    glDisable(GL_TEXTURE_2D);	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);	
	glBindTexture(GL_TEXTURE_2D, standTex->texID); 
	DrawStand(0.1f);
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0f,0.1f,0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, standTex2->texID);
	DrawStand(0.2f);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,0.3f,0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, standTex3->texID);
	DrawStandPiece2(0.5f);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0,0.3f,0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, standTex5->texID);
	DrawStandPiece1(0.5f);
	DrawStandPiece3(0.5f);
	glBindTexture(GL_TEXTURE_2D, standTex5->texID);
	DrawStandPiece4(0.5f);
	DrawStandPiece5(0.5f);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

// Animate()
// opis: wyznacza równania ruch  (których brak w przypadku lodowiska)
void CStand::Animate(scalar_t deltaTime) {}

// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CStand::SetupTexture()
{
     glGenTextures(1, &standTex->texID);
     glBindTexture(GL_TEXTURE_2D, standTex->texID);
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, standTex->width, standTex->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, standTex->image->data);

	 glGenTextures(1, &standTex2->texID);
     glBindTexture(GL_TEXTURE_2D, standTex2->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, standTex2->width, standTex2->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, standTex2->image->data);

	 glGenTextures(1, &standTex3->texID);
	 glBindTexture(GL_TEXTURE_2D, standTex3->texID);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, standTex3->width, standTex3->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, standTex3->image->data);

	 glGenTextures(1, &standTex4->texID);
	 glBindTexture(GL_TEXTURE_2D, standTex4->texID);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, standTex4->width, standTex4->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, standTex4->image->data);

	 glGenTextures(1, &standTex5->texID);
	 glBindTexture(GL_TEXTURE_2D, standTex5->texID);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, standTex5->width, standTex5->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, standTex5->image->data);

}


// Load()
// opis: inicjuje atrybuty obiektu
void CStand::Load()
{

	 standTex = new CTexture;
     standTex->LoadTexture("images/red.bmp");

	 standTex2 = new CTexture;
	 standTex2->LoadTexture("images/oceanblue.bmp");

	 standTex3 = new CTexture;
	 standTex3->LoadTexture("images/window.bmp");

	 standTex4 = new CTexture;
	 standTex4->LoadTexture("images/strip2.bmp");

	 standTex5 = new CTexture;
	 standTex5->LoadTexture("images/yellow.bmp");

	 SetupTexture();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CStand::Unload()
{
    standTex->Unload();
	standTex2->Unload();
	standTex3->Unload();
	standTex4->Unload();
	standTex5->Unload();
}