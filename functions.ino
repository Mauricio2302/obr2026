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
}

void followLine(){
  //função para aplicar ou reduzir velocidade nos motores para seguir linha

  readLine();

  P = Kp * error;            
  P = constrain(P, -90, 90); // limita correção para não fazer curva muito fechada

  int baseSpeed = 140;

  int leftSpeed  = baseSpeed - P;
  int rightSpeed = baseSpeed + P;

  leftSpeed  = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  analogWrite(IN1, leftSpeed);
  analogWrite(IN2, 0);
  analogWrite(IN3, rightSpeed);
  analogWrite(IN4, 0);
}

bool isGreen(ColorSensor &s) {
  //função para retornar se a cor lida pelo sensor é verde
  int color = s.getColor();
  if (color == 3) { 
    return true;
  }
  return false;
}

bool hasGreen(){
  //função para ver se tem verde em qualquer um dos sensores
  if(sensor.getColor() == 3 || sensor2.getColor() == 3 || sensor3.getColor() == 3 || sensor4.getColor() == 3 ){
    return true;
  }
  else{
    return false;
  }
}

bool greenLeft(){
  //função para ver se tem verde em qualquer um dos sensores da esquerda
  if(sensor3.getColor() == 3 || sensor4.getColor() == 3 ){
    return true;
  }
  else{
    return false;
  }
}

bool greenRight(){
  //função para ver se tem verde em qualquer um dos sensores da direita
  if(sensor.getColor() == 3 || sensor2.getColor() == 3 ){
    return true;
  }
  else{
    return false;
  }
}