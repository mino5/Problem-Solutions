#ifndef __TARGET_H
#define __TARGET_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <math.h>
#include "vector.h"
#include "object.h"
#include "texture.h"


class CTarget : public CObject
{
private:
     CTexture* targetTex;    

public:

     CTarget() 
     {
          position = CVector(0.0, 0.0, 0.0);
     }

     ~CTarget()
     {}

     void Load();
     void Unload();

     void Draw();
     void SetupTexture();
};


#endif 