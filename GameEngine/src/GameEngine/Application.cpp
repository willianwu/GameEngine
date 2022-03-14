#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include "Gepch.h"


namespace GameEngine {

	Application::Application() {

	}
	Application::~Application() {

	}
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		GE_CORE_TRACE(e);
		while (true);
	}
}