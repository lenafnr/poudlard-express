#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_texture.hpp"
#include "draw_scene.hpp"
#include "tools/shaders.hpp"
#include "tools/camera.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "tools/stb_image.h"
#include <iostream>

using namespace glbasimac;
using namespace STP3D;

/* Window properties */
static const unsigned int WINDOW_WIDTH = 1200;
static const unsigned int WINDOW_HEIGHT = 800;
static const char WINDOW_TITLE[] = "Train Poudlard Express";
static float aspectRatio = 1.0f;

// Position initiale

FPSCamera cameraFPS(Vector3D(-12.0f, 0.0f, 5.0f),
					Vector3D(1.0f, 0.0f, 0.0f),
					Vector3D(0.0f, 0.0f, 1.0f));

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* Error handling function */
void onError(int error, const char *description)
{
	std::cout << "GLFW Error (" << error << ") : " << description << std::endl;
}

void onWindowResized(GLFWwindow * /*window*/, int width, int height)
{
	myEngine.set3DProjection(90.0, aspectRatio, Z_NEAR, Z_FAR);

	glViewport(0, 0, width, height);
	std::cerr << "Setting 3D projection" << std::endl;
}

void onKey(GLFWwindow *window, int key, int /*scancode*/, int action, int /*mods*/)
{

	const float speednessFoot = 1.0f;
	const float speednessHead = 2.0f;

	int is_pressed = (action == GLFW_PRESS);
	switch (key)
	{
	case GLFW_KEY_C:
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		break;
	case GLFW_KEY_L:
		if (is_pressed)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case GLFW_KEY_P:
		if (is_pressed)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case GLFW_KEY_T:
		if (is_pressed)
		{
			cameraFPS.reinitPosCam(Vector3D(0.0f, 0.0f, 70.0f),
								   Vector3D(0.0f, 0.0f, -1.0f),
								   Vector3D(0.0f, 1.0f, 0.0f));
		}
		break;

	case GLFW_KEY_H:
		if (is_pressed)
		{
			cameraFPS.reinitPosCam(Vector3D(-12.0f, 0.0f, 5.0f),
								   Vector3D(1.0f, 0.0f, 0.0f),
								   Vector3D(0.0f, 0.0f, 1.0f));
		}
		break;
	case GLFW_KEY_LEFT:
		cameraFPS.lookLeft(speednessHead);
		break;
	case GLFW_KEY_RIGHT:
		cameraFPS.lookRight(speednessHead);
		break;
	case GLFW_KEY_UP:
		cameraFPS.lookUp(speednessHead);
		break;
	case GLFW_KEY_DOWN:
		cameraFPS.lookDown(speednessHead);
		break;
	case GLFW_KEY_W:
		cameraFPS.stepFront(speednessFoot);
		break;
	case GLFW_KEY_A:
		cameraFPS.stepLeft(speednessFoot);
		break;
	case GLFW_KEY_S:
		cameraFPS.stepBack(speednessFoot);
		break;
	case GLFW_KEY_D:
		cameraFPS.stepRight(speednessFoot);
		break;
	case GLFW_KEY_J:
		if (is_pressed)
		{
			phong_lightning = !phong_lightning;
		}
		break;
	default:
		std::cerr << "Touche non gérée " << key << std::endl;
	}
}

void onMouseButton(GLFWwindow *window, int button, int action, int /*mods*/)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		std::cout << "Pressed in " << xpos << " " << ypos << std::endl;
	}
}

int main(int /*argc*/, char ** /*argv*/)
{
	/* GLFW initialisation */
	GLFWwindow *window;
	if (!glfwInit())
		return -1;

	/* Try to uncomment this for MAC OS if it did not work */
     //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
     //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
     //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/* Callback to a function if an error is rised by GLFW */
	glfwSetErrorCallback(onError);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		// If no context created : exit !
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	std::cout << "Loading GL extension" << std::endl;
	// Intialize glad (loads the OpenGL functions)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return -1;
	}

	glfwSetWindowSizeCallback(window, onWindowResized);
	glfwSetKeyCallback(window, onKey);
	glfwSetMouseButtonCallback(window, onMouseButton);

	std::cout << "Engine init" << std::endl;
	myEngine.mode2D = false; // Set engine to 3D mode
	myEngine.initGL();
	onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	CHECK_GL;

	initScene();

	initJson();

	double elapsedTime{0.0};

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

		/* Render begins here */
		if (phong_lightning)
			glClearColor(0.f, 0.0f, 0.0f, 0.0f);
		else
			glClearColor(0.f, 0.5f, 0.5f, 0.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		/* Fix camera FPS position */
		myEngine.mvMatrixStack.loadIdentity();
		Matrix4D viewMatrix = cameraFPS.returnViewMatrix();
		myEngine.setViewMatrix(viewMatrix);

		myEngine.updateMvMatrix();

		drawScene();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/* Elapsed time computation from loop begining */
		elapsedTime = glfwGetTime() - startTime;
		/* If to few time is spend vs our wanted FPS, we wait */
		while (elapsedTime < FRAMERATE_IN_SECONDS)
		{
			glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS - elapsedTime);
			elapsedTime = glfwGetTime() - startTime;
		}
	}
	glfwTerminate();
	return 0;
}
