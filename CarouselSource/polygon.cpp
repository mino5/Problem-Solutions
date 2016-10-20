#include "polygon.h"
#include <string>

using std::string;

const float a = 1.0f;
double CPolygon::radian(double a){
       return (a*3.1415)/180;
       }

double CPolygon::countAngle(double rad) {
	   return (rad*180)/3.1415;
}


void CPolygon::DrawLines(GLuint metalTex, GLuint chainTex, float radius)
{

	// krótki kawa³ek od góry
	
	// odchylenie
	float aberration = countAngle(atan((velocity*velocity)/(1.48f*9.81)));

	int rotz = 1;

	for(float x=0.0;x<=360.0;x+=360.0/9.0)
	{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, metalTex);
		    glPushMatrix();

			glTranslatef(radius*cos(radian(x + 20.0f)), 0.0f, radius*sin(radian(x + 20.0f)));
		
			glRotatef(-110 - x, 0.0f, 1.0f, 0.0f);
			
			// odchylenie 
			glRotated(aberration,1,0, 0);

			// linia pionowa
			glRotatef(90, 1.0f, 0.0f, 0.0f);
			gluCylinder(cylinderQuad, 0.01f , 0.01f, 0.2f,  32, 32);	
			glRotatef(-90, 1.0f, 0.0f, 0.0f);

			glTranslatef(0.0f, -0.2f, -0.1f);

			// linia pozioma pod tym kawa³kiem

			gluCylinder(cylinderQuad, 0.01f, 0.01f, 0.195f, 32, 32);

			glRotatef(90, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0, 0.0f, 0.0f);
				
			// ³añcuchy
			glBindTexture(GL_TEXTURE_2D, chainTex);


			
			glRotatef(5, 0.0f, 1.0f, 0.0f);
			gluCylinder(cylinderQuad, 0.003f, 0.003f, 1.1f, 32, 32);

			glRotatef(-10, 0.0f, 1.0f, 0.0f);
			gluCylinder(cylinderQuad, 0.003f, 0.003f, 1.1f, 32, 32);

			glTranslatef(0.0, 0.2f, 0.0f);

			glRotatef(10, 0.0f, 1.0f, 0.0f);
			gluCylinder(cylinderQuad, 0.003f, 0.003f, 1.1f, 32, 32);

			glRotatef(-10, 0.0f, 1.0f, 0.0f);
			gluCylinder(cylinderQuad, 0.003f, 0.003f, 1.1f, 32, 32);

			glPopMatrix();

			glPushMatrix();

			glBindTexture(GL_TEXTURE_2D, polygonTex2->texID);


			glTranslatef(radius*cos(radian(x + 20.0f)), 0.0f, radius*sin(radian(x + 20.0f)));

			glRotatef(90, 1.0f, 0.0f, 0.0f);

			glRotatef(-90, 1.0f, 0.0f, 0.0f);
			glRotatef(-110 - x, 0.0f, 1.0f, 0.0f);
		    glRotated(aberration,1,0,0);


			glTranslatef(0.0f, -0.2f -1.1f*cos(radian(5.0f)),-0.1);

						
			// siedzenia

			glBegin(GL_QUADS);

			    glTexCoord2f(0.0f, 0.0f);
				glVertex3f(1.1f*sin(radian(5.0f)), 0.0f, 0.0f);

				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.1f*sin(radian(5.0f)), 0.0f, 0.2f);

				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-1.1f*sin(radian(5.0f)), 0.0f, 0.2f);
							
				glTexCoord2f(0.0f, 1.0f);
			    glVertex3f(-1.1f*sin(radian(5.0f)), 0.0f, 0.0f);

			glEnd();

			glDisable(GL_TEXTURE_2D);
			// rysuje zawodnika
			if (x == 0.0f)
			{
				if (!play->isFalling)
				{
					glTranslatef(0.01f, 0.1f, 0.1f);
					play->Draw();
				}
			}

			glPopMatrix();

	}
}

void CPolygon::DrawTriangles(GLuint texture, float radius, float radius2, float heightDifference)
{
	glBindTexture(GL_TEXTURE_2D, texture);

	
	for(float x=0.0;x<=360.0;x+=360.0/9.0)
	{

			float z1 = radius*sin(radian(x));
			float z2 = radius*sin(radian(x + 20.0f));
			float z3 = radius*sin(radian(x + 40.0f));
			float x1 = radius*cos(radian(x));
			float x2 = radius*cos(radian(x + 20.0f));
			float x3 = radius*cos(radian(x + 40.0f));

			float z4 =  radius2*sin(radian(x + 20.0f));
			float x4 = radius2*cos(radian(x + 20.0f));
		
		glBegin(GL_POLYGON);


		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x1, 0 ,z1);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x2, 0, z2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x3, 0, z3);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x4, heightDifference, z4);

		
		glEnd();
	}


}

void drawChar(double x, double y, double z, int c)
{
   double scaleChar = 0.001;
   glColor3f(1.0, 0.0, 0.0); 
   glPushMatrix();
   glTranslatef(x, y, z);
   glScalef(scaleChar, scaleChar, scaleChar);
   glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
   glPopMatrix();
}

void drawDist(char* dist, double x, double y, double z)
{
	
	for (int i = 0; i < sizeof(dist); i ++)
	{
		x+= 0.1f;
		drawChar(x, y, z, dist[i]);
	}

}

void CPolygon::DrawFoundation(float radius, GLuint texture)
{
	glBindTexture(GL_TEXTURE_2D, texture); 

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0.0f, 0.0f, 0.0f); 
	glTexCoord2f(0.5f,0.5f);

	int i = 1;

		for(float x=0.0;x<=360.0;x+=360.0/18.0)
		{
			switch (i)
			{
				case 1:
					glTexCoord2f(0.0f, 0.0f);
					break;
				case 2:
					glTexCoord2f(1.0f, 0.0f);
					break;
				case 3:
					glTexCoord2f(1.0f, 1.0f);
					break;
				case 4:
					glTexCoord2f(0.0f, 1.0f);
					i = 1;
					break;
			}
			glVertex3f(radius*cos(radian(x)) , 0 , -radius*sin(radian(x)));
	    }

	glEnd();
}

void CPolygon::DrawPolygon(float radius, GLuint texture, float height, float radiusDifference)
{

	glBindTexture(GL_TEXTURE_2D, texture); 

	for(float x=0; x<=360.0; x+= 360.0/18.0)
	{
		    float radius2 = radius + radiusDifference;
			float x1 = radius2*cos(radian(x));
			float x2 = radius2*cos(radian(x + 20.0f));
			float x3 = radius*cos(radian(x + 20.0f));
			float x4 = radius*cos(radian(x));
			float z1 = radius2*sin(radian(x));
			float z2 = radius2*sin(radian(x + 20.0f));
			float z3 = radius*sin(radian(x + 20.0f));
			float z4 = radius*sin(radian(x));

			glBegin(GL_QUADS);

			    glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x1, height, z1); // top right
				
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x2, height, z2 ); // top left

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x3, 0.01f, z3); // bottom left
				
		        glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x4, 0.01f, z4); // bottom right

			glEnd();
	}
}

void CPolygon::Draw()
{
	
	glTranslatef(position.x, position.y, position.z);

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);	
	DrawFoundation(2.0f, polygonTex->texID);
	DrawPolygon(1.85f, polygonTex2->texID, 0.08f, 0.0f);
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.08f,0.0f);
	glEnable(GL_TEXTURE_2D);	
	DrawFoundation(1.92f, polygonTex->texID);
	DrawPolygon(1.77f, polygonTex2->texID, 0.08f, 0.0f);
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(0.0f, 0.16f,0.0f);
	glEnable(GL_TEXTURE_2D);			
	DrawFoundation(1.84f, polygonTex->texID);
	DrawPolygon(1.69f, polygonTex2->texID, 0.08f, 0.0f);
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(0.0f, 0.24f,0.0f);
	glEnable(GL_TEXTURE_2D);	
	DrawFoundation(1.76f, polygonTex->texID);
	DrawPolygon(1.61f, polygonTex2->texID, 0.08f, 0.0f);
	glDisable(GL_TEXTURE_2D);		
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(0.0f, 0.32f,0.0f);
	glEnable(GL_TEXTURE_2D);			
	DrawFoundation(1.68f, polygonTex->texID);
	DrawPolygon(1.53f, polygonTex2->texID, 0.08f, 0.0f);
	glDisable(GL_TEXTURE_2D);			
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(0.0f,0.4f,0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawFoundation(1.6f, polygonTex->texID);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.03f,1.20f,0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawFoundation(0.60f, polygonTex5->texID);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.03f,1.19f,0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawPolygon(0.57f, polygonTex3->texID, 0.08f, 0.0f);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// stripes
	glPushMatrix();
	glTranslatef(-0.03f,1.20f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawPolygon(0.55f, polygonTex4->texID, 1.2f, 0.4f); 
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// góra

	glPushMatrix();

	glRotated(angle, 0, 1, 0);

	glPushMatrix();

	glTranslatef(-0.03f, 2.42f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawFoundation(1.50f, polygonTex6->texID);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// trójk¹ty

	glPushMatrix();

	glTranslatef(-0.03f, 2.40f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawTriangles(polygonTex7->texID, 0.95f, 1.5f, 0.02f);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// siedzenie z zawieszeniem

	glPushMatrix();

	glTranslatef(-0.03f, 2.42f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	DrawLines(polygonTex8->texID, polygonTex9->texID, 1.48f);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPopMatrix();

	if (play->isFalling || play->visible)
	{
		AnimatePlayer(angle - play->startingAngle);
	}

	
	glPushMatrix();

	if (play->visible)
	{
		glDisable(GL_TEXTURE_2D);
		glRasterPos3f(-0.2, 3.5, 5.0);
		float dist = play->CalculateResult(target->position.x, target->position.z - 0.5f);
		glColor3f(1, 0, 0);

		auxDrawStrA("WYNIK");
		
		char str[50];
		sprintf(str, "%f", dist);

		drawDist(str, -0.35, 3.35, 5.0);

	}

	glPopMatrix();

}

void CPolygon::AnimatePlayer(scalar_t deltaTime)
{
	if (deltaTime == 0.0)
	{
		if (play->visible) 
		{
			play->visible = false;
		}

		play->startingAngle = angle;
		play->startingAberration = countAngle(atan((velocity*velocity)/(1.48f*9.81)));
		play->velocity = velocity;
		play->isFalling = true;
	}

	play->Animate(deltaTime);
}


// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CPolygon::SetupTexture()
{

     glGenTextures(1, &polygonTex->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex->texID);
     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
     
     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex->width, polygonTex->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex->image->data);

	 glGenTextures(1, &polygonTex2->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex2->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex2->width, polygonTex2->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex2->image->data);

	 
	 glGenTextures(1, &polygonTex3->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex3->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex3->width, polygonTex3->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex3->image->data);

	 glGenTextures(1, &polygonTex4->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex4->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex4->width, polygonTex4->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex4->image->data);

	 glGenTextures(1, &polygonTex5->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex5->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex5->width, polygonTex5->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex5->image->data);

	 glGenTextures(1, &polygonTex6->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex6->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex6->width, polygonTex6->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex6->image->data);

	 glGenTextures(1, &polygonTex7->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex7->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex7->width, polygonTex7->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex7->image->data);

	 glGenTextures(1, &polygonTex8->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex8->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex8->width, polygonTex8->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex8->image->data);

	 glGenTextures(1, &polygonTex9->texID);
     glBindTexture(GL_TEXTURE_2D, polygonTex9->texID);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     

     gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, polygonTex9->width, polygonTex9->height, 
		 GL_RGB, GL_UNSIGNED_BYTE, polygonTex9->image->data);
}


// Load()
// opis: inicjuje atrybuty obiektu
void CPolygon::Load()
{

	 play = new CPlayer;
	 play->Load();

	 cylinderQuad = gluNewQuadric();
	 gluQuadricDrawStyle(cylinderQuad, GLU_FILL);
	 gluQuadricTexture(cylinderQuad, GL_TRUE); 

	 polygonTex = new CTexture;
     polygonTex->LoadTexture("images/wood.bmp");

	 polygonTex2 = new CTexture;
	 polygonTex2->LoadTexture("images/blue.bmp");

	 polygonTex3 = new CTexture;
	 polygonTex3->LoadTexture("images/lights.bmp");

	 polygonTex4 = new CTexture;
	 polygonTex4->LoadTexture("images/strip2.bmp");

	 polygonTex5 = new CTexture;
	 polygonTex5->LoadTexture("images/yellow.bmp");

	 polygonTex6 = new CTexture;
	 polygonTex6->LoadTexture("images/strip3.bmp");

	 polygonTex7 = new CTexture;
	 polygonTex7->LoadTexture("images/oceanblue.bmp");

	 polygonTex8 = new CTexture;
	 polygonTex8->LoadTexture("images/metal.bmp");

	 polygonTex9 = new CTexture;
	 polygonTex9->LoadTexture("images/chain.bmp");

	 SetupTexture();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CPolygon::Unload()
{
     polygonTex->Unload();
	 polygonTex2->Unload();
	 polygonTex3->Unload();
	 polygonTex4->Unload();
	 polygonTex5->Unload();
	 polygonTex6->Unload();
	 polygonTex7->Unload();
	 polygonTex8->Unload();
	 polygonTex9->Unload();
}