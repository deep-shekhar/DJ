#include "djpch.h"

#include "Application.h"
#include "log.h"
#include "Events/ApplicationEvent.h"

namespace DJ {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		
		while (m_Running) 
		{
			m_Window->OnUpdate();

		}
	}
}
