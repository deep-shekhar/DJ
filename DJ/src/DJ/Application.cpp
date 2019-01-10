#include "djpch.h"
#include "Application.h"
#include "log.h"

namespace DJ {
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(onEvent));
	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		DJ_CORE_TRACE("An event has occurred- {0}",e);
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

	bool Application::OnWindowClose(WindowCloseEvent &e) {
		m_Running = false;
		return true;
	}
}
