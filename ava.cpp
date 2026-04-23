#include <GL/glut.h>

float posicaoQuadradoX = -1.0f;
float posicaoTrianguloX = -1.0f; 
float direcaoQuadrado = 1.0f;  

float anguloTriangulo = 0.0f;
float direcaoTriangulo = 1.0f; 
bool visaoPeriscopio= false; 


void desenharCena() {
    glDisable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    if (visaoPeriscopio==true){
        glEnable(GL_SCISSOR_TEST);
        glScissor(100, 100, 200, 200);
    }
    if (visaoPeriscopio==false){
        glDisable(GL_SCISSOR_TEST);
    }



    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f); 

    glVertex2f(-400, -300);
    glVertex2f(400, -300);
    glVertex2f(400, 0);
    glVertex2f(-400, 0);
    glEnd();


    glPushMatrix(); 
    glTranslatef(posicaoQuadradoX, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f); 
        glVertex2f( -0.0f, -0.4f);
        glVertex2f( 0.2f, -0.4f);
        glVertex2f( 0.2f,  - 0.2f);
        glVertex2f(-0.0f,  -0.2f);
    glEnd();
    glPopMatrix(); 


    glPushMatrix();
        glTranslatef(posicaoQuadradoX,-0.3f, 0.0f); 
        glRotatef(anguloTriangulo, 1.0f, 0.0f, 0.0f); 
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
        glVertex2f(-0.0f, -0.0f);
        glVertex2f(-0.2f, 0.15f);
        glVertex2f(-0.2f, -0.15f);
        glEnd();

        glPopMatrix();
        glutSwapBuffers();   
    glFlush();
}

void atualizaAnimacao(int valor) {

    anguloTriangulo += 4.0f;
    if (anguloTriangulo > 360.0f) {
        anguloTriangulo -= 360.0f;
    }

    posicaoTrianguloX += 0.02f * direcaoTriangulo;
    if (posicaoTrianguloX > 1.0f || posicaoTrianguloX < -1.0f) {
        direcaoTriangulo *= -1.0f; 
    }

  
    posicaoQuadradoX += 0.02f * direcaoQuadrado;
    if (posicaoQuadradoX > 1.0f || posicaoQuadradoX < -1.0f) {
        direcaoQuadrado *= -1.0f; 
    }

    glutPostRedisplay();
    glutTimerFunc(16, atualizaAnimacao, 0);
}


void keyboard(unsigned char key, int mouse_x, int mouse_y) {
    if (key == 'c' || key == 'C') {
        if (visaoPeriscopio==true) visaoPeriscopio = false;
        else visaoPeriscopio = true;
    }
    glutPostRedisplay();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    glutInitWindowSize(400, 400);
    glutCreateWindow("Animacao com OpenGL e GLUT");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(desenharCena);
  
    glutTimerFunc(25, atualizaAnimacao, 0);
    
    glutMainLoop();
    
}
