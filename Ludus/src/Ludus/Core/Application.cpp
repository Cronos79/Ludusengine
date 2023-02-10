#include "ldpch.h"
#include "Application.h"
#include "Log.h"

Ludus::Application::Application(const ApplicationSpecification& specification)
	: m_Specification(specification)
{
	/*LD_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;*/

	// Set working directory here
	if (!m_Specification.WorkingDirectory.empty())
		std::filesystem::current_path(m_Specification.WorkingDirectory);
	WindowProps props;
	props.Title = m_Specification.Name;
	props.Width = m_Specification.Width;
	props.Height = m_Specification.Height;
	m_Window = Window::Create(props); //#Note: Set window size in props
	m_Window->SetEventCallback(LD_BIND_EVENT_FN(Application::OnEvent));
}

Ludus::Application::~Application()
{

}

void Ludus::Application::OnEvent(Event& e)
{
	//HZ_PROFILE_FUNCTION();

	//LD_CORE_INFO(e.ToString());

	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(LD_BIND_EVENT_FN(Application::OnWindowClose));
	dispatcher.Dispatch<WindowResizeEvent>(LD_BIND_EVENT_FN(Application::OnWindowResize));

	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
	{
		if (e.Handled)
			break;
		(*it)->OnEvent(e);
	}
}

void Ludus::Application::PushLayer(Layer* layer)
{
	//HZ_PROFILE_FUNCTION();

	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Ludus::Application::PushOverlay(Layer* layer)
{
	//HZ_PROFILE_FUNCTION();

	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
}

void Ludus::Application::Close()
{
	IsRunning = false;
}

void Ludus::Application::Begin()
{

}

void Ludus::Application::Tick(float dt)
{

}

bool Ludus::Application::OnWindowClose(WindowCloseEvent& e)
{
	IsRunning = false;
	return true;
}

bool Ludus::Application::OnWindowResize(WindowResizeEvent& e)
{
	//HZ_PROFILE_FUNCTION();

	if (e.GetWidth() == 0 || e.GetHeight() == 0)
	{
		m_Minimized = true;
		return false;
	}

	m_Minimized = false;
	//Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

	return false;
}

#include "Ludus/Core/Timer.h"

void Ludus::Application::Run()
{
	Timer* timer = new Timer();
	timer->Reset();
	LD_CORE_INFO("Loading application!");
	Begin();
	IsRunning = true;
	while (IsRunning)
	{
		if (!m_Minimized)
		{
			{
				//HZ_PROFILE_SCOPE("LayerStack OnUpdate");

				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timer->ElapsedMillis());
			}

		/*	m_ImGuiLayer->Begin();
			{
				HZ_PROFILE_SCOPE("LayerStack OnImGuiRender");

				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();*/
		}
		m_Window->OnUpdate();
		Tick(timer->ElapsedMillis()); // #TODO: Timer needs testing
		timer->Reset();
	}
}
