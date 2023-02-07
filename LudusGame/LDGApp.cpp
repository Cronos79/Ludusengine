#include "Ludus.h"
#include "Ludus/Core/EntryPoint.h"

class LDGApp : public Ludus::Application
{
public:
	LDGApp(const Ludus::ApplicationSpecification& spec)
		: Ludus::Application(spec)
	{

	}

	~LDGApp()
	{

	}
};

Ludus::Application* Ludus::CreateApplication(Ludus::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "LudusGame";
	spec.WorkingDirectory = "../LudusGame";
	spec.CommandLineArgs = args;

	return new LDGApp(spec);
}