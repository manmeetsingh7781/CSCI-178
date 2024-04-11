#ifndef GLSKYBOX_H
#define GLSKYBOX_H
#include<common.h>

#include<GLTexture.h>
#include<GLTimer.h>

class GLSkyBox
{
    public:
        GLSkyBox();
        virtual ~GLSkyBox();

        GLTexture background[6];// = new GLTexture();
        GLTimer   *myTime = new GLTimer();

        void skyBoxInit();// load background file
        void skyBoxScroll(bool,string,float); // auto, direction, speed
        void skyBoxDraw(); // width and height
        void skyBoxTexture();
        float xMax,xMin,zMin,yMax,yMin,zMax;

        float width,height,depth;
        GLuint tex[6];

        vec3 Rot;   // for rotation
        vec3 Trans;

    protected:

    private:
};

#endif // GLSKYBOX_H
