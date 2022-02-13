/**
 * @file 2.cpp
 * @author {
 *            Alejandro Caicedo 1827260
 *            Nicolas Jaramillo 1840558
 *         }
 * @date 2022-02-12
 * 
 */
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>

bool fullscreen = false;
int  width = 1280, height = 720;

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 'h':
      printf("help\n\n");
      printf("c - Toggle culling\n");
      printf("q/escape - Quit\n\n");
      break;
    case 'c':
      if (glIsEnabled(GL_CULL_FACE)) 
          glDisable(GL_CULL_FACE);
      else glEnable(GL_CULL_FACE);
      break;
    case 'q':
    case 27:
      exit(0);
      break;
  }
  glutPostRedisplay();
}

void f11(int key, int x, int y)
{
  if (key == 11){
    if(fullscreen){
        glutReshapeWindow(width, height);
        fullscreen=false;
    }
    else{
      glutFullScreen();
      fullscreen=true;
    }
  }
  glutPostRedisplay();
}

void triagle(float v1x, float v1y, float v1z, float r1, float g1, float b1, float v2x, float v2y, float v2z, float r2, float g2, float b2, float v3x, float v3y, float v3z, float r3, float g3, float b3)
{
  
  glBegin(GL_TRIANGLES);   // Begin drawing the triangle
    glColor3f(r1, g1, b1); // color of the vertex
    glVertex3f(v1x, v1y, v1z);
    glColor3f(r2, g2, b2); // color of the vertex
    glVertex3f(v2x, v2y, v2z);
    glColor3f(r3, g3, b3); // color of the vertex
    glVertex3f(v3x, v3y, v3z);
  glEnd();   // Done drawing the triangle
}

void square(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z, float v4x, float v4y, float v4z, float red, float green, float blue)
{
  glColor3f(red, green, blue); // color of the square
  glBegin(GL_QUADS);           // Begin drawing the square
    glVertex3f(v1x, v1y, v1z);
    glVertex3f(v2x, v2y, v2z);
    glVertex3f(v3x, v3y, v3z);
    glVertex3f(v4x, v4y, v4z);
  glEnd();   // Done drawing the square
}

void reshape(GLsizei width, GLsizei height) {
  if (height == 0) height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, aspect, 0.1f, 100.0f);
}

void display()
{
  glClearColor(0.4f, 0.2f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
/**
 * Hacer una traslación de (-1.5,0,-6)
 */
  glTranslatef( -1.5f, 0.0f, -6.0f);
/**
 * genere un triángulo cuyos vértices son de color Rojo, Verde y Azul
 */
  triagle(
     0.0f, 1.0f, 0.0f, // First vertex
     1.0f, 0.0f, 0.0f,  // RGB of the First vertex
    -1.0f,-1.0f, 0.0f, // Second vertex
     0.0f, 1.0f, 0.0f,  // RGB of the Second vertex
     1.0f,-1.0f, 0.0f, // Third vertex
     0.0f, 0.0f, 1.0f);  // RGB of the Third vertex
  glTranslatef( 3.0f, 0.0f, 0.0f);
/**
 * Dibujar un cuadrilátero de color Cian
 */
  square(
    -1.0f, 1.0f, 0.0f, // First vertex
     1.0f, 1.0f, 0.0f, // Second vertex
     1.0f,-1.0f, 0.0f, // Third vertex
    -1.0f,-1.0f, 0.0f, // Forth vertex
     0.0f, 1.0f, 1.0f); // RGB
  glFlush(); // Render Now
  glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void initialize()
{
  glutInitWindowPosition(
    (int)(glutGet(GLUT_SCREEN_WIDTH) - width) / 2,
    (int)(glutGet(GLUT_SCREEN_HEIGHT) - height) / 2); // Position the window's center
  glutInitWindowSize(width, height);         // Set the window's initial width & height
  glutCreateWindow("Ejercicio 2");  // Create a window with the given title
  glClearColor(0.4f, 0.2f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(f11);
  glutDisplayFunc(display); 
}

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  initialize();
  glutMainLoop();
  return 0;
}