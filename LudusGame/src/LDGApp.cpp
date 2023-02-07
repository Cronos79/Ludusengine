#include "LDGApp.h"
#include "Ludus/Core/EntryPoint.h"

Ludus::Application* Ludus::CreateApplication(Ludus::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "LudusGame";
	spec.WorkingDirectory = "../LudusGame";
	spec.CommandLineArgs = args;

	return new LDGApp(spec);
}

LDGApp::LDGApp(const Ludus::ApplicationSpecification& spec)
	: Application(spec)
{

}

LDGApp::~LDGApp()
{

}

void LDGApp::Begin()
{
	
}

void LDGApp::Tick(float dt)
{
	
}

