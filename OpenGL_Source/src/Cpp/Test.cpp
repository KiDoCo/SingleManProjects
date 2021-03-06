#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderClass.h"



void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void ShaderProgram();
void ShaderAttributeSetter();
void Compileshaders();

int success;
char infoLog[512];

int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "Learnibduoterb", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init glad" << std::endl;
		return -1;
	}

	///-------------------------------------------------


	float vertices[] = {
	0.5f, 0.5f,0.0f, 1.0f, 0.0f, 0.0f,
	0.5f,-0.5f,0.0f, 0.0f, 1.0f, 0.0f,
	-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	-0.4f,-0.5f,0.0f,1.0f,0.0f,1.0f
	};

	unsigned int indices[] =
	{
		//fisrt
		0,1,3,
		//second
		1,2,3
	};
	unsigned int VBO, VAO, EBO;
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	///glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Compileshaders();
	ShaderProgram();


	glViewport(0, 0, 800, 600);


	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);
		//rendering
		glClearColor(0.2f, 0.2f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		//check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}

void FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Compileshaders()
{


	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex, NULL);
	glCompileShader(vertexShader);

	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &frag, NULL);
	glCompileShader(fragmentshader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "asdf" << infoLog << std::endl;
	}

	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "fdsa" << infoLog << std::endl;
	}
}



void ShaderAttributeSetter()
{
	float timeValue = glfwGetTime();
	float greenval = (sin(timeValue) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	glUseProgram(shaderProgram);
	glUniform4f(vertexColorLocation, 0.0f, greenval, 0.0f, 1.0f);
}
