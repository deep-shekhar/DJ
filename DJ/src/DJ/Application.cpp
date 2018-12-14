#include "djpch.h"

#include "Application.h"
#include "log.h"
#include "Events/ApplicationEvent.h"

namespace DJ {
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(600,800);
		DJ_TRACE(e);
		while (true) {

		}
	}
}
