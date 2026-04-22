#include <GL/glut.h>

float step = 0.1f;
float r=1.0f;
float g=0.075f;
float b=0.94f;

void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glBegin(GL_QUADS);
 glColor3f(r, g, b);
 glVertex2f(-0.1f, -0.1f);
 glVertex2f( 0.1f, -0.1f);
 glVertex2f( 0.1f, 0.1f);
 glVertex2f(-0.1f, 0.1f);
 glEnd();
 glutSwapBuffers();
}
void keyboard(unsigned char key,
 int xMouse, int yMouse) {
 switch (key) {
 case '1': r=1.0f,g=0.0f,b=0.0f; break;
 case '2': r=0.0f,g=1.0f,b=0.0f; break;
 case '3': r=0.0f,g=0.0f,b=1.0f; break;
 case 27: exit(0); 
 }
 glutPostRedisplay();
}
void init() {
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Controle com Teclado - OpenGL");
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}
