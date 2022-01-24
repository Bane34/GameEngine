#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>
#include <cstdio>

namespace bane {

	#define MAX_KEYS	1024
	#define MAX_BUTTONS 32
	
	class Window {
	private:
		const char* m_Title;
		int m_Width, m_Height;

		GLFWwindow* m_Window;

		static bool m_Keys[MAX_KEYS];
		static bool m_Buttons[MAX_BUTTONS];
		static double m_MouseX, m_MouseY;
		static GLboolean drawMode;

		bool m_Closed;
	public:
		Window(const char* title, int width, int height);
		~Window();

		void update();
		void clear() const;
		void render();

		inline bool			closed()			const { return glfwWindowShouldClose(m_Window); }
		inline GLFWwindow*	getWindow()				  { return m_Window; }
		inline int			getWidth()			const { return m_Width; }
		inline int			getHeight()			const { return m_Height;  }
	
		inline bool  isKeyPressed(int keycode)		  { return m_Keys[keycode]; }
		inline bool  isMouseButtonPressed(int button) { return m_Buttons[button]; }
	private:
		void init();
		void ImGUIinit();
		
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend static void joystick_callback(int jid, int event);
	};
	
	static void error_callback(int error, const char* description);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}