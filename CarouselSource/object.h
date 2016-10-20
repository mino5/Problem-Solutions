#ifndef __OBJECT_H
#define __OBJECT_H

#include "vector.h"

class CObject
{
public:
     CVector position;        // po�o�enie obiektu
     float velocity;        // pr�dko�� obiektu
     CVector acceleration;    // przyspieszenie obiektu
     scalar_t size;           // promie� sfery

public:
     CObject() {};            // konstruktor
     ~CObject() {};           // destruktor

     virtual void Load() = 0;      // �aduje obiekt do pami�ci
     virtual void Unload() = 0;    // zwalnia pami�� zajmowan� przez obiekt
     virtual void Draw() = 0;      // rysuje obiekt

};


#endif