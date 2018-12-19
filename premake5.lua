workspace "DJ"
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
IncludeDir["GLFW"] = "DJ/vendor/GLFW/include"

include "DJ/vendor/GLFW"
	
project "DJ"
	location "DJ"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "djpch.h"
	pchsource "DJ/src/djpch.cpp"	
		
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog_module/include",
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
		systemversion "10.0.17134.0"
		
	defines
	{
		"DJ_PLATFORM_WINDOWS",
		"DJ_BUILD_DLL",
		"_WINDLL"
	}
	
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}
	
	filter "configurations:Debug"
		defines "DJ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "DJ_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "DJ_DIST"
		optimize "On"	
	
	--filter { "system:windows" , "configurations:Release" }
	--	buildoptions "/MT"
		

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
		"DJ/vendor/spdlog_module/include",
		"DJ/src"
	}
	
	links
	{
		"DJ"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"
		
	defines
	{
		"DJ_PLATFORM_WINDOWS",
	}
	
	filter "configurations:Debug"
		defines "DJ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "DJ_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "DJ_DIST"
		optimize "On"	
	
	
	
	
	
	