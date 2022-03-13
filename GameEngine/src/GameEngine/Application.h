#pragma once

#include "Core.h"

namespace GameEngine {
	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};
	//to be defined in Client
	Application* CreateApplication();
}


