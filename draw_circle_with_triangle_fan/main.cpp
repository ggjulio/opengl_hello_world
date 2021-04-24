#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

void draw_circle(GLfloat vertex[3], GLfloat radius, GLint numberOfSides);

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		/* Render here */

		draw_circle((GLfloat[3]){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0}, 50.0f, 4);
		draw_circle((GLfloat[3]){SCREEN_WIDTH * 0.7, SCREEN_HEIGHT / 2, 0}, 50.0f, 5);
		draw_circle((GLfloat[3]){SCREEN_WIDTH * 0.3, SCREEN_HEIGHT / 2, 0}, 50.0f, 8);
		draw_circle((GLfloat[3]){SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.2, 0}, 50.0f, 16);
		draw_circle((GLfloat[3]){SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.8, 0}, 50.0f, 32);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void draw_circle(GLfloat vertex[3], GLfloat radius, GLint numberOfSides){
	GLint numberOfVertices = numberOfSides + 2;
	GLfloat doublePi = 2.0f * M_PI;
	GLfloat circleVerticesX[numberOfVertices];
	GLfloat circleVerticesY[numberOfVertices];
	GLfloat circleVerticesZ[numberOfVertices];

	circleVerticesX[0] = vertex[0];
	circleVerticesY[0] = vertex[1];
	circleVerticesZ[0] = vertex[2];

	for (size_t i = 1; i < (size_t)numberOfVertices; i++){
		circleVerticesX[i] = vertex[0] + (radius * cos( i * doublePi / numberOfSides));
		circleVerticesY[i] = vertex[1] + (radius * sin( i * doublePi / numberOfSides));
		circleVerticesZ[i] = vertex[2];
	}
	GLfloat allCircleVertices[numberOfVertices * 3];

	for (size_t i = 0; i < (size_t)numberOfVertices; i++)
	{
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[i * 3 + 1] = circleVerticesY[i];
		allCircleVertices[i * 3 + 2] = circleVerticesZ[i];
	}
	glEnableClientState( GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
	glDisableClientState( GL_VERTEX_ARRAY);
	
};