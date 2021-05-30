# Sortilyzer

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/f0641ec098fe4c33878783fcd70aca65)](https://app.codacy.com/gh/ayaankhan98/Sortilyzer?utm_source=github.com&utm_medium=referral&utm_content=ayaankhan98/Sortilyzer&utm_campaign=Badge_Grade_Settings)

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
- Install SFML, glfw, GLUT, GL, GLU, GLEW
- run `./premake gmake`
- run `make`

Check `bin` folder for executable file to run the app

## Test Drive
- [Download x86 Debug mode executable](https://github.com/ayaankhan98/Sortilyzer/releases/download/1.0.0/Sortilyzer-x86-debug.exe)
- [Dowload x86 Release mode executable](https://github.com/ayaankhan98/Sortilyzer/releases/download/1.0.0/Sortilyzer-x86-Release.exe)

## Preview
<img src="https://github.com/ayaankhan98/Sortilyzer/blob/master/Preview/1.JPG">
<br/>
<img src="https://github.com/ayaankhan98/Sortilyzer/blob/master/Preview/2.JPG">


## Contribution

All PR are welcome.
