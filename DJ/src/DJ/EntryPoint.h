#pragma once
#include <stdio.h>
#ifdef DJ_PLATFORM_WINDOWS
	
	extern DJ::Application* DJ::CreateApplication();

	int main(int argc,char **argv) {
		printf("Entry point of DJ engine\n");
		auto app = DJ::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}
#endif