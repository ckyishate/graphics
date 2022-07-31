#include<GL/freeglut.h>
#include<stdio.h>

static void RenderSceneCB(){

    static GLclampf c = 0.0f;
    glClearColor(c, c, c, c); 

    c += 1.0f/256.0f;

    if( c >= 1.0f){
        c = 0.0f;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    glutSwapBuffers();
}


int main(int argc , char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


    int height = 1090;
    int weight = 2000;
    glutInitWindowSize(height, weight);

    int x = 20;
    int y= 30;

    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("Hello world");

    GLclampf Red  = 0.0f, Green =0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);


    glutDisplayFunc(RenderSceneCB);
    glutMainLoop();
    return 0;
}