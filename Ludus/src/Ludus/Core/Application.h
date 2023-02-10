#pragma once
#include <string>
#include "Ludus/Core/Window.h"
#include "Ludus/Core/LayerStack.h"
#include "../Events/ApplicationEvent.h"
#include "Ludus/Core/Timestep.h"

int main(int argc, char** argv);

namespace Ludus 
{
	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			LD_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	struct ApplicationSpecification
	{
		float Width = 1600;
		float Height = 720;
		std::string Name = "Ludus Application";
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		Window& GetWindow() { return *m_Window; }
		void Close();
		virtual void Begin();
		virtual void Tick(float dt);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		void Run();
	private:
		bool IsRunning{ false };
		bool m_Minimized = false;
		ApplicationSpecification m_Specification;
		Scope<Window> m_Window;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		//static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}