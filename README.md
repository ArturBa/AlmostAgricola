# Almost Agricola
[![Build Status](https://travis-ci.com/ArturBa/AlmostAgricola.svg?token=5PNdM7qHNNqDFxDZsBRp&branch=develop)](https://travis-ci.com/ArturBa/AlmostAgricola)
[![codecov](https://codecov.io/gh/ArturBa/AlmostAgricola/branch/develop/graph/badge.svg?token=gVGDosqV6F)](https://codecov.io/gh/ArturBa/AlmostAgricola)

available on your Linux and PC

## What is this
This is a game based on Agricola 

## Table of Contents
1.  [What is this?](#what-is-this)
2.  [Project structure](#project-structure)
3.  [Project dependencies](#project-dependencies)
4.  [Project building](#project-building)
5.  [Game show](#game-show)
6.  [Documentation](#documentation)

## Project structure
-  [`docs/`](./docs) is where documentation is
-  [`ext/`](./ext) includes project dependencies
-  [`inlude/`](./include) is where the header files are located
-  [`src/`](./src) is where the source files are located
-  [`test/`](./test) is where the test source files are located


## Project dependencies
This project uses:
-  [`Google Test`](https://github.com/google/googletest) for testing purposes 
-  [`ImGui`](https://github.com/ocornut/imgui) + [`SFML`](https://www.sfml-dev.org/) for GUI
-  [`JSON for Modern C++`](https://github.com/nlohmann/json) for file dictionary

## Project building 
### Linux
In the project root:
```bash
mkdir build
cd build
cmake ..
make
```

#### Run executables
Then you can do ./executable for the generated executable:
```bash
./AlmostAgricola
```
    
### Windows
To run this project in Visual Studio replace file `CMakeSettings.json` with [`docs/CMakeSettings.json`](docs/CMakeSettings.json) in project main folder.
This file contains main configuration required by Visual Studio for running this project.

#### Run executables
At this moment I strongly recommend using Visual Studio for running this project

## Game show
### Main menu
![main menu](docs/screenshots/mainMenu.png)

## Documentation
### Doxygen
To create [Doxygen](http://doxygen.nl/) documentation run in project root:
```bash
doxygen Doxyfile
```
Then you will find [`index.html`](docs/html/index.html) file
`docs/html/index.html`

### UML
UML diagram available in:
[`docs/UML`](docs/UML/README.md)


