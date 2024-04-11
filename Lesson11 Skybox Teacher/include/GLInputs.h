#ifndef GLINPUTS_H
#define GLINPUTS_H

#include<GLModel.h>
#include<GLParallax.h>
#include<GLPlayer.h>
#include<GLSounds.h>
#include<common.h>
#include<GLSkyBox.h>

class GLInputs
{
    public:
        GLInputs();
        virtual ~GLInputs();

        void keyPress(GLModel *, GLPlayer*);  // when key pressed
        void keyUP(GLPlayer*);               // when key released
        void keyBackground(GLParallax *, float);//parallax model & speed


        void mouseEventDown(GLModel*, double, double); // mouse btn pressed
        void mouseEventUp();                                // mouse btn released
        void mouseWheel(GLModel*,double);              // mouse wheel rolled
        void mouseMove(GLModel*, double,double);       // mouse moved

        double prev_MouseX;      // current mouse location X before action
        double prev_MouseY;      // current mouse location Y before action

        bool mouse_Translate;    // if mouse moved
        bool mouse_Rotate;       // if mouse moved for rotation

        void keyPressed(GLSounds *);
        void keyPressed(GLSkyBox *);
        void mouseMove(GLSkyBox*, double,double);       // mouse moved

        WPARAM wParam;           // catching input interrupts

    protected:

    private:
};

#endif // GLINPUTS_H
