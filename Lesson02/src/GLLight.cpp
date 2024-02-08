#include "GLLight.h"

GLLight::GLLight(){
    //ctor
}

GLLight::~GLLight(){
    //dtor
}

GLLight :: GLLight(GLenum Light) {
    glEnable(Light);
    glEnable(GL_LIGHTING);
}

GLvoid GLLight::setLight(GLenum light) {

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    // have my lights we want
    glLightfv(light, GL_AMBIENT,  light_ambient);
    glLightfv(light, GL_DIFFUSE,  light_diffuse);
    glLightfv(light, GL_SPECULAR, light_specular);
    glLightfv(light, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}


