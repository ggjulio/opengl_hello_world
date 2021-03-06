
#include <GLFW/glfw3.h>

#include <iostream>

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

	float vertices[] =
	{
		-0.5, 0.5, 0.0,      
		0.5, 0.5, 0.0, 
		0.5, -0.5, 0.0, 
		-0.5, -0.5, 0.0
	};

	// specify the part of the window to which opengl will draw (in pixels), convert from normalized to pixels
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

	// projection matrix defines the properties of the camera that views the objects in the world coordinate frame,
	// here you typically set the zoom factor, aspect ratio and the near and far clipping planes.
	glMatrixMode(GL_PROJECTION);

	// replace the current matrix with the identity matrix and starts us a fresh because
	// matrix transforms such as glOrtho and glRotate cumulate, basically puts us at (0, 0, 0)
	glLoadIdentity();
	
 	// essentially set coordinate system
	glOrtho(-1, 1, -1, 1, 0, 1);
//  glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	
	// (default matrix mode) modelview matrix defines how your objects are
	// transformed in our world (meaning translation, rotation and scaling)
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity(); // same as the other call


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		/* Render here */
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}