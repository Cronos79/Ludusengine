project "Ludus"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ldpch.h"
	pchsource "src/ldpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	defines
	{
	}

	includedirs
	{
		"src",
		"3rdparty/spdlog/include"
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

		links
		{
			--"%{Library.WinSock}",
			--"%{Library.WinMM}",
			--"%{Library.WinVersion}",
			--"%{Library.BCrypt}",
		}

	filter "configurations:Debug"
		defines "LD_DEBUG"
		runtime "Debug"
		symbols "on"

		links
		{
		}

	filter "configurations:Release"
		defines "LD_RELEASE"
		runtime "Release"
		optimize "on"

		links
		{
		}

	filter "configurations:Dist"
		defines "LD_DIST"
		runtime "Release"
		optimize "on"

		links
		{
		}