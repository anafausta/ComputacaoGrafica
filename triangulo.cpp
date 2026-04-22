#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, -0.8f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.8f, -0.8f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.8f);

    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Triângulo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}