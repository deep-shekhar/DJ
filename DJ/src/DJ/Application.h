#pragma once
#include "Core_Stuff.h"
#include "Events/Event.h"

namespace DJ {
	class DJ_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};

	//DEFINE THIS FUNCTION IN CLIENT APP.
	Application* CreateApplication();
}
