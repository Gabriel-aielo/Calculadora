//Programa: Display LCD 16x2
//Autor: MakerHero
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

#define FLOW_SENSOR_PIN 2
#define pinButton 10


int counter = 0;


volatile int pulseCount = 0;
float flowRate = 0.0;
unsigned long prevTime = 0;
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 8);
 
void setup()
{
 
  //pino botão para navegação do menu
  pinMode(pinButton, INPUT_PULLUP);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(FLOW_SENSOR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), countPulse, RISING);
 }
 
void loop()
{
  //resistencia potenciometro de regulação para o display
  

  //Navegação menu display
  int armazenaEstadoButton = digitalRead(pinButton);
  
  if(armazenaEstadoButton == 1){
    Serial.println("Botão solto");

  }else if(armazenaEstadoButton == 0){
    Serial.println("Botão Pressionado");
    counter++;
    delay(500);

    if(counter > 3){
      counter = 0;
    }

  }
  Serial.println(counter);

  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - prevTime;
  
  if (elapsedTime >= 1000) {
    // A cada segundo, calcular o fluxo com base no número de pulsos recebidos
    noInterrupts();
    flowRate = pulseCount / 7.5; // 7.5 pulsos por litro no sensor YF-S201
    pulseCount = 0;
    interrupts();
    
prevTime = currentTime;
}

if(counter == 0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pressione para");
  lcd.setCursor(0,1);
  lcd.print("Entrar no menu");
  }

  if(counter == 1){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(flowRate);

  lcd.setCursor(0, 0);
  lcd.print("Fluxo L/Min:");

}

  if(counter == 2){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(flowRate*60);

  lcd.setCursor(0, 0);
  lcd.print("Fluxo L/Hora:");
  }

  if(counter == 3){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Menu 3");
  }
    
  }


void countPulse() {
  // Incrementar o contador de pulsos
  pulseCount++;
}