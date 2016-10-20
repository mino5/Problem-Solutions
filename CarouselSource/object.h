#ifndef __OBJECT_H
#define __OBJECT_H

#include "vector.h"

class CObject
{
public:
     CVector position;        // po³o¿enie obiektu
     float velocity;        // prêdkoœæ obiektu
     CVector acceleration;    // przyspieszenie obiektu
     scalar_t size;           // promieñ sfery

public:
     CObject() {};            // konstruktor
     ~CObject() {};           // destruktor

     virtual void Load() = 0;      // ³aduje obiekt do pamiêci
     virtual void Unload() = 0;    // zwalnia pamiêæ zajmowan¹ przez obiekt
     virtual void Draw() = 0;      // rysuje obiekt

};


#endif