#include "GLScene.h"
#include "GLLight.h"
#include "GLTexture.h"
#include "GLModel.h"
#include "GLInputs.h"

GLTexture *textureImage     = new GLTexture();

// event mapping through keyboard and mouse
GLInputs  *KeyboardMouse    = new GLInputs();
GLModel   *testPotModel     = new GLModel();

// test object only
GLModel   *testPotModel2    = new GLModel();

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



// call this function in main.cpp
// this function handles incoming events from main.cpp and binds it
// so that we can send control movements from this file to even handler like GLInput.cpp
int GLScene::windowsMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lparam){

     KeyboardMouse->wParam = wParam;

    // message being recieved from input
    switch(uMsg) {

    // windows mouse key down event, this is responsible for reflecting key events to object
    case WM_KEYDOWN:
        // object to perform operations on
        KeyboardMouse->keyPress(testPotModel);
        break;


    case WM_KEYUP:
        KeyboardMouse->keyUp(testPotModel);
        break;

    case WM_LBUTTONDOWN:
        // passing x and y to the mouse event
        KeyboardMouse->mouseEventDown(testPotModel, LOWORD(lparam), HIWORD(lparam));
        break;

    case WM_RBUTTONDOWN:

        // passing x and y to the mouse event
        KeyboardMouse->mouseEventDown(testPotModel, LOWORD(lparam), HIWORD(lparam));
        break;

    // multiple cases for mouse button left middle and right
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KeyboardMouse->moseEventUp();
        break;


    // mouse move event from scene to event handler
    case WM_MOUSEMOVE:
        KeyboardMouse->mouseMove(testPotModel, LOWORD(lparam), HIWORD(lparam));
        break;

    // mouse wheel movement from scene to event handler
    case WM_MOUSELAST:
        KeyboardMouse->mouseWheel(testPotModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
    }
}




