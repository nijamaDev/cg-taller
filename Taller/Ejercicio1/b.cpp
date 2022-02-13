/**
 * @file b.cpp
 * @author {
 *            Alejandro Caicedo 1827260
 *            Nicolas Jaramillo 1840558
 *         }
 * @date 2022-02-10
 * 
 */
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string> 

bool fullscreen = false;
int height = 720;
int width = 1080;
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
    case '1':
      glRotatef(1.0,1.,0.,0.);
      break;
    case '2':
      glRotatef(1.0,0.,1.,0.);
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
  switch (key)
  {
    case 11:
      if(fullscreen){
        glutReshapeWindow(width, height);
        fullscreen=false;
      }
      else{
        glutFullScreen();
        fullscreen=true;
      }
      break;
  }
  glutPostRedisplay();
}


/**
 * Dibujar un triángulo con sus vértices en las coordenadas 
 * (-1.5,1,-6), (-2.5,-1,-6) y (-0.5,-1,-6). 
 */
void triagle(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z, float red, float green, float blue)
{
    glColor3f(red, green, blue);

    glBegin(GL_TRIANGLES);           // Begin drawing the triangle
      glVertex3f(v1x, v1y, v1z);
      glVertex3f(v2x, v2y, v2z);
      glVertex3f(v3x, v3y, v3z);
    glEnd();   // Done drawing the triangle
}

/**
 * Dibujar un cuadrilátero con sus vértices en las coordenadas 
 * (0.5,1,-6), (2.5,1,-6), ( 2.5,-1,-6) y (0.5,-1,-6)
 */

void square(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z, float v4x, float v4y, float v4z, float red, float green, float blue)
{
    glColor3f(red, green, blue);

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
    triagle(
      -1.5f, 1.0f, -6.0f, // First vertex
      -2.5f,-1.0f, -6.0f, // Second vertex
      -0.5f,-1.0f, -6.0f, // Third vertex
      1.0f, 0.4f, 0.8f);  // RGB
    square(
      0.5, 1.0,-6, // First vertex
      2.5, 1.0, -6, // Second vertex
      2.5,-1.0, -6, // Third vertex
      0.5,-1.0, -6, // Forth vertex
      1.0f, 0.4f, 0.8f); // RGB
    glFlush(); // Render Now
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}


void initialize()
{
    glClearColor(0.4f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitWindowPosition(
        (int)(glutGet(GLUT_SCREEN_WIDTH) - width) / 2,
        (int)(glutGet(GLUT_SCREEN_HEIGHT) - height) / 2); // Position the window's center
    glutInitWindowSize(width, height);                        // Set the window's initial width & height
    glutCreateWindow("Ejercicio 1, Parte A");         // Create a window with the given title
    initialize();                                    // Initializing
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(f11);
    glutDisplayFunc(display);                        // Register display callback handler for window re-paint
    bool fullscreen = false;
    glutMainLoop();                                  // Enter the event-processing loop
    return 0;
}