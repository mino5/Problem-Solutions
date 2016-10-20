#include "sky.h"


void CSky::Draw()
{

	glPushMatrix();
	glRotated(rot_x, 1.0, 0.0, 0.0);	
	glRotated(rot_y, 0.0, 1.0, 0.0);	

	glColor3f(1.0f,1.0f,1.0f);			
	glEnable(GL_TEXTURE_2D);			
	glDisable (GL_DEPTH_TEST);			

		glBindTexture(GL_TEXTURE_2D, texture[0 + text_offset]);

		glBegin (GL_QUADS);		
		
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET,0.0 + OFFSET);	glVertex3d (-10.0,-10.0,10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET,0.0 + OFFSET);	glVertex3d (-10.0,-10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET,1.0 - OFFSET);	glVertex3d (-10.0,10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET,1.0 - OFFSET);	glVertex3d (-10.0,10.0,10.0);

		glEnd ();				

		glBindTexture(GL_TEXTURE_2D, texture[1 + text_offset]);
		glBegin (GL_QUADS);
		
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET,0.0 + OFFSET);	glVertex3d (-10.0,-10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET,0.0 + OFFSET);	glVertex3d (10.0,-10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET,1.0 - OFFSET);	glVertex3d (10.0,10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET,1.0 - OFFSET);	glVertex3d (-10.0,10.0,-10.0);
		glEnd ();

		glBindTexture(GL_TEXTURE_2D, texture[2 + text_offset]);
		glBegin (GL_QUADS);
		
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,0.0 + OFFSET); glVertex3d (10.0,-10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,0.0 + OFFSET); glVertex3d (10.0,-10.0,10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,1.0 - OFFSET); glVertex3d (10.0,10.0,10.0);
				glNormal3d (0.0,0.0,10.0); glTexCoord2d (0.0 + OFFSET ,1.0 - OFFSET); glVertex3d (10.0,10.0,-10.0);

		glEnd ();

		glBindTexture(GL_TEXTURE_2D, texture[3 + text_offset]);	
		glBegin (GL_QUADS);
			
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,0.0 + OFFSET); glVertex3d (10.0,-10.0,10.0);
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,0.0 + OFFSET); glVertex3d (-10.0,-10.0,10.0);
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,1.0 - OFFSET); glVertex3d (-10.0,10.0,10.0);
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,1.0 - OFFSET); glVertex3d (10.0,10.0,10.0);
		
		glEnd ();

		glBindTexture(GL_TEXTURE_2D, texture[4 + text_offset]);	
		glBegin (GL_QUADS);
			
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,0.0 + OFFSET); glVertex3d (-10.0,-10.0,10.0);
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,0.0 + OFFSET); glVertex3d (10.0,-10.0,10.0);
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,1.0 - OFFSET); glVertex3d (10.0,-10.0,-10.0);
			glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,1.0 - OFFSET); glVertex3d (-10.0,-10.0,-10.0);
		
		glEnd ();

		glBindTexture(GL_TEXTURE_2D, texture[5 + text_offset]);
		glBegin (GL_QUADS);
		
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,0.0 + OFFSET); glVertex3d (-10.0,10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,0.0 + OFFSET); glVertex3d (10.0,10.0,-10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (1.0 - OFFSET ,1.0 - OFFSET); glVertex3d (10.0,10.0,10.0);
				glNormal3d (0.0,0.0,1.0); glTexCoord2d (0.0 + OFFSET ,1.0 - OFFSET); glVertex3d (-10.0,10.0,10.0);
				
		glEnd ();

	glEnable(GL_DEPTH_TEST);
	
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

// Animate()

void CSky::Animate(scalar_t deltaTime) {}



bool CSky::LoadTexture(unsigned int & aTexture, char * fileName) 
{

	if(!fileName) return false;					//if no file name is given return

	FILE *aFile = NULL;
	AUX_RGBImageRec *image_record = NULL;

	if((aFile = fopen(fileName, "rb")) == NULL) return false;

	image_record = auxDIBImageLoadA(fileName);	//Function to load BMP

	if(!image_record) return false;				//check that BMP loaded

	glGenTextures(1, &aTexture);				//generates 1 texture name

	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);		//sets how the pixels of the texture are stored

	glBindTexture(GL_TEXTURE_2D, aTexture);		//binds the name to the target
	

												//build prefiltered textures at different resolutions
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image_record->sizeX, 
					  image_record->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image_record->data);

												//give the texture its attributes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Now we need to free the image data that we loaded since openGL stored it as a texture
	if (image_record) {							//if we stored data then free the memory
		if (image_record->data) {				//check if there is any data
			free(image_record->data);			//free the memory
		}
		free(image_record);						//free the image record
	}

	return true; //everything should have worked so return true
}

// SetupTexture()
// opis: inicjuje teksturê OpenGL
void CSky::SetupTexture()
{

	OFFSET = 1/512.0; //set offset value for skybox

	rot_x = 0.0; rot_y = 0.0;



	//load third set of skybox textures
	LoadTexture(texture[0],"images/lefttron.bmp");
	LoadTexture(texture[1],"images/fronttron.bmp");
	LoadTexture(texture[2],"images/righttron.bmp");
	LoadTexture(texture[3],"images/backtron.bmp");
	LoadTexture(texture[4],"images/downtron.bmp");  //images/downtron
	LoadTexture(texture[5],"images/uptron.bmp");
}

// Load()
// opis: inicjuje atrybuty obiektu
void CSky::Load()
{
	text_offset = 0;
	SetupTexture();
}

// Unload()
// opis: zwalnia pamiêæ zajmowan¹ przez teskturê
void CSky::Unload()
{
     
}