#include <GL/glut.h>

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;
float r=0.0f;
float g=0.0f;
float b=1.0f;
float multiplicador =1.0f;

void desenharQuadrado (float x, float y, float r, float g, float b){
    float tamanho=0.1f;
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x-tamanho *multiplicador, y-tamanho *multiplicador);
    glVertex2f(x+ tamanho  *multiplicador, y-tamanho  *multiplicador);
    glVertex2f(x+ tamanho  *multiplicador, y+tamanho *multiplicador);
    glVertex2f(x-tamanho *multiplicador, y+tamanho  *multiplicador);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    desenharQuadrado(x, y, r, g,b);
    glFlush();
}

void keyboard(unsigned char key,
 int xMouse, int yMouse) {
 switch (key) { //recebe a opção do teclado
 case 'w': y += step; break; //se a tecla for 'w' o objeto vai para cima
 case 's': y -= step; break; //se a tecla for 's' o objeto vai para baixo
 case 'a': x -= step; break; //se a tecla for 'a' o objeto vai para a esquerda
 case 'd': x += step; break; //se a tecla for 'd' o objeto vai para a direita
 case '+': multiplicador +=0.1f; break;
 case '-': multiplicador -=0.1f;break; 
}
 glutPostRedisplay(); 
}

void mouse(int buttom, int state, int xinutil, int yinutil) {
    switch (buttom) { //identifica as opções do mouse
        case GLUT_LEFT_BUTTON: //caso a aperte o botão esquerdo do mouse
            r=1.0f,g=0.0f,b=0.0f; //definição da cor vermelha
            glutPostRedisplay(); 
            break;
        case GLUT_RIGHT_BUTTON:
            r=0.0f,g=0.0f,b=1.0f;//definição da cor azul
            glutPostRedisplay(); 
            break;
        case GLUT_MIDDLE_BUTTON:
            x=0.0f, y=0.0f;
            break;
    } 
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Controle com Teclado - OpenGL");
 glClearColor(0.0,0.0,0.0,1.0);
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}