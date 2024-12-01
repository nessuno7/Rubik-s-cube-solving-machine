# Arduino Code 
This code is used to control the Arduino Mega and reads a string of moves from the serial monitor and executes those moves.\
\
The move functions use a for() cycle to control the stepper motors into doing 50 steps for a 90° rotation or 100 steps for a 180° rotation. By setting the direction pin as high or low, the motor will rotate clockwise or anticlockwise.\
\
The delay between one step and the other is given by the acceleration_delay() function. This function allows the speed of the motor to be slower at the beginning of the rotation and then accelerate.\
\
The code also adds a delay between one move and the other of 100 milliseconds to avoid jamming. The delay is 0 only when the two moves are opposite each other.
