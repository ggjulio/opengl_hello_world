
#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>

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

	GLfloat pointVertex[] = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
	GLfloat pointVertex2[] = {SCREEN_WIDTH * 0.75, SCREEN_HEIGHT / 2};

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		/* Render here */
		glEnable( GL_POINT_SMOOTH );
		glEnableClientState(GL_VERTEX_ARRAY);
		glPointSize( 150 ); 
		glVertexPointer(2, GL_FLOAT, 0, pointVertex);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable( GL_POINT_SMOOTH );

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, pointVertex2);
		glPointSize( 120 ); 
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableClientState(GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		usleep(3000 * 1000);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}