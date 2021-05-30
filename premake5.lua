workspace "Sortilyzer"
  architecture "x64"

  configurations {
    "Debug",
    "Release"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLEW"] = "Sortilyzer/src/Dependencies/GLEW/include"
IncludeDir["GLFW"] = "Sortilyzer/src/Dependencies/GLFW/include"
IncludeDir["imgui"] = "Sortilyzer/src/Dependencies/imgui"
IncludeDir["imgui-sfml"] = "Sortilyzer/src/Dependencies/imgui-sfml"
IncludeDir["SFML"] = "Sortilyzer/src/Dependencies/SFML/include"

LinkDirs = {}
LinkDirs["SFML"] = "Sortilyzer/src/Dependencies/SFML/lib"

project "Sortilyzer"
  kind "consoleApp"
  language "C++"
  cppdialect "C++17"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.cpp",
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.h",
  }

  includedirs {
    "%{prj.name}/src",
    "%{prj.name}/src//Dependencies/imgui",
    "%{prj.name}/src/Dependencies/imgui-sfml",
    "%{prj.name}/src//Dependencies/GLEW/include",
    "%{prj.name}/src//Dependencies/GLFW/include/"
  }

  filter "system:linux"
    links {
      "sfml-graphics",
      "sfml-window",
      "sfml-system",
      "sfml-network",
      "sfml-audio",
      "GL",
      "GLU",
      "glut",
      "GLEW",
      "OpenGL",
      "glfw",
    }
  
  filter "system:windows"
    links {
      "sfml-graphics",
      "sfml-window",
      "sfml-system",
      "sfml-network",
      "sfml-audio",
      "opengl32"
    }

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { " NDEBUG" }
    optimize "On"
