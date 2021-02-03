 workspace "FlyHigh"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 project "FlyHigh"
	location "FlyHigh"
	kind "SharedLib"
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
		"%{prj.name}/third party/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FH_PLATFORM_WINDOWS",
			"FH_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Projects")
		}

	filter "configurations:Debug"
		defines "FH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FH_DIST"
		optimize "On"

project "Projects"
	location "Projects"
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
		"FlyHigh/third party/spdlog/include",
		"FlyHigh/src"
	}

	links
	{
		"FlyHigh"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FH_DIST"
		optimize "On"