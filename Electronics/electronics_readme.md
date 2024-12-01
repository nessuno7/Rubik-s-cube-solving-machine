# Electronics
The Rubik’s cube solving machine consist of 6 stepper motors controlled through the A4988 stepper motor driver and the Arduino Mega 2560 R3 board. The schematics of the circuits are shown in the Schematic_rubik-cube-machine.pdf file.\
\
Stepper motors were used as they provided very precise 90° and 180° turns. The model used is the NEMA 17 with 59 Ncm torque.\
\
Each driver needs two separate power supplies: 5V operating voltage with low current and 12V 2A max current for the motor. The VDD of the 6 drivers was connected in parallel with the Arduino 5V output. The VMOT of the 6 drivers was connected in parallel by an external power supply of 12V 10A (max). A capacitor (16V 100 uF) wired in parallel to each driver was also used to prevent voltage spikes to damage the driver and the motor. NEMA 17 59 Ncm has a max operating current of 2A, so the max current was adjusted to 1.8~1.5 A with the potentiometer screw.\
\
By using the A4988 stepper motor driver only two digital pins are needed to control each motor (one step pin and and one direction pin), meaning that only 12 digital pins are needed in total to control the whole machine. This makes it possible to operate the machine also with other small processors, such as the Arduino Uno.\
\
No PCB was used due to the cost of producing and shipping, the wiring is still on a breadboard. 
