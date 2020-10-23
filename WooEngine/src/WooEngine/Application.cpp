#include "Application.h"

#include "WooEngine\Events\ApplicationEvent.h"
#include "WooEngine\Log.h"

namespace WE {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			WE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			WE_TRACE(e);

			while (true);
		}
	}
}