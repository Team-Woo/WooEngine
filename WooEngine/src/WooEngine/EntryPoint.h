#pragma once

#ifdef WE_PLATFORM_WINDOWS

extern WE::Application* WE::CreateApplication();

int main(int argc, char** argv)
{
	WE::Log::Init();

	WE_CORE_WARN("Initilized Log!");
	int a = 69;
	WE_INFO("Hello Var={0}", a);

	auto app = WE::CreateApplication();
	app->Run();
	delete app;
}

#endif // WE_PLATFORM_WINDOWS
