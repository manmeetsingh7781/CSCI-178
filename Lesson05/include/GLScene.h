#ifndef GLSCENE_H
#define GLSCENE_H
#include <windows.h>
#include <GL/glut.h>
#include <iostream>

class GLScene
{
    public:
        GLScene();

        // using dynamic screen size and memory space depending on device
        GLint initGL();


        GLint drawScene();

        // for window resize
        GLint resizeScene(GLsizei, GLsizei);

        // windows input mapping
        int windowsMsg(HWND, UINT, WPARAM, LPARAM);

        // keyboard mouse message
        WPARAM wParam;

        virtual ~GLScene();
    protected:
    private:
};

#endif // GLSCENE_H
