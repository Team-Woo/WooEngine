#pragma once

#include "WooEngine\Layer.h"

namespace WE {

	class WOOENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;
	};

}