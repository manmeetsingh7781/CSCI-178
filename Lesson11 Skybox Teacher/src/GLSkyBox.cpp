#include "GLSkyBox.h"

GLSkyBox::GLSkyBox()
{
    //ctor
}

GLSkyBox::~GLSkyBox()
{
    //dtor
}

void GLSkyBox::skyBoxInit()
{
   //  glGenTextures(6,tex);
   skyBoxTexture();
   Trans.x=Trans.y=Trans.z =0;
   Rot.x=Rot.y=Rot.z;


}

void GLSkyBox::skyBoxScroll(bool, string, float)
{

}

void GLSkyBox::skyBoxTexture()
{
    background[0].loadTexture("images/sky/front.jpg");
    background[1].loadTexture("images/sky/back.jpg");
    background[2].loadTexture("images/sky/bottom.jpg");
    background[3].loadTexture("images/sky/top.jpg");
    background[4].loadTexture("images/sky/left.jpg");
    background[5].loadTexture("images/sky/right.jpg");
   // tex[0]= background->tex;

}



void GLSkyBox::skyBoxDraw()
{
     glRotatef(Rot.x, 1,0,0);
     glRotatef(Rot.y, 0,1,0);
     glRotatef(Rot.z, 0,0,1);
     glTranslatef(Trans.x,Trans.y,Trans.z);
     glScalef(200,100,200);

     //front face
     background[0].bindTexture();
     glBegin(GL_QUADS);
     glTexCoord2f(0,0);glVertex3f(-1,1,1);
     glTexCoord2f(1,0);glVertex3f( 1,1,1);
     glTexCoord2f(1,1);glVertex3f( 1,-1,1);
     glTexCoord2f(0,1);glVertex3f(-1,-1,1);
     glEnd();

     //Back face
     background[1].bindTexture();
     glBegin(GL_QUADS);
     glTexCoord2f(1,0);glVertex3f(-1,1,-1);
     glTexCoord2f(1,1);glVertex3f(-1,-1,-1);
     glTexCoord2f(0,1);glVertex3f(1,-1,-1);
     glTexCoord2f(0,0);glVertex3f(1,1,-1);
     glEnd();

     //bottom Face
     background[2].bindTexture();
     glBegin(GL_QUADS);
     glTexCoord2f(1,1);glVertex3f(-1,-1,1);
     glTexCoord2f(0,1);glVertex3f( 1,-1,1);
     glTexCoord2f(0,0);glVertex3f( 1,-1,-1);
     glTexCoord2f(1,0);glVertex3f(-1,-1,-1);
     glEnd();

     //top
     background[3].bindTexture();
     glBegin(GL_QUADS);
     glTexCoord2f(0,1);glVertex3f( 1,1,-1);
     glTexCoord2f(0,0);glVertex3f( 1,1,1);
     glTexCoord2f(1,0);glVertex3f(-1,1,1);
     glTexCoord2f(1,1);glVertex3f(-1,1,-1);
     glEnd();

     //Right Face
     background[4].bindTexture();
     glBegin(GL_QUADS);
     glTexCoord2f(1,0);glVertex3f( 1,1,-1);
     glTexCoord2f(1,1);glVertex3f( 1,-1,-1);
     glTexCoord2f(0,1);glVertex3f( 1,-1,1);
     glTexCoord2f(0,0);glVertex3f( 1,1,1);
     glEnd();

     //left Face
     background[5].bindTexture();
     glBegin(GL_QUADS);
     glTexCoord2f(0,0);glVertex3f(-1,1,-1);
     glTexCoord2f(1,0);glVertex3f( -1,1,1);
     glTexCoord2f(1,1);glVertex3f( -1,-1,1);
     glTexCoord2f(0,1);glVertex3f(-1,-1,-1);
     glEnd();

}
