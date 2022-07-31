#include<GL/glut.h>

const GLsizei  windowWidth = 500;
const GLsizei windowHeight = 500;

GLvoid establishProjectionMatrix(GLsizei width, GLsizei height){
    glViewport(0,0,width, height);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 200.0f);
}
GLvoid initGL(GLsizei width, GLsizei height){

    establishProjectionMatrix(width, height);

    glShadeModel(GL_SMOOTH);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
      
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_PERSPECTIVE_CORRECTION_HINT);

}

GLvoid drawScene(GLvoid){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -5.0f);


    //Draw cube
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.0f);

        //top face
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);

        //bottom face
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        //front face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        //back face
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        //left face
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);


        //Rightface 
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);

    glEnd();

    glFlush();
    glutSwapBuffers();
}
GLvoid timerLoop(int value){

    glutPostRedisplay();
    glutTimerFunc(1, timerLoop, 0);
    
}


int main(int argc, char *argv[]){

    //intialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    int windowID = glutCreateWindow("Open GL demo");
    glutReshapeWindow(windowWidth, windowHeight);

    initGL(windowWidth, windowHeight);

    glutDisplayFunc(drawScene);

    glutTimerFunc(1, timerLoop, 0);

    glutMainLoop();

    //it never gets here
    return 0;
}