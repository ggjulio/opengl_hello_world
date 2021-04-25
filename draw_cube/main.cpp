#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

void cursorPositionCallback(GLFWwindow *window, double x, double y);
void cursorEnterPositionCallback(GLFWwindow *window, int entered);

void draw_cube(GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat edgeLength);

GLfloat rotationX = 0;
GLfloat rotationY = 0;

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
	glfwSetKeyCallback(window, keyCallback);

	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetCursorEnterCallback(window, cursorEnterPositionCallback);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */
		glPushMatrix();
		glTranslatef( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, -500);
		glRotatef(rotationX, 1, 0, 0);
		glRotatef(rotationY, 0, 1, 0);
		glTranslatef(-(SCREEN_WIDTH / 2), -(SCREEN_HEIGHT / 2), 500);

		draw_cube(SCREEN_WIDTH / 2, SCREEN_WIDTH / 2, -500, 200);
		
		draw_cube(SCREEN_WIDTH * 0.2 , SCREEN_WIDTH / 2, -500, 100);

		glPopMatrix();

		// glEnableClientState( GL_VERTEX_ARRAY);
		// glDisableClientState( GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void draw_cube(GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat edgeLength)
{
	(void)centerX;
	(void)centerY;
	(void)centerZ;
	(void)edgeLength;

	GLfloat halfSideLength = edgeLength * 0.5;

	GLfloat vertices[]
	{
		// front 
		centerX - halfSideLength, centerY + halfSideLength, centerZ + halfSideLength, // top left
		centerX + halfSideLength, centerY + halfSideLength, centerZ + halfSideLength, // top right
		centerX + halfSideLength, centerY - halfSideLength, centerZ + halfSideLength, // bottom left
		centerX - halfSideLength, centerY - halfSideLength, centerZ + halfSideLength, // bottom right

		// back
		centerX - halfSideLength, centerY + halfSideLength, centerZ - halfSideLength, // top left
		centerX + halfSideLength, centerY + halfSideLength, centerZ - halfSideLength, // top right
		centerX + halfSideLength, centerY - halfSideLength, centerZ - halfSideLength, // bottom left
		centerX - halfSideLength, centerY - halfSideLength, centerZ - halfSideLength, // bottom right

		// left face
		centerX - halfSideLength, centerY + halfSideLength, centerZ + halfSideLength, // top left
		centerX - halfSideLength, centerY + halfSideLength, centerZ - halfSideLength, // top right
		centerX - halfSideLength, centerY - halfSideLength, centerZ - halfSideLength, // bottom left
		centerX - halfSideLength, centerY - halfSideLength, centerZ + halfSideLength, // bottom right

		// right face
		centerX + halfSideLength, centerY + halfSideLength, centerZ + halfSideLength, // top left
		centerX + halfSideLength, centerY + halfSideLength, centerZ - halfSideLength, // top right
		centerX + halfSideLength, centerY - halfSideLength, centerZ - halfSideLength, // bottom left
		centerX + halfSideLength, centerY - halfSideLength, centerZ + halfSideLength, // bottom right

		// top face
		centerX - halfSideLength, centerY + halfSideLength, centerZ + halfSideLength, // top left
		centerX - halfSideLength, centerY + halfSideLength, centerZ - halfSideLength, // top right
		centerX + halfSideLength, centerY + halfSideLength, centerZ - halfSideLength, // bottom left
		centerX + halfSideLength, centerY + halfSideLength, centerZ + halfSideLength, // bottom right

		// top face
		centerX - halfSideLength, centerY - halfSideLength, centerZ + halfSideLength, // top left
		centerX - halfSideLength, centerY - halfSideLength, centerZ - halfSideLength, // top right
		centerX + halfSideLength, centerY - halfSideLength, centerZ - halfSideLength, // bottom left
		centerX + halfSideLength, centerY - halfSideLength, centerZ + halfSideLength, // bottom right
	};
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
}


void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)window;
	(void)scancode;
	(void)mods;

	GLfloat rotationSpeed = 5;

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			rotationX += rotationSpeed;
			break;
		case GLFW_KEY_DOWN:
			rotationX -= rotationSpeed;
			break;
		case GLFW_KEY_LEFT:
			rotationY -= rotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationY += rotationSpeed;
			break;
		
		default:
			break;
		}
	}

}

void cursorPositionCallback(GLFWwindow *window, double x, double y)
{
	(void)window;
	(void)x;
	(void)y;
}
void cursorEnterPositionCallback(GLFWwindow *window, int entered)
{
	(void)window;
	(void)entered;

}
