#include "GLTexture.h"

GLTexture::GLTexture()
{
    //ctor
}

GLTexture::~GLTexture()
{
    //dtor
}
void GLTexture::loadTexture(char* fileName)
{
    // a handler to handle the texture
    glGenTextures(1, &tex);

    // pointing handler to the texture data format
    glBindTexture(GL_TEXTURE_2D, tex);

    // can be any image formate to render
    image = SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGBA);

    if(!image) {
        cout << "ERROR: Image not found" << endl;
    }

    // store image data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, image);

    // delete image holder
    SOIL_free_image_data(image);

    // how to wrap on object in x direction
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    // how to wrap on object in y direction

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // decide the quality of image in x direction

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


    // decide the quality of the image in y direction
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void GLTexture::bindTexture(){
    glBindTexture(GL_TEXTURE_2D, tex);
}
