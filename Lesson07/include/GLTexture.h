#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "common.h"
using namespace std;


class GLTexture
{
    public:
        GLTexture();
        virtual ~GLTexture();
        GLuint tex;
        GLint width, height;

        // read the image context - a char array
        unsigned char * image;
        // loads image data
        void loadTexture(char *);
        // display loaded image to the screen
        void bindTexture();


    protected:
    private:
};

#endif // GLTEXTURE_H
