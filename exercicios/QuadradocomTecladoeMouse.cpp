#include <GL/glut.h>

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

float r = 0.0f;
float g = 0.0f;
float b = 1.0f;

float multiplicador = 1.0f;

void desenharQuadrado(float x, float y, float r, float g, float b) {
    float tamanho = 0.1f;

    glColor3f(r, g, b);

    glBegin(GL_QUADS);
        glVertex2f(x - tamanho * multiplicador, y - tamanho * multiplicador);
        glVertex2f(x + tamanho * multiplicador, y - tamanho * multiplicador);
        glVertex2f(x + tamanho * multiplicador, y + tamanho * multiplicador);
        glVertex2f(x - tamanho * multiplicador, y + tamanho * multiplicador);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    desenharQuadrado(x, y, r, g, b);
    glFlush();
}

/* Função responsável por capturar teclas do teclado */
void keyboard(unsigned char key, int xMouse, int yMouse) {

    switch (key) {

        case 'w':
            y += step; // move para cima
            break;

        case 's':
            y -= step; // move para baixo
            break;

        case 'a':
            x -= step; // move para esquerda
            break;

        case 'd':
            x += step; // move para direita
            break;

        case '+':
            multiplicador += 0.1f; // aumenta tamanho
            break;

        case '-':
            if (multiplicador > 0.2f)
                multiplicador -= 0.1f; // diminui tamanho
            break;
    }

    glutPostRedisplay(); // redesenha tela
}

/* Função responsável por capturar cliques do mouse */
void mouse(int button, int state, int xinutil, int yinutil) {

    if (state == GLUT_DOWN) {

        switch (button) {

            case GLUT_LEFT_BUTTON:
                r = 1.0f;
                g = 0.0f;
                b = 0.0f; // vermelho
                break;

            case GLUT_RIGHT_BUTTON:
                r = 0.0f;
                g = 0.0f;
                b = 1.0f; // azul
                break;

            case GLUT_MIDDLE_BUTTON:
                x = 0.0f;
                y = 0.0f; // volta ao centro
                break;
        }

        glutPostRedisplay(); // atualiza tela
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Controle de Quadrado");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
