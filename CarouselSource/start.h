#ifndef __START_H
#define __START_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"


class CStart : public CObject
{
private:
     CTexture* startTex;    


public:

     CStart() 
     {
          position = CVector(0.0, 0.0, 0.0);
     }

     ~CStart()
     {}

     void Load();
     void Unload();

     void Draw();
     void Animate(scalar_t deltaTime);
     void SetupTexture();
};


#endif 