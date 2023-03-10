project "LudusGame"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Hazel/src",
		"%{wks.location}/Hazel/3rdparty"
	}

	links
	{
		"Ludus"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "LD_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LD_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LD_DIST"
		runtime "Release"
		optimize "on"