#include "ldpch.h"
#include "Application.h"
#include "Log.h"

Ludus::Application::Application(const ApplicationSpecification& specification)
	: m_Specification(specification)
{
	m_Window = Window::Create(WindowProps(m_Specification.Name));
	m_Window->SetEventCallback(LD_BIND_EVENT_FN(Application::OnEvent));
}

Ludus::Application::~Application()
{

}

void Ludus::Application::OnEvent(Event& e)
{
	//HZ_PROFILE_FUNCTION();

	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(LD_BIND_EVENT_FN(Application::OnWindowClose));
	dispatcher.Dispatch<WindowResizeEvent>(LD_BIND_EVENT_FN(Application::OnWindowResize));

	//for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
	//{
	//	if (e.Handled)
	//		break;
	//	(*it)->OnEvent(e);
	//}
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

void Ludus::Application::Run()
{
	LD_CORE_INFO("Loading application!");
	Begin();
	IsRunning = true;
	while (IsRunning)
	{
		m_Window->OnUpdate();
		Tick(0.0f); // #TODO: Add a timer
	}
}
