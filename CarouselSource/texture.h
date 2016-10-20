#ifndef __TEXTURE_H
#define __TEXTURE_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glaux.h>
#include <gl/gl.h>
#include <gl/glu.h>

#define BITMAP_ID 0x4D42		// identyfikator pliku BMP


class CTexture
{
private:
	long int scaledWidth;
	long int scaledHeight;

	unsigned char *palette;

	AUX_RGBImageRec *LoadBitmapFile(char *Filename);

	void LoadBMPTexture(char *filename);

public:

	int width;
	int height;
	unsigned int texID;

	AUX_RGBImageRec *image;

	CTexture() { image = NULL; palette = NULL; }
	~CTexture() {}

	
    bool LoadTexture(char * fileName);
	void Unload()
	{
		glDeleteTextures(1, &texID);

		if (image != NULL)
			free(image);
		if (palette != NULL)
			free(palette);
		
		image = NULL;
		palette = NULL;
	}
};


#endif