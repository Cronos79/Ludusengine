#include "ldpch.h"
#include "Application.h"
#include "Log.h"

Ludus::Application::Application(const ApplicationSpecification& specification)
{

}

Ludus::Application::~Application()
{

}

void Ludus::Application::Begin()
{

}

void Ludus::Application::Tick(float dt)
{

}

void Ludus::Application::Run()
{
	Log::Init();
	LD_CORE_INFO("Loading application!");
	Begin();
	IsRunning = true;
	while (IsRunning)
	{
		Tick(0.0f); // #TODO: Add a timer
	}
}
