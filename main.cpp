/* 
CEUB - Computacao Grafica - Projeto OpenGL
Flavio Ribeiro Lima Filho - RA: 22000202
*/

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include "stb_image.h"	
#include "cores.h"		// Define o modelo de cores a ser utilizado
#include "objetos.h"	
#include "camera.h"



static float eyex = 0.0, eyey = 0.5, eyez = 5.0;	// posicao inicial da camera

float posicao[] = { 0.0, 3.0, 2.0, 0.0 };	// posicao inicial da luz


void init(void) {

	/* Cria as matrizes responsáveis pelo
	controle de luzes na cena */
	GLfloat ambiente[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat difusa[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat especular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodelo_ambiente[] = { 0.2, 0.2, 0.2, 1.0 };

	glClearColor (0.196078, 0.6, 0.8,0.0);
	glEnable(GL_DEPTH_TEST);

	glShadeModel (GL_SMOOTH);

	// habilita a luz
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, especular);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodelo_ambiente);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

}

void display(void) {

	glLoadIdentity();			// Carrega a matriz identidade
	camera(eyex, eyey, eyez);	// Chama a funcao camera
	
	/*
	Limpa o buffer de pixels e
	determina a cor padrão dos objetos.
	*/
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);

	glDisable( GL_LIGHTING );
	desenhaTerreno(5);			// Cria o terreno - Recebe o valor para o tamanha do terreno
	glEnable( GL_LIGHTING );

/* Cria os Objetos (nuvem) */
	desenhaNuvem();				// Cria a nuvem ( POSICAO PADRAO )

	glPushMatrix();
	glTranslatef(-2.0, 1.0, -0.7);
	desenhaNuvem();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(4.0, 1.0, 2.0);
	desenhaNuvem();
	glPopMatrix();



	glDisable( GL_LIGHTING );	// Cria uma pequena esfera na posição da luz.
	glPushMatrix();
	{
		glLightfv( GL_LIGHT0, GL_POSITION, posicao );
		
		// Esfera representando a fonte de luz
		
		glTranslatef( posicao[0], posicao[1], posicao[2] );
		glColor3f(1.0f, 1.0f, 0.5f);
		glutSolidSphere( 0.1, 8, 8 );
	}
	glPopMatrix();
	glEnable( GL_LIGHTING );


/* Cria os Objetos (arvores) */
	desenhaArvore();			// Cria arvore ( POSICAO PADRAO )

	glPushMatrix();
	glTranslatef(-2.0, 0.0, -1.0);
	desenhaArvore();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-3.0, 0.0, 2.0);
	desenhaArvore();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3.0, 0.0, 3.5);
	desenhaArvore();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-1.5, 0.0, -3.5);
	desenhaArvore();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3.0, 0.0, -3.0);
	desenhaArvore();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1.5, 0.0, -2.0);
	desenhaArvore();
	glPopMatrix();

// Executa os comandos
	glutSwapBuffers();
}


/*
Função responsável pelo desenho da tela
Quando a tela é redimensionada os valores
da visão perspectiva são recalculados com base no novo tamanho da tela
assim como o Viewport
*/
void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 0.5, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

/* Função responsável pelo controle de teclado

Teclas para movimentacao da camera:
- w
- a
- s
- d
- Barra de Espaco
- l

Teclas para movimentacao da luz:
- seta para cima
- seta para baixo
- seta para direita
- seta para esquerda
- m
- n

*/
void keyboard (unsigned char key, int x, int y) {
	
// Movimentacao da Fonte de Luz
	switch (key) {
		case 'n':
		case 'N':
			posicao[2] -= 0.1f;
			glutPostRedisplay();
			break;

		case 'm':
		case 'M':
			posicao[2] += 0.1f;
			glutPostRedisplay();
			break;


// Movimentacao da Camera
		case 'w':
		case 'W':
			eyez = eyez - 0.2;
			glutPostRedisplay();
			break;

		case 's':
		case 'S':
			eyez = eyez + 0.2;
			glutPostRedisplay();
			break;
			
		case 'a':
		case 'A':
			eyex = eyex - 0.2;
			glutPostRedisplay();
			break;
			
		case 'd':
		case 'D':
			eyex = eyex + 0.2;
			glutPostRedisplay();
			break;
			
		case 32:
			eyey = eyey + 0.2;
			glutPostRedisplay();
			break;
			
		case 'l':
			case 'L':
			eyey = eyey - 0.2;
			glutPostRedisplay();
			break;

		default:
			break;
	}
}

// Movimentacao da Fonte de Luz
void Special_keyboard (int key, int x, int y)
{
switch (key) {
case GLUT_KEY_LEFT :
posicao[0] -= 0.1f;
glutPostRedisplay();
break;
case GLUT_KEY_UP :
posicao[1] += 0.1f;
glutPostRedisplay();
break;
case GLUT_KEY_DOWN :
posicao[1] -= 0.1f;
glutPostRedisplay();
break;
case GLUT_KEY_RIGHT :
posicao[0] += 0.1f;
glutPostRedisplay();
break;
}
}

/*
Função principal do programa.
*/
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Paisagem OpenGL");
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Special_keyboard);
	glutMainLoop();
	return 0;
}
