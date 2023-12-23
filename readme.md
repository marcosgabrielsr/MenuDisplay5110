**Autor**: Marcos Gabriel <br>
**Data da última atualização**: 23/12/2023 

## Descrição:
Este projeto é uma forma de criar menus rápidos e iterativos com arduino e o display LCD Nokia 5110 48x84. As funcionalidades encontradas aqui, buscam permitir criar a parte visual do menu e também as funcionalidades executadas de acordo com cada opção selecionada.

![*Exemplo do sistema em funcionamento*](images/example.gif)

**OBS:** A IDE utilizada para desenvolver este projeto é o PlatformIO utilizando o framework Arduino, logo é possível utilizar este código na IDE oficial do Arduino.

## Circuito Eletrônico:
<img src="https://cdn.discordapp.com/attachments/1153711382336909332/1163203943237689404/image.png?ex=653eb917&is=652c4417&hm=aafb61461d30b2c1abee0a6c10e71c59c9cdcf73e34c3c1c1630b3395ad9d880&" />

## Funcionalidades:
1. Função `menu_title`:
    Objetivo: Desenha o título do menu no display.
    Parâmetros:
    Adafruit_PCD8544 &display: Referência para o objeto que controla o display.
    char* title: Ponteiro para uma string que contém o título do menu.
    Funcionamento: Desenha um retângulo na parte superior do display e imprime o título dentro desse retângulo.

2. Função `navegation`:
    Objetivo: Controla a navegação pelo menu.
    Parâmetros:
    PushButton &buttonL: Referência para o botão de navegação para a esquerda.
    PushButton &buttonR: Referência para o botão de navegação para a direita.
    const int8_t size: Número total de opções no menu.
    Funcionamento: Mantém o controle da posição do cursor no menu, permitindo a navegação para a esquerda ou direita. Retorna o índice da opção selecionada.

3. Função `menu_show`:
    **Objetivo**: Exibe o menu no display, permitindo a navegação e a seleção de opções.

    **Parâmetros**:
    Adafruit_PCD8544 &display: Referência para o objeto que controla o display.
    char* title: Ponteiro para uma string que contém o título do menu.
    PushButton &buttonL: Referência para o botão de navegação para a esquerda.
    PushButton &buttonX: Referência para o botão de seleção.
    PushButton &buttonR: Referência para o botão de navegação para a direita.
    const char options[][MAX_TITLE]: Matriz de strings contendo as opções do menu.
    const int size: Número total de opções no menu.
    bool (*func)(int, PushButton &): Ponteiro para uma função que aceita a opção selecionada e o botão de seleção como parâmetros e retorna um valor booleano indicando se o menu deve continuar sendo exibido.

    **Funcionamento**: Utiliza um loop infinito para atualizar continuamente o display com as opções disponíveis, permitindo a navegação do usuário. A função passada como parâmetro (func) é chamada para determinar se o menu deve continuar sendo exibido. A navegação é controlada pelos botões, e a opção selecionada é destacada no display.

## Actions:
No arquivo main.cpp é encontrada a função actions que é passada como parâmetro para a função `menu_show`, note que ela possui os comandos `switch e case` e executa um bloco de comando de acordo com a posição do cursor. Dessa forma, podemos criar diferentes blocos com várias opções, sem ter de se preocupar em muudar o código principal da função que trata de imprimir o menu na tela (`menu_show`).
