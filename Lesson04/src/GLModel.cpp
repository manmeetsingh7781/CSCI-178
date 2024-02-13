#include "GLModel.h"

GLModel::GLModel()
{
    // default object positions
    RotateX = 0.0;
    RotateY = 0.0;
    RotateZ = 0.0;
    // zoom = -8.0;
    xPos = 0.0;
    yPos = 0.0;
    zPos = -8.0;

}

GLModel::~GLModel()
{
    //dtor
}


void GLModel::drawModel(){
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(xPos, yPos, zPos);
    glRotatef(RotateX, 1, 0, 0);
    glRotatef(RotateY, 1, 0, 0);
    glRotatef(RotateZ, 1, 0, 0);

    glutSolidTeapot(1.5);


}
