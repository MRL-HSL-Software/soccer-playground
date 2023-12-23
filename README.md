# Soccer Playground

Base of other experimental and tools tasks

#### Table of Contents
- [Soccer Playground](#soccer-playground)
      - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Dependencies](#dependencies)
  - [Build and Run](#build-and-run)
- [Clone the repository](#clone-the-repository)
- [Build the project](#build-the-project)
- [Run the executable](#run-the-executable)

## Introduction
This Soccer Playground is a graphically designed environment created using OpenCV in C++ specifically tailored for kid-sized robots participating in RoboCup competitions. RoboCup is an international initiative aiming to advance the field of robotics and artificial intelligence through soccer-playing robots.
## Dependencies

- **C++ Compiler**: C++11 or later
- **OpenCV**: [Link to OpenCV](https://www.opencv.org)
- **XLib**: [Link to XLib](https://www.x.org)

## Build and Run

This project can be compiled as standalone project but if you want to compile it under MRL HSL License, You must use MRL HSL CMake like :
```bash
# - Clone the Repository
git clone https://github.com/MRL-HSL-Software/soccer-playground.git
cd soccer-playground/
# - Also Clone MRL HSL CMake Project
git clone https://github.com/MRL-HSL-Software/MRL-HSL-CMake.git
cd MRL-HSL-CMake/
# - Build Project Project Using This Command :
./setup.sh
# - To Run Output Go to build Directory and Then Enter This Command :
./SoccerField
```

## Contributors
Thanks to these new members of MRL HSL Software Team :
- [Mobina Abforoosh](https://github.com/MobinaAbf) - Playground Dimensions and Conversions
- [Amir Yusefian](https://github.com/AmirUsefian) - Shape Structures
- [Erfan Zarabadi](https://github.com/ErfanDE10) - Configuratons
- [Parsa Karbasi](https://github.com/ChefParsa) - Shape Structures
- [Alireza Mortezaei](https://github.com/AMCode-80) - Functional Scalable Drawing
- [Ramtin Kosari](https://github.com/RamtinKosari) - Merge All Works Above