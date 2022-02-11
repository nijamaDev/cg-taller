/**
 * @file a.cpp
 * @author {
 *            Alejandro Caicedo 18
 *            Nicolas Jaramillo 1840558
 *         }
 * @date 2022-02-10
 * 
 */
#include <GL/glut.h>
#include <cmath>

/**
 * Dibujar un triángulo con sus vértices en las coordenadas 
 * (-1.5,1,-6), (-2.5,-1,-6) y (-0.5,-1,-6). 
 */
void triagle(float v1, float v2, float v3, float red, float green, float blue)
{
    double p = 0.0;
    double q = 0.0;
    double angle = 1.0;

    //glPushMatrix();
    //glTranslatef(glTranslatefX, glTranslatefY, 0);
    glColor3f(red, green, blue);

    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      //glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 1.0f);
      //glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-2.5f, -1.0f, 1.0f);
      //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -0.8f, 1.0f);
    glEnd();   // Done drawing the pyramid
}

/**
 * Dibujar un cuadrilátero con sus vértices en las coordenadas 
 * (0.5,1,-6), (2.5,1,-6), ( 2.5,-1,-6) y (0.5,-1,-6)
 */

void display()
{
    triagle(0.0f, 1.0f, 0.0f, 0.3f, 0.3f, 0.3f);
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
    int width = 1280, height = 720;  // x and y value
    glutInitWindowPosition(
        (int)(glutGet(GLUT_SCREEN_WIDTH) - width) / 2,
        (int)(glutGet(GLUT_SCREEN_HEIGHT) - height) / 2); // Position the window's center
    glutInitWindowSize(width, height);                        // Set the window's initial width & height
    glutCreateWindow("Ejercicio 1, Parte A");         // Create a window with the given title
    initialize();                                    // Initializing
    glutDisplayFunc(display);                        // Register display callback handler for window re-paint
    glutMainLoop();                                  // Enter the event-processing loop
    return 0;
}