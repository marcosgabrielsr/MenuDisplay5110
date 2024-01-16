//Arquivo principal
#include "config.h"

//-- Mapeando Hardware:
//- Pinos do display:
#define pinCLK 3
#define pinDIN 4
#define pinDC 5
#define pinCE 6
#define pinRST 7
#define led 2

//- Pinos dos botões
#define pinButtonL 10
#define pinButtonX 9
#define pinButtonR 8

//-- Declarando funções:
//- Função responsável por executar comandos no menu
bool actions(int cursor, PushButton &btnX);

//-- Criando objetos
//- Display Nokia 5110:
Adafruit_PCD8544 display = Adafruit_PCD8544(pinCLK, pinDIN, pinDC, pinCE, pinRST);

//- PushButtons:
PushButton buttonL(pinButtonL, 170);
PushButton buttonX(pinButtonX, 170);
PushButton buttonR(pinButtonR, 170);

//Criando uma matriz de opções
const char options[][MAX_TITLE] = {"Opcao 1", "Opcao 2", "Opcao 3", "Opcao 4", "Opcao 5", "Sair"};

//- Função Setup
void setup(){
  //Inicializando comunicação Serial
  Serial.begin(9600);

  //Inicializando Display e setando o contraste do mesmo
  display.begin();
  display.setContrast(57);
  display.clearDisplay();
  display.display();

  //Definindo o pino led como saída e definindo ele como LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}// end Setup

//- Função Loop
void loop(){
  //Limpando o display
  display.clearDisplay();

  //Chamando função que desenha no menu do display
  menuShow(display, "Menu Teste", buttonL, buttonX, buttonR, options, 6, actions);

  //Atualizando o display
  display.display();
}// end Loop

//- Função responsável por executar comandos no menu
bool actions(int cursor, PushButton &btnX){
  bool value = true;

  //Verifica se o buttonX foi clicado
  if(btnX.clickButton()){
    //Executa uma opção de acordo com a posição do cursor
    switch (cursor){
      case 0:
        Serial.println("Opcao 1");
      break;

      case 1:
        Serial.println("Opcao 2");
      break;

      case 2:
        Serial.println("Opcao 3");
      break;

      case 3:
        Serial.println("Opcao 4");
      break;

      case 4:
        Serial.println("Opcao 5");
      break;

      //Considera sempre a última linha da matriz(última opção do menu) como a opção de sair
      case 5:
        Serial.println("Sair");
        value = false;
      break;

      default:
        Serial.println("Opcao nao faz nada!");
      break;
    }
  }

  return value;
}