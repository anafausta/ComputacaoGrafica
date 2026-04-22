#include <GL/glut.h>

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex2f(-0.5f, 0.5f);    
    glVertex2f(0.5f, 0.5f);    
    glVertex2f(0.5f, -0.5f);    
    glVertex2f(-0.5f, -0.5f);    
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f(-0.5f, 0.5f);     
    glVertex2f(0.5f, 0.5f);     
    glVertex2f(0.0f, 1.0f);    
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex2f(-0.4f, -0.5f);    
    glVertex2f(-0.4f, -0.1f);    
    glVertex2f(-0.2f, -0.1f);    
    glVertex2f(-0.2f, -0.5f); 
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.1f, -0.1f);     
    glVertex2f(0.4f, -0.1f);    
    glVertex2f(0.4f, 0.2f); 
    glVertex2f(0.1f, 0.2f); 
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Triangulo Clássico com GLUT");
    glutDisplayFunc(desenhaCena);
    glutMainLoop();

    return 0;
}