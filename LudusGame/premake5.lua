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
		"src",
		"%{wks.location}/Ludus/src",
		"%{wks.location}/Ludus/3rdparty",
		"%{wks.location}/Ludus/3rdparty/spdlog/include"
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