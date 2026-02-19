//Alumno: Torres Martinez Victor Manuel
//Fecha 18/02/26
//Practica 2: Dibujos de Primitivas en 2D
#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Dibujo de Primitivas en 2D Victor Manuel Torres Martinez", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");
	//Alumno: Torres Martinez Victor Manuel
	//Fecha 18/02/26
	//Practica 2: Dibujos de Primitivas en 2D
	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		-0.89f, -0.39f, 0.0f, 0.749f, 0.937f, 0.949f,
		-0.65f, -0.19f, 0.0f, 0.557f, 0.824f, 0.788f,
		-0.46f, -0.07f, 0.0f, 0.659f, 0.902f, 0.812f,
		-0.24f,  0.1f,  0.0f, 0.557f, 0.824f, 0.788f,
		-0.07f,  0.17f, 0.0f, 0.957f, 0.980f, 0.792f,
		0.15f,  0.26f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.04f,  0.08f,  0.0f, 0.749f, 0.937f, 0.949f,
		-0.09f,  0.06f, 0.0f, 0.557f, 0.824f, 0.788f,
		-0.32f, -0.17f, 0.0f, 0.659f, 0.902f, 0.812f,
		-0.4f,  -0.32f, 0.0f, 0.557f, 0.824f, 0.788f,
		-0.41f, -0.22f, 0.0f, 0.659f, 0.902f, 0.812f,
		-0.58f, -0.4f,  0.0f, 0.957f, 0.980f, 0.792f,
		-0.44f, -0.41f, 0.0f, 0.557f, 0.824f, 0.788f,
		-0.51f, -0.56f, 0.0f, 0.749f, 0.937f, 0.949f,
		-0.78f, -0.48f, 0.0f, 0.659f, 0.902f, 0.812f,
		-0.25f, -0.52f, 0.0f, 0.957f, 0.980f, 0.792f,
		-0.38f, -0.53f, 0.0f, 0.659f, 0.902f, 0.812f,
		-0.13f, -0.62f, 0.0f, 0.557f, 0.824f, 0.788f,
		0.0f,  -0.48f, 0.0f, 0.957f, 0.980f, 0.792f,
		0.12f, -0.52f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.24f, -0.43f, 0.0f, 0.957f, 0.980f, 0.792f,
		0.40f, -0.30f, 0.0f, 0.659f, 0.902f, 0.812f,
		0.29f, -0.13f, 0.0f, 0.957f, 0.980f, 0.792f,
		0.06f, -0.24f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.22f, -0.03f, 0.0f, 0.659f, 0.902f, 0.812f,
		0.13f, -0.16f, 0.0f, 0.957f, 0.980f, 0.792f,
		-0.03f,  0.0f,  0.0f, 0.659f, 0.902f, 0.812f,
		-0.09f, -0.22f, 0.0f, 0.557f, 0.824f, 0.788f,
		-0.15f, -0.43f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.19f,  0.11f, 0.0f, 0.659f, 0.902f, 0.812f,
		0.12f,  -0.01f, 0.0f, 0.957f, 0.980f, 0.792f,
		0.44f, -0.12f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.57f, -0.16f, 0.0f, 0.557f, 0.824f, 0.788f,
		0.75f,  0.02f, 0.0f, 0.659f, 0.902f, 0.812f,
		0.67f, -0.25f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.95f,  0.01f, 0.0f, 0.957f, 0.980f, 0.792f,
		0.72f, -0.29f, 0.0f, 0.749f, 0.937f, 0.949f,
		0.77f, -0.53f, 0.0f, 0.557f, 0.824f, 0.788f,
		0.82f, -0.39f, 0.0f, 0.557f, 0.824f, 0.788f,
	};
	unsigned int indices[] = {  // note that we start from 0!
		0,1,11,
		1,10,11,
		1,2,10,
		2,8,9,
		10,11,9,
		9,11,12,
		3,4,7,
		0,14,11,
		13,9,15,
		9,15,28,
		9,8,28,
		8,27,28,
		8,27,26,
		8,7,26,
		2,8,7,
		2,3,7,
		4,7,6,
		7,29,30,
		26,27,25,
		7,24,25,
		24,22,23,
		24,31,21,
		31,32,21,
		31,33,32,
		32,33,34,
		33,35,34,
		32,36,21,
		21,36,37,
		36,38,37,
		22,21,20,
		23,22,20,
		27,25,23,
		23,20,18,
		23,18,15,
		27,23,28,
		16,18,17,
		18,19,17,
		14,11,13,
		11,12,13,
		4,5,6
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//Alumno: Torres Martinez Victor Manuel
		//Fecha 18/02/26
		//Practica 2: Dibujos de Primitivas en 2D

		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);


        glPointSize(10);
        //glDrawArrays(GL_POINTS,0,40);
        
        //glDrawArrays(GL_LINES,0,40);
        //glDrawArrays(GL_LINE_LOOP,0,60);
        
        //glDrawArrays(GL_TRIANGLES,0,30);
		//glDrawElements(GL_LINES, 120, GL_UNSIGNED_INT, 0);
        glDrawElements(GL_TRIANGLES, 120 ,GL_UNSIGNED_INT,0);
        
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}