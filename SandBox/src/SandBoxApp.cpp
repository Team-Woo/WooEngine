#include <WooEngine.h>

class Sandbox : public WE::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox() 
	{

	}
};

WE::Application* WE::CreateApplication()
{
	return new Sandbox();
}