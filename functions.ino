void forward(int speed){
  //função pro robô andar pra frente
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}

void backward(int speed){
  //função pro robô andar para trás
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}
void right(int speed){
  //função pro robô andar para trás
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}
void left(int speed){
  //função pro robô andar para trás
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}

void readColors(){
  //função para atualizar a leitura dos sensores de cor
  sensor.getColor();
  sensor2.getColor();
  sensor3.getColor();
  sensor4.getColor();
  //direita = 1 direitaMeio = 2 esquerdaMeio = 3 esquerda = 4
}

void readLine(){
  //função para calcular o quão longe o robô está da linha
  readColors();
  colorR  = sensor.getColor();
  colorRM = sensor2.getColor();
  colorLM = sensor3.getColor();
  colorL  = sensor4.getColor();
  int s1 = 0;
  int s2 = 0;
  int s3 = 0;
  int s4 = 0;
  // apenas PRETO (1) conta como linha
  if(colorR == 1)  s1 = 1;
  if(colorRM == 1) s2 = 1;
  if(colorLM == 1) s3 = 1;
  if(colorL == 1)  s4 = 1;
  int soma = s1 + s2 + s3 + s4;  
  // soma = quantos sensores estão vendo preto
  if(soma == 0){
    error = 0;  // nenhum sensor viu a linha
    return;
  }
  // cada sensor tem um "peso" de posição:
  // direita = +3
  // direita meio = +1
  // esquerda meio = -1
  // esquerda = -3
  // a fórmula calcula a posição média da linha
  error = (s1*3 + s2*1 + s3*(-1) + s4*(-3)) / (float)soma;
  /*if(s1 == 1 && s2 == 1){
    forward(100);
    delay(200);
    right(120);
    delay(300);
    while(sensor3.getColor() != 1){
      readColors();
      right(120);
    }
    /*left(100);
    delay(300);
  }
  if(s3 == 1 && s4 == 1){
    forward(100);
    delay(200);
    left(120);
    delay(300);
    while(sensor2.getColor() != 1){
      readColors();
      left(120);
    }
    /*right(100);
    delay(300);
  }*/
}

void followLine(){

  /*if(hasGreen()){

    // decide lado antes de andar
    bool leftSide  = greenLeft();
    bool rightSide = greenRight();

    forward(100);
    delay(150);

    if(leftSide){
      left(150);
      delay(600);

      while(sensor2.getColor() != 1){
        left(120);
      }
    }
    else if(rightSide){
      right(150);
      delay(600);

      while(sensor3.getColor() != 1){
        right(120);
      }
    }

    return; // sai da função depois de resolver verde
  }*/

  // se não tem verde, segue linha normal
  readLine();

  P = Kp * error;            
  P = constrain(P, -150, 150);

  int baseSpeed = 100;

  int leftSpeed  = baseSpeed - P;
  int rightSpeed = baseSpeed + P;

  leftSpeed  = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  analogWrite(IN1, leftSpeed);
  analogWrite(IN2, 0);
  analogWrite(IN3, rightSpeed);
  analogWrite(IN4, 0);
}

bool isGreen(ColorSensor &s, float margem){
  s.getRGB();

  int r = s.R_raw;
  int g = s.G_raw;
  int b = s.B_raw;

  if(margem == 3){
    if((g > 40 && g < 65) && (r > 35 && r < 65) && (b > 35 && b < 70)){
      return true;
    }else{
      return false;
    }
  }
  else if(g > r * margem && g > b * margem){
    return true;
  }

  return false;
}

bool hasGreen(){
  // verifica verde em qualquer sensor
  if(
    isGreen(sensor, 1.4)  ||
    isGreen(sensor2, 1.4) ||
    isGreen(sensor3, 3)   ||
    isGreen(sensor4, 1.85)
 ){
    return true;
  }

  return false;
}

bool greenLeft(){
  // verifica verde no lado esquerdo
  if(
    isGreen(sensor3, 3)   ||
    isGreen(sensor4, 1.85)
  ){
    return true;
  }

  return false;
}

bool greenRight(){
  // verifica verde no lado direito
  if(
    isGreen(sensor, 1.4)  ||
    isGreen(sensor2, 1.4)
  ){
    return true;
  }

  return false;
}
