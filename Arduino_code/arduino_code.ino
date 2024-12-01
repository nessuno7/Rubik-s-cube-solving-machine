#define stepPinY 42
#define dirPinY 43
#define dirPinW 44
#define stepPinW 45
#define dirPinO 46
#define stepPinO 47
#define dirPinG 50
#define stepPinG 51
#define dirPinB 48
#define stepPinB 49
#define dirPinR 52
#define stepPinR 53


int dirPin = 0;
int stepPin = 0;
int minDelay = 1000;
const int rotationSpeedDelay = 1000;

int acceleration_delay(int i){
  int return_ = 1250 - i*10;

  return return_;
}

void F_(){ //red
  dirPin = dirPinR;
  stepPin = stepPinR;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void f_(){ //red
  dirPin = dirPinR;
  stepPin = stepPinR;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void F2(){
  dirPin = dirPinR;
  stepPin = stepPinR;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<100; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotationSpeedDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotationSpeedDelay);
  }
}

void L_(){ //green
  dirPin = dirPinG;
  stepPin = stepPinG;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void l_(){ //green
  dirPin = dirPinG;
  stepPin = stepPinG;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void L2(){
  dirPin = dirPinG;
  stepPin = stepPinG;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<100; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotationSpeedDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotationSpeedDelay);
  }
}

void R_(){ //blue
  dirPin = dirPinB;
  stepPin = stepPinB;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void r_(){ //blue
  dirPin = dirPinB;
  stepPin = stepPinB;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void R2(){
  dirPin = dirPinB;
  stepPin = stepPinB;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<100; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotationSpeedDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotationSpeedDelay);
  }
}

void B_(){ //orange
  dirPin = dirPinO;
  stepPin = stepPinO;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void b_(){ //orange
  dirPin = dirPinO;
  stepPin = stepPinO;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void B2(){
  dirPin = dirPinO;
  stepPin = stepPinO;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<100; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotationSpeedDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotationSpeedDelay);
  }
}

void U_(){ //yellow
  dirPin = dirPinY;
  stepPin = stepPinY;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void u_(){ //yellow
  dirPin = dirPinY;
  stepPin = stepPinY;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void U2(){
  dirPin = dirPinY;
  stepPin = stepPinY;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<100; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotationSpeedDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotationSpeedDelay);
  }
}

void D_(){ //white
  dirPin = dirPinW;
  stepPin = stepPinW;
  digitalWrite(dirPin, HIGH);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void d_(){ //white
  dirPin = dirPinW;
  stepPin = stepPinW;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<50; i++){
    int delay = acceleration_delay(i);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}

void D2(){
  dirPin = dirPinW;
  stepPin = stepPinW;
  digitalWrite(dirPin, LOW);

  for(int i = 0; i<100; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotationSpeedDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotationSpeedDelay);
  }
}

void setup() {
  pinMode(stepPinR, OUTPUT);
  pinMode(dirPinR, OUTPUT);
  pinMode(stepPinB, OUTPUT);
  pinMode(dirPinB, OUTPUT);
  pinMode(stepPinG, OUTPUT);
  pinMode(dirPinG, OUTPUT);
  pinMode(stepPinO, OUTPUT);
  pinMode(dirPinO, OUTPUT);
  pinMode(stepPinW, OUTPUT);
  pinMode(dirPinW, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);

  Serial.begin(9600);
}


bool is_opposite(String move1, String move2){
  if((move1 == "R" || move1 == "r" || move1 == "2R") && (move2 == "L" || move2 == "l" || move2 == "2L")){
    return true;
  }
  if((move1 == "L" || move1 == "l" || move1 == "2L") && (move2 == "R" || move2 == "r" || move2 == "2R")){
    return true;
  }
  if((move1 == "B" || move1 == "b" || move1 == "2B") && (move2 == "F" || move2 == "f" || move2 == "2F")){
    return true;
  }
  if((move1 == "F" || move1 == "f" || move1 == "2F") && (move2 == "B" || move2 == "b" || move2 == "2B")){
    return true;
  }
  if((move1 == "U" || move1 == "u" || move1 == "2U") && (move2 == "D" || move2 == "d" || move2 == "2D")){
    return true;
  }
  if((move1 == "D" || move1 == "d" || move1 == "2D") && (move2 == "U" || move2 == "u" || move2 == "2U")){
    return true;
  }

  return false;
}

void execute_move(String move){
  if(move == "R"){
    R_();
  }
  else if(move == "r"){
    r_();
  }
  else if(move == "2R"){
    R2();
  }
  else if(move == "L"){
    L_();
  }
  else if(move == "l"){
    l_();
  }
  else if(move == "2L"){
    L2();
  }
  else if(move == "F"){
    F_();
  }
  else if(move == "f"){
    f_();
  }
  else if(move == "2F"){
    F2();
  }
  else if(move == "B"){
    B_();
  }
  else if(move == "b"){
    b_();
  }
  else if(move == "2B"){
    B2();
  }
  else if(move == "U"){
    U_();
  }
  else if(move == "u"){
    u_();
  }
  else if(move == "2U"){
    U2();
  }
  else if(move == "D"){
    D_();
  }
  else if(move == "d"){
    d_();
  }
  else if(move == "2D"){
    D2();
  }
  else{
    Serial.println("Error: move not recognised");
  }
}

void execute_moves(String moves[], int numberMoves){
  for(int i=0; i<numberMoves; i++){
    if(moves[i] != " "){
      execute_move(moves[i]);
      Serial.println(moves[i]);

      if(is_opposite(moves[i], moves[i+1])){
        delay(0);
      }
      else{
        delay(100);
      }
    }
  }
}

void loop() {
  while (Serial.available() == 0) {}
  String moves = Serial.readString();
  moves.trim();


  int dimension = moves.length(); 
  String moves_to_do[dimension];
  for(int i = 0; i < dimension; i++){
    moves_to_do[i] = " ";
  }

  int index = 0;

  for (int i = 0; i < moves.length(); i++){
    char appo = moves.charAt(i);
    bool previous_is_2;

    if(appo != " "){
      if(appo == '2'){
        previous_is_2 = true;
      }
      else{
        switch(appo){
          case 'R':
            if(previous_is_2 == true){
              moves_to_do[index] = "2R";
            }
            else{
              moves_to_do[index] = "R";
            }
            break;

          case'r':
            moves_to_do[index] = "r";
            break;

          case 'L':
            if(previous_is_2 == true){
              moves_to_do[index] = "2L";
            }
            else{
              moves_to_do[index] = "L";
            }
            break;

          case 'l':
            moves_to_do[index] = "l";
            break;

          case 'F':
            if(previous_is_2 == true){
              moves_to_do[index] = "2F";
            }
            else{
              moves_to_do[index] = "F";
            }
            break;

          case 'f':
            moves_to_do[index] = "f";
            break;          
          
          case 'B':
            if(previous_is_2 == true){
              moves_to_do[index] = "2B";
            }
            else{
              moves_to_do[index] = "B";
            }
            break;          
          
          case 'b':
            moves_to_do[index] = "b";
            break;          
          
          case 'U':
            if(previous_is_2 == true){
              moves_to_do[index] = "2U";
            }
            else{
              moves_to_do[index] = "U";
            }
            break;          
          
          case 'u':
            moves_to_do[index] = "u";
            break;          
          
          case 'D':
            if(previous_is_2 == true){
              moves_to_do[index] = "2D";
            }
            else{
              moves_to_do[index] = "D";
            }
            break;          
          
          case 'd':
            moves_to_do[index] = "d";
            break;
        }
        index++;
        previous_is_2 = false;
      }
    }
  }

  for(int i =0; i<dimension; i++){
    Serial.print(moves_to_do[i]);
    Serial.print(" ");
  }

  execute_moves(moves_to_do, dimension);

}