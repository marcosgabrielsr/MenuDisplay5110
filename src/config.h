//Incluindo biblioteca para trabalhar com Arduino
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "PushButton.hpp"

//Definindo constantes
#define MAX_TITLE 20

//-- Funções:
//- Função que desenha no display as opções e a opção selecionada pelo usuário
void menuShow(Adafruit_PCD8544 &display, char* title, PushButton &buttonL, PushButton &buttonX, PushButton &buttonR, const char options[][MAX_TITLE], const int size, bool (*func)(int, PushButton &));