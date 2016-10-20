#ifndef __GROUND_H
#define __GROUND_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"


class CGround : public CObject
{
private:
     CTexture* groundTex;              // tekstura ziemi

public:
    // float tableCorners[4][3];     // wspó³rzêdne naro¿ników
    // CPlane tableWalls[4];         // p³aszczyzny band	

     CGround() 
     {
          position = CVector(0.0, 0.0, 0.0);
     }

     ~CGround()
     {}

     void Load();
     void Unload();

     void Draw();
     void Animate(scalar_t deltaTime);
     void SetupTexture();
};


#endif 