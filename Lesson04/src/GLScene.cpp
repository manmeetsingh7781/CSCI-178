#include "GLScene.h"
#include "GLLight.h"
#include "GLTexture.h"
#include "GLModel.h"

GLTexture *textureImage     = new GLTexture();
GLModel   *testPotModel            = new GLModel();

// test object only
GLModel   *testPotModel2            = new GLModel();

GLScene::GLScene()
{
    //initialize the position of test pot
    testPotModel2->xPos = 5;
    testPotModel2->yPos = 3;
    testPotModel2->RotateX = 45; // 45 deg rotation
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL() {
    // for smooth render
    glShadeModel(GL_SMOOTH);

    // background color of scene
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);

    // depth test for layers
    glClearDepth(1.0f);

    // enable depth test
    glEnable(GL_DEPTH_TEST);

    // depth function type
    glDepthFunc(GL_LEQUAL);

    GLLight Light(GL_LIGHT0);

    Light.setLight(GL_LIGHT0);

    // enable textures
    glEnable(GL_TEXTURE_2D);

    // load texture handler

    textureImage->loadTexture("images/download.jpg");

    return true;
}

// infinite loop
GLint GLScene::drawScene() {

    // clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // translate object to x y z
    glTranslatef(0.0, 0.0, -8.0);

    // color the object red (RGB)
    glColor3f(1.0, 0.0,0.0);

    // activate texture
    textureImage->bindTexture();

    // group object
    glPushMatrix();

    // load and render object
    // inserted into GL Model drawModel() method ->   glutSolidTeapot(1.5);
    testPotModel->drawModel();
    testPotModel2->drawModel();

    // exit group
    glPopMatrix();
    return true;
}


GLint GLScene::resizeScene(GLsizei width, GLsizei height) {
     // keep track of ratio
    GLfloat aspectRatio = (GLfloat) width /(GLfloat) height;

    // adjusting the view port of screen when resizing
    glViewport(0,0,width, height);

    // changes the size of object player is looking at based on the distance
    // gets smaller when player is far, and bigger when player is closer
    // closest view is 0.1 and furtherest is 100
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    // this is the angle of projection for player looking at the object from a distance x
    // 0.1 is closest
    // 100 is furtherest
    gluPerspective(45, aspectRatio, 0.1, 100.0);


    // when ever we change screen size it has to adjust the inner content of the application
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    return true;
}





