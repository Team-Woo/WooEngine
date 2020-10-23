#include <WooEngine.h>

class ExampleLayer : public WE::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		WE_INFO("ExampleLayer::Update");
	}

	void OnEvent(WE::Event& event) override
	{
		WE_TRACE("{0}", event);
	}

};


class Sandbox : public WE::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

WE::Application* WE::CreateApplication()
{
	return new Sandbox();
}