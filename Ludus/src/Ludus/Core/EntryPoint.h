#pragma once
#include "ldpch.h"
#include "Application.h"

#ifdef LD_PLATFORM_WINDOWS

extern Ludus::Application* Ludus::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	//Hazel::Log::Init();

	//HZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = Ludus::CreateApplication({ argc, argv });
	//HZ_PROFILE_END_SESSION();

	//HZ_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	//HZ_PROFILE_END_SESSION();

	//HZ_PROFILE_BEGIN_SESSION("Shutdown", "HazelProfile-Shutdown.json");
	delete app;
	//HZ_PROFILE_END_SESSION();
}

#endif