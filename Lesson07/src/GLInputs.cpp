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

    switch (wParam) {

    // when left key is pressed
    case VK_LEFT:
        model->RotateY -= 1.0;
        break;

    case VK_RIGHT:
        model->RotateY += 1.0;
        break;

    case VK_DOWN:
        model->RotateX -= 1.0;
        break;

    case VK_UP:
        model->RotateX += 1.0;
        break;

    case VK_ADD:
        model->zPos += 1.0;
        break;

    case VK_SUBTRACT:
        model->zPos -= 1.0;
        break;

    }
}

void GLInputs::keyUp(GLModel* model){
    switch(wParam) {
    default:
        break;
    }
}

void GLInputs::mouseEventDown(GLModel* model, double x, double y){

    // keep track of previous mouse movements
    prev_mouseX = x;
    prev_mouseY = y;

    switch(wParam) {

        // rotation flags
        case MK_LBUTTON:
            mouse_Rotate = true;
            break;

        case MK_RBUTTON:
            mouse_Translate = true;
            break;

        case MK_MBUTTON:
            // mouse middle button
            break;

        default:
            break;
    }

}

void GLInputs::moseEventUp(){
    // reset flags when mouse button is released
    mouse_Rotate = false;
    mouse_Translate = false;
}

void GLInputs::mouseWheel(GLModel* model, double delta){
    // mouse scroll movement it will zoom in and out of an object
    model->zPos += delta / 100;
}

void GLInputs::mouseMove(GLModel* model, double x, double y){
    if (mouse_Translate) {

        // move the object with respect to mouse position
        model->xPos += (x - prev_mouseX) / 100;
        model->yPos += (y - prev_mouseY) / 100;

        // update previous mouse values
        prev_mouseX = x;
        prev_mouseY = y;
    }

    if (mouse_Rotate) {

        // rotate the object with respect to previous rotation
        // x / 3 ? <- maybe a moving speed of an object?
        // rotation of model on the x and y axis
        model->RotateY += (x - prev_mouseX) / 3;
        model->RotateX += (y - prev_mouseY) / 3;

        prev_mouseX = x;
        prev_mouseY = y;

    }
}
