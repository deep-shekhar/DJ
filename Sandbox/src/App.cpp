#include <stdio.h>
#include "DJ.h"

class Sandbox : public DJ::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

DJ::Application* DJ::CreateApplication(){
	return new Sandbox();
}
