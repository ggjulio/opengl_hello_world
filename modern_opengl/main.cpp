#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

int main(void)
{
	GLFWwindow* window;

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

	if (glewInit() != GLEW_OK)
		std::cout << "ERROR: glewInit()" << std::endl;

	std::cout << "gl version: " << glGetString(GL_VERSION) << std::endl;

	unsigned int a;
	glGenBuffers(1, &a);

	GLfloat triangleVertices[] = 
	{
		0, 0.5, 0,
		-0.25, -0.5, 0,
		0.25, -0.5, 0
	};


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, triangleVertices);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableClientState(GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
