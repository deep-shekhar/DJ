#pragma once
#include "Core_Stuff.h"
#include "Events/Event.h"
#include "Window.h"

namespace DJ {
	class DJ_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//DEFINE THIS FUNCTION IN CLIENT APP.
	Application* CreateApplication();
}
