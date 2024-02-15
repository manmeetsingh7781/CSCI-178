#ifndef GLINPUTS_H
#define GLINPUTS_H
#include "GLModel.h"
#include <windows.h>

/*
    Passing values from keyboard into OpenGL
    This class handles input mapping of objects

    // WPARAM is mouse or keyboard events
    // LPARAM is also used for keyboard events
    WPARAM	wParam
    LPARAM	lParam

*/
class GLInputs
{
    public:
        GLInputs();
        virtual ~GLInputs();

        // when key is pressed
        void keyPress(GLModel *);

        // when key is released
        void keyUp(GLModel *);


        // mouse events

        // mouse button pressed
        void mouseEventDown(GLModel *, double, double);

        // mouse button released
        void moseEventUp();

        // mouse wheel rolled
        void mouseWheel(GLModel *, double);


        // mouse location x and y on a graph before event
        void mouseMove(GLModel *, double, double);

        // previous axis of mouse before event happened
        double prev_mouseX, prev_mouseY;

        // if mouse moved
        bool mouse_Translate, mouse_Rotate;

        // mapping input interrupts coming from keyboard
        WPARAM wParam;


    protected:
    private:
};

#endif // GLINPUTS_H
