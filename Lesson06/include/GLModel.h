#ifndef GLMODEL_H
#define GLMODEL_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/Glut.h>


// scale, rotation, move and translation of an object

class GLModel
{
    public:
        GLModel();
        virtual ~GLModel();

        // position and rotation of an object
        GLfloat RotateX, RotateY, RotateZ, xPos, yPos, zPos;

        // to draw a model
        void drawModel();

    protected:
    private:
};

#endif // GLMODEL_H
