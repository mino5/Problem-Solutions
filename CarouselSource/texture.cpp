#include "texture.h"

// LoadBitmapFile
// desc: Returns a pointer to the bitmap image of the bitmap specified
//       by filename. Also returns the bitmap header information.
//		 No support for 8-bit bitmaps.
AUX_RGBImageRec *CTexture::LoadBitmapFile(char *filename)
{
	FILE *File = NULL;

	if (!filename)
	{
		return NULL;
	}

	File = fopen(filename, "r");

	if (File)
	{
		fclose(File);
		return auxDIBImageLoadA(filename);
	}

	return NULL;
}



bool CTexture::LoadTexture(char * fileName) 
{

	if(!fileName) return false;					//if no file name is given return

	FILE *aFile = NULL;

	if((aFile = fopen(fileName, "rb")) == NULL) return false;

	image = auxDIBImageLoadA(fileName);	//Function to load BMP

	if(!image) return false;				//check that BMP loaded

		// store texture information
	width = image->sizeX;
	height = image->sizeY;
	palette = NULL;
	scaledHeight = 0;
	scaledWidth = 0;

	//// Now we need to free the image data that we loaded since openGL stored it as a texture
	//if (image_record) {							//if we stored data then free the memory
	//	if (image_record->data) {				//check if there is any data
	//		free(image_record->data);			//free the memory
	//	}
	//	free(image_record);						//free the image record
	//}

	return true; //everything should have worked so return true
}
	
