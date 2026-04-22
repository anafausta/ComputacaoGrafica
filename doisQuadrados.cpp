#include <GL/glut.h>

float x1 = 0.0f;
float y1 = 0.0f;
float x2=0.5f;
float y2=0.5f;
float step = 0.1f;

void desenhaQuadrado(float x, float y, float r, float g, float b){
    glLoadIdentity();
    glTranslatef(x,y, 0.0f);

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f( 0.1f, -0.1f);
    glVertex2f( 0.1f,  0.1f);
    glVertex2f(-0.1f,  0.1f);
    glEnd();
}

void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 
 desenhaQuadrado(x1, y1, 1.0, 0.0f, 0.0f);
 desenhaQuadrado(x2, y2, 0.0, 0.0f, 1.0f);
 glutSwapBuffers();
}
void keyboard(unsigned char key,
 int xMouse, int yMouse) {
 switch (key) {
 case 'w': y1 += step; break;
 case 's': y1 -= step; break;
 case 'a': x1 -= step; break;
 case 'd': x1 += step; break;

 case 'i': y2 += step; break;
 case 'k': y2 -= step; break;
 case 'j': x2 -= step; break;
 case 'l': x2 += step; break;

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