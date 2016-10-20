#ifndef __STAND_H
#define __STAND_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <GL/glext.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"


class CStand : public CObject
{
private:
     CTexture* standTex;    
	 CTexture* standTex2;
	 CTexture* standTex3;
	 CTexture* standTex4;
	 CTexture* standTex5;

public:

     CStand() 
     {
          position = CVector(0.0, 0.0, 0.0);
     }

     ~CStand()
     {}

     void Load();
     void Unload();

	 void DrawStand(float heightDifference);
	 void DrawStandPiece1(float heightDifference);
	 void DrawStandPiece2(float heightDifference);
	 void DrawStandPiece3(float heightDifference);
	 void DrawStandPiece4(float heightDifference);
	 void DrawStandPiece5(float heightDifference);
     void Draw();
     void Animate(scalar_t deltaTime);
     void SetupTexture();
};


#endif 