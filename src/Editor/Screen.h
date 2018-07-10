#ifndef Screen_h
#define Screen_h

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>
#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"

//#if Debug
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // ȥ����ɫ����̨����
//#endif //  Debug

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  //���������������ڴ�С����ʱ�����ĺ���
void processInput(GLFWwindow *window);                                      //������������ĺ���

void mouse_callback(GLFWwindow* window, double xpos, double ypos);          //��괦������
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);   //���ִ�������

#if defined(_WIN32)
#if defined(NANOGUI_BUILD)
#      define TmingAPI __declspec(dllexport)
#else
#      define TmingAPI __declspec(dllimport)
#endif
#endif

class Screen
{
public:
	GLFWwindow * window;
	unsigned int texture1, texture2;
	Shader ourShader;
	unsigned int VBO, VAO;

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	Screen();
	~Screen();
	void Initialize();
	void Update();
	void ShutDown();

	bool ScreenShouldClose();

private:
	void InitImgui();
};

#endif // 