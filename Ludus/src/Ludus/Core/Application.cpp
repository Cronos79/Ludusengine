#include "ldpch.h"
#include "Application.h"

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
	Begin();
	IsRunning = true;
	while (IsRunning)
	{
		Tick(0.0f); // #TODO: Add a timer
	}
}
