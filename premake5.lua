workspace "Ludus"
	architecture "x86_64"
	startproject "LudusGame"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Ludus/3rdparty/GLFW"
	--include "3rdparty/premake"
group ""

group "Core"
	include "Ludus"
group ""

group "Tools"
	
group ""

group "Games"
	include "LudusGame"
group ""