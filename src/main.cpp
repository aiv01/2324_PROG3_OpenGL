#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <format>

int main() {

	if (glfwInit() == 0) 
	{
		std::cout << "Error glfw init\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	int width = 800;
	int height = 600;
	const std::string title = "HelloOpenGL";
	GLFWmonitor* monitor = NULL;

	GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), monitor, NULL);
	if (window == NULL) {
		std::cout << "Error creating window\n";
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (gladLoadGL() == 0) 
	{
		std::cout << "Error loading GL Functions\n";
		return -1;
	}

	std::cout << "GL VERSION: " << glGetString(GL_VERSION) << "\n";
	std::cout << "GL RENDERER: " << glGetString(GL_RENDERER) << "\n";
	std::cout << "GL VENDOR: " << glGetString(GL_VENDOR) << "\n";
	std::cout << "GLSL VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

	float lastTime = glfwGetTime();
	float deltaTime = 0.f;

	float titleUpdateMaxTime = 1.f;
	float titleUpdateElapsed = 0.f;

	while(!glfwWindowShouldClose(window))
	{
		float currTime = glfwGetTime();
		deltaTime = currTime - lastTime;
		lastTime = currTime;
		
		titleUpdateElapsed += deltaTime;

		if (titleUpdateElapsed >= titleUpdateMaxTime) //1.1 >= 1
		{
			int fps = (int)(1.f / deltaTime);
			std::string formattedTitle = std::format("OpenGL App | DeltaTime: {} - FPS: {}", deltaTime, fps);
			glfwSetWindowTitle(window, formattedTitle.c_str());

			titleUpdateElapsed -= titleUpdateMaxTime; //0.1
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	return 0;	
}