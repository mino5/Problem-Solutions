#ifndef __POLYGON_H
#define __POLYGON_H

#define MAX_TEXTURES 10

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <gl/glut.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"
#include "player.h"
#include "target.h"

class CPolygon : public CObject
{
private:
     CTexture* polygonTex;    
	 CTexture* polygonTex2;
	 CTexture* polygonTex3;
	 CTexture* polygonTex4;
	 CTexture* polygonTex5;
	 CTexture* polygonTex6;
	 CTexture* polygonTex7;
	 CTexture* polygonTex8;
	 CTexture* polygonTex9;
	 GLUquadric* cylinderQuad;

public:

     CPolygon() 
     {
          position = CVector(0.0, 0.0, 0.0);
		  angle = 0.0f;
		  camera = false;
     }

     ~CPolygon()
     {}

     void Load();
     void Unload();

	 void DrawPolygon(float radius, GLuint texture, float height, float radiusDifference);
	 void DrawFoundation(float radius, GLuint texture);
	 void DrawTriangles(GLuint texture, float radius, float radius2, float heightDifference);
	 void DrawLines(GLuint metalTex, GLuint chainTex, float radius);
     void Draw();
     void SetupTexture();

	 CTarget* target;
	 CPlayer* play;
	 double angle;
	 bool camera;
	 double radian(double a);
	 double countAngle(double rad);
	 void AnimatePlayer(scalar_t deltaTime);
};


#endif 