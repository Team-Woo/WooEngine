#pragma once

#ifdef WE_PLATFORM_WINDOWS

extern WE::Application* WE::CreateApplication();

int main(int argc, char** argv)
{
	printf("Woo Engine\n");
	auto app = WE::CreateApplication();
	app->Run();
	delete app;
}

#endif // WE_PLATFORM_WINDOWS
