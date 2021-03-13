# Sortilyzer
<p align="center">
  <img src="./Sortilyzer/assets/log-trans.png"></img>
</p>

Sortilyzer is a sorting algorithm visualizer, under MIT License. Sortilyzer codebase is written in C++17 using Visual Studio 2019. Using external dependencies as
- GLFW
- GLEW
- SFML
- ImGui-SFML
- Dear-ImGui

Currently sortilyzer is able to visualizer only few standard comparision based sorting algorithms.
- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort

Sortilyzer is not using any build system for now like CMake, PreMake, Bazel etc. Therefore if you wish to run it on OS other than Windows, you have to set up things from scratch.

## Setup Guide
#### Windows
In order to build and run sortilyzer locally on your system you need
- Microsoft Visual C++ Compiler
- GLFW
- GLEW
- SFML
- Dear-ImGui
- ImGui-SFML

Once you have all these dependencies, clone the repository and set the include path, Linker dependencies in project properties in Microsoft Visual Studio.

Sortilyzer is using static library linking so make sure you also set the static SFML flag and GLEW static flag in `properties > C/C++ > Preprocessor > Preprocessor Definitions`
- For GLEW set `GLEW_STATIC`
- For SFML set `SFML_STATIC`

After setting all these you will successfully be able to build Sortilyzer on your local machine.

Provided here a basic overview for how to setup on local system, In case of any problem feel free to open issue regarding.

#### Linux
Update it later on, once i plan to configure a build system.
In case if you wish feel free to raise a PR for this.

## Test Drive
- [Download x86 Debug mode executable](./Debug-x86/Sortilyzer.exe)
- [Dowload x86 Release mode executable](./Release-x86/Sortilyzer.exe)

## Preview
<img src="./Preview/1.jpg">
<br/>
<img src="./Preview/2.jpg">

## Contribution
All PR are welcome.