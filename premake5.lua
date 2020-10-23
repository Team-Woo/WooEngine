workspace "WooEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "WooEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "WooEngine/vendor/Glad/include"

include "WooEngine/vendor/GLFW"
include "WooEngine/vendor/Glad"


project "WooEngine"
	location "WooEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wepch.h"
	pchsource "WooEngine/src/wepch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WE_PLATFORM_WINDOWS",
			"WE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "WE_DEBUG"
			buildoptions "/MDd"
			symbols "On"

			
		filter "configurations:Release"
			defines "WE_RELEASE"
			buildoptions "/MD"
			optimize "On"

			
		filter "configurations:Dist"
			defines "WE_DIST"
			buildoptions "/MD"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"WooEngine/vendor/spdlog/include",
		"WooEngine/src"
	}

	links
	{
		"WooEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WE_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "WE_DEBUG"
			buildoptions "/MDd"
			symbols "On"

			
		filter "configurations:Release"
			defines "WE_RELEASE"
			buildoptions "/MD"
			optimize "On"

			
		filter "configurations:Dist"
			defines "WE_DIST"
			buildoptions "/MD"
			optimize "On"