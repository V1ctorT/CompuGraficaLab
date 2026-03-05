//Nombre: Torres Martinez Victor Manuel
//Fecha 04/02/26
//Practica 4: Modelado Geometrico 

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Modelado geometrico Victor Manuel Torres Martinez", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,1.0f,//Front
		0.5f, -0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f, 0.5f, 1.0f, 0.0f,0.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,0.0f,
		
	    -0.5f, -0.5f,-0.5f, 0.0f, 1.0f,0.0f,//Back
		 0.5f, -0.5f,-0.5f, 0.0f, 1.0f,0.0f,
		 0.5f,  0.5f,-0.5f, 0.0f, 1.0f,0.0f,
		 0.5f,  0.5f,-0.5f, 0.0f, 1.0f,0.0f,
	    -0.5f,  0.5f,-0.5f, 0.0f, 1.0f,0.0f,
	    -0.5f, -0.5f,-0.5f, 0.0f, 1.0f,0.0f,
		
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  -0.5f, 0.5f, 0.0f, 0.0f,1.0f,
      
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f,0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.0f,
		
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 1.0f,1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 1.0f,1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 1.0f,1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,1.0f,
		
		-0.5f,  0.5f, -0.5f, 1.0f, 0.2f,0.5f,
		0.5f,  0.5f, -0.5f,  1.0f, 0.2f,0.5f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.2f,0.5f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.2f,0.5f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.2f,0.5f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.2f,0.5f,
	};

	float cuboVerdeClaro[] = {

		// FRONT
		-0.5f,-0.5f, 0.5f,  0.7f,1.0f,0.7f,
		 0.5f,-0.5f, 0.5f,  0.7f,1.0f,0.7f,
		 0.5f, 0.5f, 0.5f,  0.7f,1.0f,0.7f,
		 0.5f, 0.5f, 0.5f,  0.7f,1.0f,0.7f,
		-0.5f, 0.5f, 0.5f,  0.7f,1.0f,0.7f,
		-0.5f,-0.5f, 0.5f,  0.7f,1.0f,0.7f,

		// BACK
		-0.5f,-0.5f,-0.5f,  0.6f,0.9f,0.6f,
		 0.5f,-0.5f,-0.5f,  0.6f,0.9f,0.6f,
		 0.5f, 0.5f,-0.5f,  0.6f,0.9f,0.6f,
		 0.5f, 0.5f,-0.5f,  0.6f,0.9f,0.6f,
		-0.5f, 0.5f,-0.5f,  0.6f,0.9f,0.6f,
		-0.5f,-0.5f,-0.5f,  0.6f,0.9f,0.6f,

		// RIGHT
		 0.5f,-0.5f, 0.5f,  0.5f,0.8f,0.5f,
		 0.5f,-0.5f,-0.5f,  0.5f,0.8f,0.5f,
		 0.5f, 0.5f,-0.5f,  0.5f,0.8f,0.5f,
		 0.5f, 0.5f,-0.5f,  0.5f,0.8f,0.5f,
		 0.5f, 0.5f, 0.5f,  0.5f,0.8f,0.5f,
		 0.5f,-0.5f, 0.5f,  0.5f,0.8f,0.5f,

		 // LEFT
		 -0.5f, 0.5f, 0.5f,  0.65f,0.95f,0.65f,
		 -0.5f, 0.5f,-0.5f,  0.65f,0.95f,0.65f,
		 -0.5f,-0.5f,-0.5f,  0.65f,0.95f,0.65f,
		 -0.5f,-0.5f,-0.5f,  0.65f,0.95f,0.65f,
		 -0.5f,-0.5f, 0.5f,  0.65f,0.95f,0.65f,
		 -0.5f, 0.5f, 0.5f,  0.65f,0.95f,0.65f,
		 // TOP
		-0.5f, 0.5f,-0.5f,  0.7f,1.0f,0.7f,
		 0.5f, 0.5f,-0.5f,  0.7f,1.0f,0.7f,
		 0.5f, 0.5f, 0.5f,  0.7f,1.0f,0.7f,
		 0.5f, 0.5f, 0.5f,  0.7f,1.0f,0.7f,
		-0.5f, 0.5f, 0.5f,  0.7f,1.0f,0.7f,
		-0.5f, 0.5f,-0.5f,  0.7f,1.0f,0.7f,
		// BOTTOM
		-0.5f,-0.5f,-0.5f,  0.6f,0.9f,0.6f,
		 0.5f,-0.5f,-0.5f,  0.6f,0.9f,0.6f,
		 0.5f,-0.5f, 0.5f,  0.6f,0.9f,0.6f,
		 0.5f,-0.5f, 0.5f,  0.6f,0.9f,0.6f,
		-0.5f,-0.5f, 0.5f,  0.6f,0.9f,0.6f,
		-0.5f,-0.5f,-0.5f,  0.6f,0.9f,0.6f,
	};

	float cuboVerdeOscuro[] = {

		// ===== FRONT =====
		-0.5f,-0.5f, 0.5f,  0.0f,0.45f,0.0f,
		 0.5f,-0.5f, 0.5f,  0.0f,0.45f,0.0f,
		 0.5f, 0.5f, 0.5f,  0.0f,0.45f,0.0f,
		 0.5f, 0.5f, 0.5f,  0.0f,0.45f,0.0f,
		-0.5f, 0.5f, 0.5f,  0.0f,0.45f,0.0f,
		-0.5f,-0.5f, 0.5f,  0.0f,0.45f,0.0f,

		// ===== BACK =====
		-0.5f,-0.5f,-0.5f,  0.0f,0.35f,0.0f,
		 0.5f,-0.5f,-0.5f,  0.0f,0.35f,0.0f,
		 0.5f, 0.5f,-0.5f,  0.0f,0.35f,0.0f,
		 0.5f, 0.5f,-0.5f,  0.0f,0.35f,0.0f,
		-0.5f, 0.5f,-0.5f,  0.0f,0.35f,0.0f,
		-0.5f,-0.5f,-0.5f,  0.0f,0.35f,0.0f,

		// ===== RIGHT =====
		 0.5f,-0.5f, 0.5f,  0.0f,0.30f,0.0f,
		 0.5f,-0.5f,-0.5f,  0.0f,0.30f,0.0f,
		 0.5f, 0.5f,-0.5f,  0.0f,0.30f,0.0f,
		 0.5f, 0.5f,-0.5f,  0.0f,0.30f,0.0f,
		 0.5f, 0.5f, 0.5f,  0.0f,0.30f,0.0f,
		 0.5f,-0.5f, 0.5f,  0.0f,0.30f,0.0f,

		 // ===== LEFT =====
		 -0.5f, 0.5f, 0.5f,  0.0f,0.40f,0.0f,
		 -0.5f, 0.5f,-0.5f,  0.0f,0.40f,0.0f,
		 -0.5f,-0.5f,-0.5f,  0.0f,0.40f,0.0f,
		 -0.5f,-0.5f,-0.5f,  0.0f,0.40f,0.0f,
		 -0.5f,-0.5f, 0.5f,  0.0f,0.40f,0.0f,
		 -0.5f, 0.5f, 0.5f,  0.0f,0.40f,0.0f,

		 // ===== BOTTOM =====
		 -0.5f,-0.5f,-0.5f,  0.0f,0.25f,0.0f,
		  0.5f,-0.5f,-0.5f,  0.0f,0.25f,0.0f,
		  0.5f,-0.5f, 0.5f,  0.0f,0.25f,0.0f,
		  0.5f,-0.5f, 0.5f,  0.0f,0.25f,0.0f,
		 -0.5f,-0.5f, 0.5f,  0.0f,0.25f,0.0f,
		 -0.5f,-0.5f,-0.5f,  0.0f,0.25f,0.0f,

		 // ===== TOP =====
		 -0.5f, 0.5f,-0.5f,  0.0f,0.50f,0.0f,
		  0.5f, 0.5f,-0.5f,  0.0f,0.50f,0.0f,
		  0.5f, 0.5f, 0.5f,  0.0f,0.50f,0.0f,
		  0.5f, 0.5f, 0.5f,  0.0f,0.50f,0.0f,
		 -0.5f, 0.5f, 0.5f,  0.0f,0.50f,0.0f,
		 -0.5f, 0.5f,-0.5f,  0.0f,0.50f,0.0f,
	};

	float cuboOscuro[] = {

		// ===== FRONT =====
		-0.5f,-0.5f, 0.5f,  0.15f,0.15f,0.15f,
		 0.5f,-0.5f, 0.5f,  0.15f,0.15f,0.15f,
		 0.5f, 0.5f, 0.5f,  0.15f,0.15f,0.15f,
		 0.5f, 0.5f, 0.5f,  0.15f,0.15f,0.15f,
		-0.5f, 0.5f, 0.5f,  0.15f,0.15f,0.15f,
		-0.5f,-0.5f, 0.5f,  0.15f,0.15f,0.15f,

		// ===== BACK =====
		-0.5f,-0.5f,-0.5f,  0.10f,0.10f,0.10f,
		 0.5f,-0.5f,-0.5f,  0.10f,0.10f,0.10f,
		 0.5f, 0.5f,-0.5f,  0.10f,0.10f,0.10f,
		 0.5f, 0.5f,-0.5f,  0.10f,0.10f,0.10f,
		-0.5f, 0.5f,-0.5f,  0.10f,0.10f,0.10f,
		-0.5f,-0.5f,-0.5f,  0.10f,0.10f,0.10f,

		// ===== RIGHT =====
		 0.5f,-0.5f, 0.5f,  0.08f,0.08f,0.08f,
		 0.5f,-0.5f,-0.5f,  0.08f,0.08f,0.08f,
		 0.5f, 0.5f,-0.5f,  0.08f,0.08f,0.08f,
		 0.5f, 0.5f,-0.5f,  0.08f,0.08f,0.08f,
		 0.5f, 0.5f, 0.5f,  0.08f,0.08f,0.08f,
		 0.5f,-0.5f, 0.5f,  0.08f,0.08f,0.08f,

		 // ===== LEFT =====
		 -0.5f, 0.5f, 0.5f,  0.12f,0.12f,0.12f,
		 -0.5f, 0.5f,-0.5f,  0.12f,0.12f,0.12f,
		 -0.5f,-0.5f,-0.5f,  0.12f,0.12f,0.12f,
		 -0.5f,-0.5f,-0.5f,  0.12f,0.12f,0.12f,
		 -0.5f,-0.5f, 0.5f,  0.12f,0.12f,0.12f,
		 -0.5f, 0.5f, 0.5f,  0.12f,0.12f,0.12f,

		 // ===== BOTTOM =====
		 -0.5f,-0.5f,-0.5f,  0.05f,0.05f,0.05f,
		  0.5f,-0.5f,-0.5f,  0.05f,0.05f,0.05f,
		  0.5f,-0.5f, 0.5f,  0.05f,0.05f,0.05f,
		  0.5f,-0.5f, 0.5f,  0.05f,0.05f,0.05f,
		 -0.5f,-0.5f, 0.5f,  0.05f,0.05f,0.05f,
		 -0.5f,-0.5f,-0.5f,  0.05f,0.05f,0.05f,

		 // ===== TOP =====
		 -0.5f, 0.5f,-0.5f,  0.18f,0.18f,0.18f,
		  0.5f, 0.5f,-0.5f,  0.18f,0.18f,0.18f,
		  0.5f, 0.5f, 0.5f,  0.18f,0.18f,0.18f,
		  0.5f, 0.5f, 0.5f,  0.18f,0.18f,0.18f,
		 -0.5f, 0.5f, 0.5f,  0.18f,0.18f,0.18f,
		 -0.5f, 0.5f,-0.5f,  0.18f,0.18f,0.18f,
	};

		//Cubo Verde Pasto
	float cuboVerdePasto[] = {
		// FRONT
		-0.5f,-0.5f, 0.5f,   0.30f,0.80f,0.30f,
		 0.5f,-0.5f, 0.5f,   0.30f,0.80f,0.30f,
		 0.5f, 0.5f, 0.5f,   0.30f,0.80f,0.30f,
		 0.5f, 0.5f, 0.5f,   0.30f,0.80f,0.30f,
		-0.5f, 0.5f, 0.5f,   0.30f,0.80f,0.30f,
		-0.5f,-0.5f, 0.5f,   0.30f,0.80f,0.30f,

		// BACK
		-0.5f,-0.5f,-0.5f,   0.25f,0.70f,0.25f,
		 0.5f,-0.5f,-0.5f,   0.25f,0.70f,0.25f,
		 0.5f, 0.5f,-0.5f,   0.25f,0.70f,0.25f,
		 0.5f, 0.5f,-0.5f,   0.25f,0.70f,0.25f,
		-0.5f, 0.5f,-0.5f,   0.25f,0.70f,0.25f,
		-0.5f,-0.5f,-0.5f,   0.25f,0.70f,0.25f,

		// RIGHT
		 0.5f,-0.5f, 0.5f,   0.20f,0.75f,0.20f,
		 0.5f,-0.5f,-0.5f,   0.20f,0.75f,0.20f,
		 0.5f, 0.5f,-0.5f,   0.20f,0.75f,0.20f,
		 0.5f, 0.5f,-0.5f,   0.20f,0.75f,0.20f,
		 0.5f, 0.5f, 0.5f,   0.20f,0.75f,0.20f,
		 0.5f,-0.5f, 0.5f,   0.20f,0.75f,0.20f,

		 // LEFT
		 -0.5f, 0.5f, 0.5f,   0.35f,0.85f,0.35f,
		 -0.5f, 0.5f,-0.5f,   0.35f,0.85f,0.35f,
		 -0.5f,-0.5f,-0.5f,   0.35f,0.85f,0.35f,
		 -0.5f,-0.5f,-0.5f,   0.35f,0.85f,0.35f,
		 -0.5f,-0.5f, 0.5f,   0.35f,0.85f,0.35f,
		 -0.5f, 0.5f, 0.5f,   0.35f,0.85f,0.35f,

		 // TOP
		 -0.5f, 0.5f,-0.5f,   0.40f,0.90f,0.40f,
		  0.5f, 0.5f,-0.5f,   0.40f,0.90f,0.40f,
		  0.5f, 0.5f, 0.5f,   0.40f,0.90f,0.40f,
		  0.5f, 0.5f, 0.5f,   0.40f,0.90f,0.40f,
		 -0.5f, 0.5f, 0.5f,   0.40f,0.90f,0.40f,
		 -0.5f, 0.5f,-0.5f,   0.40f,0.90f,0.40f,

		 // BOTTOM
		 -0.5f,-0.5f,-0.5f,   0.15f,0.60f,0.15f,
		  0.5f,-0.5f,-0.5f,   0.15f,0.60f,0.15f,
		  0.5f,-0.5f, 0.5f,   0.15f,0.60f,0.15f,
		  0.5f,-0.5f, 0.5f,   0.15f,0.60f,0.15f,
		 -0.5f,-0.5f, 0.5f,   0.15f,0.60f,0.15f,
		 -0.5f,-0.5f,-0.5f,   0.15f,0.60f,0.15f,
	};

	float cuboV1[] = {

		// FRONT
		-0.5f,-0.5f, 0.5f,   0.6f,0.9f,0.6f,
		 0.5f,-0.5f, 0.5f,   0.6f,0.9f,0.6f,
		 0.5f, 0.5f, 0.5f,   0.6f,0.9f,0.6f,
		 0.5f, 0.5f, 0.5f,   0.6f,0.9f,0.6f,
		-0.5f, 0.5f, 0.5f,   0.6f,0.9f,0.6f,
		-0.5f,-0.5f, 0.5f,   0.6f,0.9f,0.6f,

		// BACK
		-0.5f,-0.5f,-0.5f,   0.55f,0.85f,0.55f,
		 0.5f,-0.5f,-0.5f,   0.55f,0.85f,0.55f,
		 0.5f, 0.5f,-0.5f,   0.55f,0.85f,0.55f,
		 0.5f, 0.5f,-0.5f,   0.55f,0.85f,0.55f,
		-0.5f, 0.5f,-0.5f,   0.55f,0.85f,0.55f,
		-0.5f,-0.5f,-0.5f,   0.55f,0.85f,0.55f,

		// RIGHT
		 0.5f,-0.5f, 0.5f,   0.5f,0.8f,0.5f,
		 0.5f,-0.5f,-0.5f,   0.5f,0.8f,0.5f,
		 0.5f, 0.5f,-0.5f,   0.5f,0.8f,0.5f,
		 0.5f, 0.5f,-0.5f,   0.5f,0.8f,0.5f,
		 0.5f, 0.5f, 0.5f,   0.5f,0.8f,0.5f,
		 0.5f,-0.5f, 0.5f,   0.5f,0.8f,0.5f,

		 // LEFT
		 -0.5f, 0.5f, 0.5f,   0.65f,0.95f,0.65f,
		 -0.5f, 0.5f,-0.5f,   0.65f,0.95f,0.65f,
		 -0.5f,-0.5f,-0.5f,   0.65f,0.95f,0.65f,
		 -0.5f,-0.5f,-0.5f,   0.65f,0.95f,0.65f,
		 -0.5f,-0.5f, 0.5f,   0.65f,0.95f,0.65f,
		 -0.5f, 0.5f, 0.5f,   0.65f,0.95f,0.65f,

		 // TOP
		 -0.5f, 0.5f,-0.5f,   0.7f,1.0f,0.7f,
		  0.5f, 0.5f,-0.5f,   0.7f,1.0f,0.7f,
		  0.5f, 0.5f, 0.5f,   0.7f,1.0f,0.7f,
		  0.5f, 0.5f, 0.5f,   0.7f,1.0f,0.7f,
		 -0.5f, 0.5f, 0.5f,   0.7f,1.0f,0.7f,
		 -0.5f, 0.5f,-0.5f,   0.7f,1.0f,0.7f,

		 // BOTTOM
		 -0.5f,-0.5f,-0.5f,   0.45f,0.75f,0.45f,
		  0.5f,-0.5f,-0.5f,   0.45f,0.75f,0.45f,
		  0.5f,-0.5f, 0.5f,   0.45f,0.75f,0.45f,
		  0.5f,-0.5f, 0.5f,   0.45f,0.75f,0.45f,
		 -0.5f,-0.5f, 0.5f,   0.45f,0.75f,0.45f,
		 -0.5f,-0.5f,-0.5f,   0.45f,0.75f,0.45f,
	};
	float cuboV2[] = {

		// FRONT
		-0.5f,-0.5f, 0.5f,   0.0f,0.6f,0.0f,
		 0.5f,-0.5f, 0.5f,   0.0f,0.6f,0.0f,
		 0.5f, 0.5f, 0.5f,   0.0f,0.6f,0.0f,
		 0.5f, 0.5f, 0.5f,   0.0f,0.6f,0.0f,
		-0.5f, 0.5f, 0.5f,   0.0f,0.6f,0.0f,
		-0.5f,-0.5f, 0.5f,   0.0f,0.6f,0.0f,

		// BACK
		-0.5f,-0.5f,-0.5f,   0.0f,0.5f,0.0f,
		 0.5f,-0.5f,-0.5f,   0.0f,0.5f,0.0f,
		 0.5f, 0.5f,-0.5f,   0.0f,0.5f,0.0f,
		 0.5f, 0.5f,-0.5f,   0.0f,0.5f,0.0f,
		-0.5f, 0.5f,-0.5f,   0.0f,0.5f,0.0f,
		-0.5f,-0.5f,-0.5f,   0.0f,0.5f,0.0f,

		// RIGHT
		 0.5f,-0.5f, 0.5f,   0.0f,0.45f,0.0f,
		 0.5f,-0.5f,-0.5f,   0.0f,0.45f,0.0f,
		 0.5f, 0.5f,-0.5f,   0.0f,0.45f,0.0f,
		 0.5f, 0.5f,-0.5f,   0.0f,0.45f,0.0f,
		 0.5f, 0.5f, 0.5f,   0.0f,0.45f,0.0f,
		 0.5f,-0.5f, 0.5f,   0.0f,0.45f,0.0f,

		 // LEFT
		 -0.5f, 0.5f, 0.5f,   0.0f,0.7f,0.0f,
		 -0.5f, 0.5f,-0.5f,   0.0f,0.7f,0.0f,
		 -0.5f,-0.5f,-0.5f,   0.0f,0.7f,0.0f,
		 -0.5f,-0.5f,-0.5f,   0.0f,0.7f,0.0f,
		 -0.5f,-0.5f, 0.5f,   0.0f,0.7f,0.0f,
		 -0.5f, 0.5f, 0.5f,   0.0f,0.7f,0.0f,

		 // TOP
		 -0.5f, 0.5f,-0.5f,   0.0f,0.8f,0.0f,
		  0.5f, 0.5f,-0.5f,   0.0f,0.8f,0.0f,
		  0.5f, 0.5f, 0.5f,   0.0f,0.8f,0.0f,
		  0.5f, 0.5f, 0.5f,   0.0f,0.8f,0.0f,
		 -0.5f, 0.5f, 0.5f,   0.0f,0.8f,0.0f,
		 -0.5f, 0.5f,-0.5f,   0.0f,0.8f,0.0f,

		 // BOTTOM
		 -0.5f,-0.5f,-0.5f,   0.0f,0.35f,0.0f,
		  0.5f,-0.5f,-0.5f,   0.0f,0.35f,0.0f,
		  0.5f,-0.5f, 0.5f,   0.0f,0.35f,0.0f,
		  0.5f,-0.5f, 0.5f,   0.0f,0.35f,0.0f,
		 -0.5f,-0.5f, 0.5f,   0.0f,0.35f,0.0f,
		 -0.5f,-0.5f,-0.5f,   0.0f,0.35f,0.0f,
	};
	//VBO1,VAO1 - Cubo verde Claro
	//2 - Cubo Verde Fuerte
	//3 - Cubo Oscuro
	//4 - Cubo Verde Pasto
	//5 - Verde 1
	//6 - Verde 2
	GLuint VBO, VAO, VBO1, VAO1, VBO2,VAO2, VBO3, VAO3, VAO4, VBO4;
	GLuint VBO5, VAO5, VBO6, VAO6;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);
	
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	
	glGenVertexArrays(1, &VAO3);
	glGenBuffers(1, &VBO3);
	
	glGenVertexArrays(1, &VAO4);
	glGenBuffers(1, &VBO4);
	
	glGenVertexArrays(1, &VAO5);
	glGenBuffers(1, &VBO5);

	glGenVertexArrays(1, &VAO6);
	glGenBuffers(1, &VBO6);
	// Enlazar  Vertex Array Object
	
	//Cubo previo
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//Cubo Verde Claro
	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cuboVerdeClaro), cuboVerdeClaro, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//Cubo Verde Oscuro
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cuboVerdeOscuro), cuboVerdeOscuro, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//Cubo Gris
	glBindVertexArray(VAO3);
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cuboOscuro), cuboOscuro, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//Cubo Verde Pasto
	glBindVertexArray(VAO4);
	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cuboVerdePasto), cuboVerdePasto, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//Cubo V1
	glBindVertexArray(VAO5);
	glBindBuffer(GL_ARRAY_BUFFER, VBO5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cuboV1), cuboV1, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
	
	//Cubo V2
	glBindVertexArray(VAO6);
	glBindBuffer(GL_ARRAY_BUFFER, VBO6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cuboV2), cuboV2, GL_STATIC_DRAW);
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		//Cubo Verde Claro
		glBindVertexArray(VAO1);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(100.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//BOCA
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(8.0f, 2.5f, -8.0f));
		model = glm::scale(model, glm::vec3(7.1f, 3.1f, 3.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//Cubos Verdes Oscuros
		glBindVertexArray(VAO2);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(100.0f, -8.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//Boca Labios
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.5f, 4.5f, -8.5f));
		model = glm::scale(model, glm::vec3(2.1f, 1.1f, 2.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(2.38f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(8.0f, 3.5f, -9.1f));
		model = glm::scale(model, glm::vec3(3.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		
		//Piernas
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(2.0f, 0.0f, -1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.0f, 0.0f, -1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//Pata 2
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(14.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(15.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(15.0f, 0.0f, -1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Pata 3
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.0f, 0.0f, -9.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(6.0f, 0.0f, -10.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0,36);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(6.0f, 0.0f, -8.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//Pata 4
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(10.0f, 0.0f, -8.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.1f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(1.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Cubos Oscuros
		glBindVertexArray(VAO3);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(100.0f, 8.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//OJOS
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.5f, 6.5f, -7.5f));
		model = glm::scale(model, glm::vec3(2.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(10.5f, 6.5f, -7.5f));
		model = glm::scale(model, glm::vec3(2.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		

		//Cubos Verde Pasto
		glBindVertexArray(VAO4);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(100.0f, 16.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 8.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(3.5f,1.5f,-2.0f));
		model = glm::scale(model, glm::vec3(2.0f, 3.0f, 3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.666f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(4.5f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 1.666f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Cuerpo............................................................
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(8.0f, 3.5f, -4.5f));
		model = glm::scale(model, glm::vec3(7.0f, 5.0f, 10.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(6.0f, 7.0f, -6.5f));
		model = glm::scale(model, glm::vec3(3.0f, 2.0f, 3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(1.33333f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Cubo V1
		glBindVertexArray(VAO5);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(30.0f, 24.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.0f,3.5f,-2.5f));
		model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Detalles atras
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(6.0f, 4.5f, 0.0f));
		model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(4.0f, -2.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(-3.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//Detalles derecha
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(11.15f, 4.5f, -1.0f));
		model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, -2.5f, -5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 3.0f, 2.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//Detalles Arriba
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(8.0f, 5.52f, -0.5f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//Cubo V2
		glBindVertexArray(VAO6);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(30.0f, 32.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.0f, 3.5f, -6.5f));
		model = glm::scale(model, glm::vec3(1.15f, 1.15f, 1.15f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Detalles atras
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.0f, 2.7f, 0.0f));
		model = glm::scale(model, glm::vec3(1.15f, 1.15f, 1.15f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(3.0f, -1.0, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(-1.0f, 2.0, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(3.2f, 1.3, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//Detalles derecha
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(11.2f, 3.5f, -4.5f));
		model = glm::scale(model, glm::vec3(1.15f, 1.15f, 1.15f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Detalles Arriba
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(10.0f, 5.52f, -0.5f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(-5.0f, 0.0f, -3.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &VBO1);
	
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);

	glDeleteVertexArrays(1, &VAO3);
	glDeleteBuffers(1, &VBO3);

	glDeleteVertexArrays(1, &VAO4);
	glDeleteBuffers(1, &VBO4);

	glDeleteVertexArrays(1, &VAO5);
	glDeleteBuffers(1, &VBO5);

	glDeleteVertexArrays(1, &VAO5);
	glDeleteBuffers(1, &VBO5);
	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {		//GLFW_RELEASE
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //Cierra la Ventana
		 glfwSetWindowShouldClose(window, true);			
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)		//Mueve a la derecha
		 movX += 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)		//Mueve a la izquierda
		 movX -= 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS) //	
		 movY += 0.005;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		 movY -= 0.005;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.005;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.005;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.01;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.01;
 }


