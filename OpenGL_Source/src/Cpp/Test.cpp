#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Headers/ShaderClass.h"
#include <filesystem>



void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int success;
char infoLog[512];

int main(int argc, TCHAR argv[])
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

	Shader subShader("C:/Users/JoonasTuo/Desktop/asdf/x64/Debug/Shaders/fragmentshader.fs", "C:/Users/JoonasTuo/Desktop/asdf/x64/Debug/Shaders/vertexshader.vs");
	//Shader subShader( "Shaders/vertexshader.vs", "Shaders/fragmentshader.fs");


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	
	///glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	glViewport(0, 0, 800, 600);


	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);
		//rendering
		glClearColor(0.2f, 0.2f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		subShader.Use();
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

