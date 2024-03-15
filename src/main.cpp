#include <string>
#include <format>
#include "Window.h"

int main() {

	Window Window{800, 600, "Hello OpenGL"};

	/* PrintInfo()
	std::cout << "GL VERSION: " << glGetString(GL_VERSION) << "\n";
	std::cout << "GL RENDERER: " << glGetString(GL_RENDERER) << "\n";
	std::cout << "GL VENDOR: " << glGetString(GL_VENDOR) << "\n";
	std::cout << "GLSL VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
	*/

	float titleUpdateMaxTime = 1.f;
	float titleUpdateElapsed = 0.f;

	while(Window.IsOpened()) 
	{	
		float DeltaTime = Window.DeltaTime();
		titleUpdateElapsed += DeltaTime;
		if (titleUpdateElapsed >= titleUpdateMaxTime) //1.1 >= 1
		{
			int fps = (int)(1.f / DeltaTime);
			std::string formattedTitle = std::format("OpenGL App | DeltaTime: {} - FPS: {}", DeltaTime, fps);
			Window.SetTitle(formattedTitle);

			titleUpdateElapsed -= titleUpdateMaxTime; //0.1
		}

		Window.Update();
	}
	return 0;	
}