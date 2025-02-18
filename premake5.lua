workspace "Dream"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Dream/vendor/GLFW/include"

include "Dream/vendor/GLFW"

project "Dream"
	location "Dream"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	pchheader "dmpch.h"
	pchsource "Dream/src/dmpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"DM_PLATFORM_WINDOWS",
			"DM_BUILD_DLL"
		}

		buildoptions { "/utf-8" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DM_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Dream/vendor/spdlog/include",
		"Dream/src"
	}

	links
	{
		"Dream"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"DM_PLATFORM_WINDOWS"
		}

		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "DM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DM_DIST"
		optimize "On"