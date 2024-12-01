# Rubik's cube solving machine
The machine solves the Rubik's cube by using the CFOP method, which method allows to solve any scrambled Rubik's cube with 60~100 moves. More information regarding the code in CFOP_algorithm/CFOP_readme.md\
\
The machine's structure is made of a Lego structure to hold the motors into place and 3D printed parts to attach the motors to the centre of the Rubik's cube. More information regarding the structure in CAD_design/CAD_readme.md\
\
The electronics of the machine consist of 6 stepper motors controlled with an Arduino Mega. More information regarding the electronics in Electronics/electronics_readme.md\
\
The code used for Arduino Mega is found in the Arduino_code folder. More information regarding the code in Arduino_code/arduino_readme.md\
\
The machine has two modes of use:
- The code gives prints a random scramble and the CFOP solution to such scramble to the terminal
- The user inputs all the colors of the already scrambles cube in a particular order, and the code prints the solution to the terminal\

To run the machine, the Arduino_code needs to be run on an Arduino Mega, while the F2L algorithm needs to be run from the advanced_method.cpp file.\
On the arduino IDE the serial monitor has to be openend to copy and paste the move solutions from the terminal to the serial monitor.\

Personal Info:
- email: nichiandetti@gmail.com


