#pragma once

#ifdef WE_PLATFORM_WINDOWS

extern WE::Application* WE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WE::CreateApplication();
	app->Run();
	delete app;
}

#endif // WE_PLATFORM_WINDOWS
