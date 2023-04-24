
void desenhaArvore(void)
{
	// Tronco arvore
	glPushMatrix();
		glTranslatef(0.0, -0.5, 1.0);	// Mantem o tronco no nivel do plano
		glRotatef(-120, 1.0, 1.0, 1.0);
		glColor3fv(marrom);
		glutSolidCone(0.2, 2.0, 3.0, 3.0);
	glPopMatrix();
	
	// copa arvora
	glPushMatrix();
		glTranslatef(0.0, 1.3, 1.0);	// Sobe a copa da arvore 
		glScalef(-0.89, -0.89, -0.89);
		glColor3fv(verde);
		glutSolidIcosahedron();
	glPopMatrix();
}


void desenhaNuvem(void)
{
	glPushMatrix();
		glTranslatef(0.0, 2.5, 0.0);
		glColor3fv(branco_gelo);
		glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.3, 2.7, 0.0);
		glColor3fv(branco_gelo);
		glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.6, 2.5, 0.0);
		glColor3fv(branco_gelo);
		glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3, 2.5, -0.3);
		glColor3fv(branco_gelo);
		glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3, 2.5, 0.3);
		glColor3fv(branco_gelo);
		glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
}


void desenhaTerreno(float SIZE)
{
	// Construtor de terreno

	float L = SIZE, y = -0.5;
	
	glColor3fv(verde_escuro);
	
	glBegin(GL_QUADS);

	glVertex3f(-L, y,  L);
	glVertex3f( L, y,  L);
	glVertex3f( L, y, -L);
	glVertex3f(-L, y, -L);
	
	glEnd();
}

/*
Construtor de terreno modelo base
	
	float L = SIZE, y = -0.5;
	glColor3fv(cinza_escuro);
	
	glBegin(GL_LINES);

	for(float i = -L; i <= L; i ++)
	{
		// Linhas Verticais 
		glVertex3f(i, y, -L);
		glVertex3f(i, y, L);
		
		// Linhas Horizontais
		glVertex3f(-L,y,i);
		glVertex3f(L,y,i);
	}
	glEnd();
*/
