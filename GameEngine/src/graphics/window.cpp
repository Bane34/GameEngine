#include "window.h"

namespace bane {
	bool Window::m_Keys[MAX_KEYS];
	bool Window::m_Buttons[MAX_BUTTONS];
	double Window::m_MouseX;
	double Window::m_MouseY;
	GLboolean Window::drawMode = GL_FALSE;

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_Keys[key] = action != GLFW_RELEASE;
		std::function<void()> f;

		if ((f = win->callbacks[key]) && action == GLFW_PRESS) {
			f();
		}
		else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
			if (win->drawMode)
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			win->drawMode = !(win->drawMode);
		}
	}

	void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_Buttons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer;
		win->m_MouseX = xpos;
		win->m_MouseY = ypos;
	}

	Window::Window(const char* title, int width, int height) {
		m_Title = title;
		m_Width = width;
		m_Height = height;

		init();
		initImGui();
	}

	Window::~Window() {
		// CLEAN UP IMGUI //
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		// CLEAN UP GLFW //
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::update() {
		glfwPollEvents(); // Poll events
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		//std::cout << "[" << m_Width << ", " << m_Height << "]\n";
	}

	void Window::clear() const {
		ImGui::Render();
		glClearColor(0.2f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::render() {
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(m_Window);
		glfwSwapInterval(1);
	}

	void Window::insertCallback(std::function<void()> callback, int key) {
		callbacks[key] = callback;
	}

	void Window::init() {
		if (!glfwInit()) {
			std::cout << "Could not init glfw\n";
			return;
		}

		memset(m_Keys, false, MAX_KEYS); 
		memset(m_Buttons, false, MAX_BUTTONS);

		glfwSetErrorCallback(error_callback);

		// SELECT THE VERSION OF OPENGL TO USE //
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_REFRESH_RATE, 60);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window) {
			glfwTerminate();
			std::cout << "Could not init window\n";
			return;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);

		glfwSetWindowSizeCallback(m_Window, framebuffer_size_callback);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		glewInit();
		glewExperimental = true;

	}

	void Window::initImGui() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io; 
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		ImGui::StyleColorsDark();;
		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 330"); //glsl version
	}

	void error_callback(int error, const char* description) {
		fprintf(stderr, "Error: %s\n", description);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
}