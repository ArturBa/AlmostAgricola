[![Build Status](https://travis-ci.com/ArturBa/AlmostAgricola.svg?token=5PNdM7qHNNqDFxDZsBRp&branch=develop)](https://travis-ci.com/ArturBa/AlmostAgricola)
[![codecov](https://codecov.io/gh/ArturBa/AlmostAgricola/branch/develop/graph/badge.svg?token=gVGDosqV6F)](https://codecov.io/gh/ArturBa/AlmostAgricola)



# Almost Agricola
now available on your Linux 

# What is this?
This is a game based on Agricola 

# Table of Contents
1. [What is this?](#what-is-this)
2. [Project structure](#project-structure)
3. [Project building](#project-building)

# Project structure
- `docs/` is where documentation is
- `build/` is where code is built - like where executables are.  
- `ext/` includes gtest
- `inlude/` is where the header files are located
- `src/` is where the source files are located
- `test/` is where the test source files are located

Rest of code in root:  
-`CMakeLists.txt` must be in each subdirectory of the project  


# Project building 
## Linux
In the project root:

    mkdir build
    cd build
    cmake ..
    make

### Run executables
Then you can do ./executable for the generated executable:

    ./AlmostAgricola
