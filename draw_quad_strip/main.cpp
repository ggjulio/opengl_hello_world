#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480


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

	GLfloat vertices[] = 
	{
		200, 300, 0, // top left corner
		300, 300, 0, // top right corner
		200, 250, 0, // botton left corner
		300, 250, 0, // botton right corner
		
		150, 200, 0, 
		350, 200, 0, 

		250, 100, 0, 
		350, 50, 0, 
	};

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		/* Render here */
		glEnableClientState( GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_QUAD_STRIP, 0, 8);
		glDisableClientState( GL_VERTEX_ARRAY);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
