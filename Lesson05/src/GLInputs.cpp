#include "GLInputs.h"


GLInputs::GLInputs()
{
    // initialize mouse values
    prev_mouseX = 0.0;
    prev_mouseY = 0.0;

    mouse_Translate = false;
    mouse_Rotate = false;
}

GLInputs::~GLInputs()
{
    //dtor
}

// when key is pressed, reflect the event onto the object
void GLInputs::keyPress(GLModel* model){
   // wParam accepts keyboard binding, which we can use to extract keys being pressed

  cout<<"got "<<wParam<<endl;

    switch (wParam) {


    // when left key is pressed
    case VK_LEFT:



        model->RotateX += 1.0;
        break;

    case VK_RIGHT:
        model->RotateX -= 1.0;
        break;

    case VK_DOWN:
        model->RotateY -= 1.0;
        break;

    case VK_UP:
        model->RotateY += 1.0;
        break;

    case VK_ADD:
        model->zPos += 1.0;
        break;

    case VK_SUBTRACT:
        model->zPos -= 1.0;
        break;

    }
}

void GLInputs::keyUp(GLModel*){
    switch(wParam) {
    default:
        break;
    }
}

void GLInputs::mouseEventDown(GLModel*, double, double)
{

}

void GLInputs::moseEventUp()
{

}

void GLInputs::mouseWheel(GLModel*, double)
{

}

void GLInputs::mouseMove(GLModel*, double, double)
{

}
