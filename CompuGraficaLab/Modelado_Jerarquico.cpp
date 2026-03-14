//Nombre: Torres Martinez Victor Manuel
//Fecha 09/03/26
//Practica 5: Modelado Jerarquico
//:)
#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 1200, HEIGHT = 800;

//For Keyboard
float	movX = 0.0f,
movY = 0.0f,
movZ = -5.0f,
rot = 0.0f;

//For model
float	hombro = 0.0f,
codo = 0.0f,
muneca = 0.0f,
dedo = 0.0f, //Indice
dedo2 = 0.0f,
dedo22 = 0.0f, 
dedo3 = 0.0f, //Medio
dedo33 = 0.0f,
dedo333 = 0.0f,
dedo4 = 0.0f, //Anular
dedo44 = 0.0f,
dedo444 = 0.0f,
dedo5 = 0.0f, //Menique
dedo55 = 0.0f,
dedo555 = 0.0f,
dedo6 = 0.0f, //Pulgar
dedo66 = 0.0f;

int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Modelado jerarquico Victor Manuel Torres Martinez", nullptr, nullptr);

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
	// use with Orthographic Projection


	

	// use with Perspective Projection
	float vertices[] = {
		-0.5f, -0.5f, 0.5f, 
		0.5f, -0.5f, 0.5f,  
		0.5f,  0.5f, 0.5f,  
		0.5f,  0.5f, 0.5f,  
		-0.5f,  0.5f, 0.5f, 
		-0.5f, -0.5f, 0.5f, 
		
	    -0.5f, -0.5f,-0.5f, 
		 0.5f, -0.5f,-0.5f, 
		 0.5f,  0.5f,-0.5f, 
		 0.5f,  0.5f,-0.5f, 
	    -0.5f,  0.5f,-0.5f, 
	    -0.5f, -0.5f,-0.5f, 
		
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  -0.5f, 0.5f,
      
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f, 
		0.5f, -0.5f,  0.5f, 
		0.5f, -0.5f,  0.5f, 
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,
		
		-0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f, 
		0.5f,  0.5f,  0.5f, 
		0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
	};




	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	glm::vec3 color= glm::vec3(0.0f, 0.0f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
		glm::mat4 modelTemp = glm::mat4(1.0f); //Temp
		glm::mat4 modelTemp2 = glm::mat4(1.0f); //Temp



		//View set up 
		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
		
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");
		GLint uniformColor = ourShader.uniformColor;

		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
	

		glBindVertexArray(VAO);
		
		//Model Bicep
		model = glm::rotate(model, glm::radians(hombro), glm::vec3(0.0f, 0.0, 1.0f)); //hombro
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //Envio de color
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//A
		modelTemp = model = glm::translate(model, glm::vec3(1.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(3.0f, 1.0f, 1.0f));
		color = glm::vec3(0.0f, 1.0f, 0.0f); //Vector de color
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //Envio de color
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//A

		//Model Antebrazo
		model = glm::translate(modelTemp, glm::vec3(1.5f,0.0f,0.0f));
		model = glm::rotate(model, glm::radians(codo),glm::vec3(0.0f,1.0f,0.0f));
		modelTemp = model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model,glm::vec3(2.0f, 1.0f, 1.0f));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//B

		//Model Palma
		model = glm::translate(modelTemp, glm::vec3(1.0f,0.0f,0.0f));
		model = glm::rotate(model, glm::radians(muneca), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model,glm::vec3(2.0f, 1.0f, 1.0f));
		modelTemp2 = modelTemp = model = glm::translate(model, glm::vec3(0.25f,0.0f,0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 1.0f, 1.0f));
		color = glm::vec3(1.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//C

		//Model Dedo
		model = glm::translate(modelTemp, glm::vec3(0.25f, 0.35f, 0.375f));
		model = glm::rotate(model, glm::radians(dedo), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(0.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//C

		//Model Dedo2
		model = glm::translate(modelTemp, glm::vec3(0.5f,0.0f,0.0f));
		model = glm::rotate(model, glm::radians(dedo2), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(1.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D

		//Model Dedo 22
		model = glm::translate(modelTemp, glm::vec3(0.35f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo2), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.75f, 0.3f, 0.25f));
		color = glm::vec3(0.5f, 0.7f, 1.5f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D


		//Model Dedo Medio
		model = glm::translate(modelTemp2, glm::vec3(0.25f, 0.35f, 0.1));
		model = glm::rotate(model, glm::radians(dedo3), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(0.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//C

		//Dedo medio 2
		model = glm::translate(modelTemp, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo33), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(1.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D

		//Dedo Medio 3
		model = glm::translate(modelTemp, glm::vec3(0.35f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo33), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.75f, 0.3f, 0.25f));
		color = glm::vec3(0.5f, 0.7f, 1.5f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D
		
		
		//Model Dedo indice
		model = glm::translate(modelTemp2, glm::vec3(0.25f, 0.35f, -0.2));
		model = glm::rotate(model, glm::radians(dedo4), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(0.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//C

		//Dedo indice 2
		model = glm::translate(modelTemp, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo44), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(1.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D

		//Dedo indice 3
		model = glm::translate(modelTemp, glm::vec3(0.35f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo44), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.75f, 0.3f, 0.25f));
		color = glm::vec3(0.5f, 0.7f, 1.5f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D

		
		//Model Dedo anular
		model = glm::translate(modelTemp2, glm::vec3(0.25f, 0.35f, -0.5));
		model = glm::rotate(model, glm::radians(dedo5), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(0.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//C

		//Dedo anular 2
		model = glm::translate(modelTemp, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo55), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.3f, 0.25f));
		color = glm::vec3(1.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D
		
		//Dedo anular 3
		model = glm::translate(modelTemp, glm::vec3(0.35f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo33), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.75f, 0.3f, 0.25f));
		color = glm::vec3(0.5f, 0.7f, 1.5f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D

		//Dedo Pulgar
		model = glm::translate(modelTemp2, glm::vec3(0.25f,-0.25f,0.45f));
		model = glm::rotate(model, glm::radians(dedo6), glm::vec3(0.0f,1.0f,0.0f));
		modelTemp = model = glm::translate(model, glm::vec3(0.5f,0.0f,0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.55f, 0.25f));
		color = glm::vec3(0.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//C


		//Dedo pulgar 2
		model = glm::translate(modelTemp, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(dedo66), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.53f, 0.25f));
		color = glm::vec3(1.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);//D
		glBindVertexArray(0);

		
		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.015f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.015f;
	 if (glfwGetKey(window,GLFW_KEY_UP) == GLFW_PRESS)
		 movY += 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		 movY -= 0.015f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.015f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.015f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.09f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.09f;
	 if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		 if (hombro >= 100) {
			 hombro += 0.36f;
			 hombro -= 0.72f;
		 }else hombro += 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		 if (hombro <= -90) {
			 hombro -= 0.36;
			 hombro += 0.72;
		 }else hombro -= 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
		 if (codo >= 10) {
			 codo += 0.36;
			 codo -= 0.72;
		 }else codo += 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		 if (codo <= -150) {
			 codo -= 0.36;
			 codo += 0.72;
		 }else codo -= 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
		 if (muneca >= 180) {
			 muneca += 0.36;
			 muneca -= 0.72;
		 }else muneca += 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		 if (muneca <= -180) {
			 muneca -= 0.36;
			 muneca += 0.36;
		 }else muneca -= 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
		 if (dedo >= 30) {
			 dedo += 0.09;
			 dedo -= 0.18;
		 } else dedo += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
		 if (dedo < -90) {
			 dedo -= 0.09;
			 dedo += 0.18;
		 }else dedo -= 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
		 if (dedo2 >= 15) {
			 dedo2 += 0.09;
			 dedo2 -= 0.18;
		 }else dedo2 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
		 if (dedo2 <= -62.2) {
			 dedo2 -= 0.09;
			 dedo2 += 0.18;
		 }else dedo2 -= 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
		 if (dedo3 >= 30) {
			 dedo3 += 0.09;
			 dedo3 -= 0.18;
		 }
		 else dedo3 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		 if (dedo3 <= -90) {
			 dedo3 -= 0.09;
			 dedo3 += 0.18;
		 }
		 else dedo3 -= 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		 if (dedo33 >= 15) {
			 dedo33 += 0.09;
			 dedo33 -= 0.18;
		 }
		 else dedo33 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_SEMICOLON) == GLFW_PRESS) {
		 if (dedo33 <= -62.2) {
			 dedo33 -= 0.09;
			 dedo33 += 0.18;
		 }else dedo33 -= 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		 if (dedo4 >= 30) {
			 dedo4 += 0.09;
			 dedo4 -= 0.18;
		 }
		 else dedo4 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		 if (dedo4 <= -90) {
			 dedo4 -= 0.09;
			 dedo4 += 0.18;
		 }
		 else dedo4 -= 0.09f;
	 }
		 
	 if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		 if (dedo44 >= 15) {
			 dedo44 += 0.09;
			 dedo44 -= 0.18;
		 }
		 else dedo44 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		 if (dedo44 <= -62.2) {
			 dedo44 -= 0.09;
			 dedo44 += 0.18;
		 }else dedo44 -= 0.09f;
	 }
	
	 if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
		 if (dedo5 >= 30) {
			 dedo5 += 0.09;
			 dedo5 -= 0.18;
		 }else dedo5 += 0.09f;
	 }
		
	 if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {
		 if (dedo5 <= -90) {
			 dedo5 -= 0.09;
			 dedo5 += 0.18;
		 }
		 else dedo5 -= 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) {
		 if (dedo55 >= 15) {
			 dedo55 += 0.09;
			 dedo55 -= 0.18;
		 }
		 else dedo55 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS) {
		 if (dedo55 <= -62.2) {
			 dedo55 -= 0.09;
			 dedo55 += 0.18;
		 }
		 else dedo55 -= 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) {
		 if (dedo6 >= 90) {
			 dedo6 += 0.09;
			 dedo6 -= 0.18;
		 }
		 else dedo6 += 0.09f;
	 } 
	 if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) {
		 if (dedo6 <= -90) {
			 dedo6 -= 0.09;
			 dedo6 += 0.18;
		 }
		 else dedo6 -= 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS) {
		 if (dedo66 >= 90) {
			 dedo66 += 0.09;
			 dedo66 -= 0.18;
		 }
		 else dedo66 += 0.09f;
	 }
	 if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) {
		 if (dedo66 <= -30) {
			 dedo66 -= 0.09;
			 dedo66 += 0.18;
		 }
		 else dedo66 -= 0.09f;
	 }
 }