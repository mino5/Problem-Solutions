#ifndef __SKY_H
#define __SKY_H

#define MAX_TEXTURES 24

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"


class CSky : public CObject
{
private:
     CTexture* skyTex;              // tekstura nieba
	 


public:

     CSky() 
     {
          position = CVector(0.0, 0.0, 0.0);
     }

     ~CSky()
     {}

     void Load();
     void Unload();

     void Draw();
     void Animate(scalar_t deltaTime);
     void SetupTexture();
	 bool LoadTexture(unsigned int & aTexture, char * fileName);


	GLuint	texture[MAX_TEXTURES];

	//used to correct the edges of the skybox overlap
	//try setting this to 0.0 in the Init() and you will see the seams of the textures
	double	OFFSET,	rot_x, rot_y;
	long	text_offset;

};


#endif 