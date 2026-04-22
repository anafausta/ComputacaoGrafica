#include <GL/glut.h>
#include <math.h>

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;
float cx=0.1f;
float cy=0.1f;
float r=0.5f;
int num_segments=50;

void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(x, y, 0.0f);
 glBegin(GL_TRIANGLE_FAN);
 glColor3f(1.0f, 0.0f, 0.0f);
 
 glVertex2f(cx, cy); 
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); 
        float x = r * cosf(theta); 
        float y = r * sinf(theta); 
        glVertex2f(x + cx, y + cy); 
    }
    glEnd();
 glutSwapBuffers();
}
void keyboard(unsigned char key,
 int xMouse, int yMouse) {
 switch (key) {
 case 'w': y += step; break;
 case 's': y -= step; break;
 case 'a': x -= step; break;
 case 'd': x += step; break;
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