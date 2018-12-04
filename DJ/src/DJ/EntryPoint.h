#pragma once

#ifdef DJ_PLATFORM_WINDOWS

	extern DJ::Application* DJ::CreateApplication();

	int main(int argc,char **argv) {
		
		DJ::log::Init();

		DJ_CORE_WARN("Inialized Logger!");
		int a = 7;
		DJ_INFO("Hello var={0}",a);

		auto app = DJ::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}

#endif