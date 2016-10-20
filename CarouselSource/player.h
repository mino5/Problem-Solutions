#ifndef __PLAYER_H
#define __PLAYER_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"


class CPlayer : public CObject
{
private:
     CTexture* playerTex; 

public:

     CPlayer() 
     {
          position = CVector(0.0, 0.0, 0.0);
		  isFalling = false;
		  visible = false;
     }

     ~CPlayer()
     {}

     void Load();
     void Unload();
	 float CalculateResult(float targetx, float targetz);

     void Draw();
     void SetupTexture();
	 void Animate(scalar_t deltaTime);

	 float startingAngle;
	 float startingAberration;
	 float velocity;
	 float storedx;
	 float storedy;
	 bool isFalling;
	 bool visible;
};


#endif 