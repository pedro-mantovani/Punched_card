# Punched Card Simulator

> 🇺🇸 English | [🇧🇷 Versão em Português](#simulador-de-cartões-perfurados)

## Overview

This project simulates how a punched card works using slide switches to represent the lines (or holes) of the card. The selected pattern is interpreted and displayed on an LCD screen.

It was designed for educational purposes, allowing students to experience the high effort once required to program using punched cards, and to provide a more tangible model of how this process worked in early computing.

### Images

![Funcionamento no Tinkercad](/Imagens%20e%20vídeos/Exemplo_tinker.png)
---

## How It Works

Each switch is connected to a digital pin on the Arduino Nano. The "HIGH" position represents a hole in the punched card. The combination of holes is processed as a binary number by the Arduino, which then sends the corresponding symbol to the display, based on the IBM 029 model ([reference](https://www.masswerk.at/keypunch/)).

The code logic consists of multiple switch-case blocks grouped similarly to how manual keypunch machines were organized. Even though a single switch-case block could do the job, the structure was chosen to emulate how the first three rows worked like a "shift", changing the way the remaining rows were interpreted.

When the push button is pressed, the cursor moves forward, preserving the previous character and allowing up to 16 characters to be typed.

To clear the display, you need to press the Arduino's reset button. This restarts the program and helps keep the display logic clean, avoiding unexpected behavior from prolonged use.

### Other Features:
- For better visibility, the current character alternates with a solid block, indicating the cursor's position.
- The first row of the LCD shows a binary representation of the current switches configuration.

**Character Mapping:**

![gabarito](/Imagens%20e%20vídeos/gabarito.png)

---

## Components Used

| Quantity | Component         | Model            
|----------|-------------------|------------------
| 1        | LCD Display       | 16x2 HD44780     
| 1        | I2C Module        | PCF8574          
| 1        | Arduino Nano      | Atmega328 CH340  
| 1        | Push Button       | 6x6x5 mm         
| 12       | Slide Switches    | SS12D00G4        
| 1        | Header (M-F)      | 40 pins          
| 1        | Phenolic Board    | 10x10 cm         

---

# Usage / Assembly Instructions

You can test the circuit online using [Tinkercad](https://www.tinkercad.com/things/hIHtu1BwrTN-simulador-de-cartao-perfurado)

![Tinkercad Example](/Imagens%20e%20vídeos/Exemplo_tinker.png)

It works just like the physical prototype, although the circuit timing has been adjusted for better visualization in the simulator, since Tinkercad's execution speed differs from real time.

### Physical Assembly

It's recommended to test the project on a breadboard first.  
However, for consistent usage, a printed circuit board (PCB) is essential — the number of wires involved can lead to unreliable connections on a breadboard. Also, the switches are small and may detach easily when manipulated.

📹 [Video of the prototype](/Imagens%20e%20vídeos/protótipo.mp4)

For PCB assembly, you can:
- Use the provided [PDF](/Imagens%20e%20vídeos/trilhas.pdf) file for ready-to-print traces,
- Or customize the schematic and board files using EAGLE.

---

## Circuit

[Circuit file (BRD)](/Códigos%20e%20arquivos/simulador.brd)

![Imagem BRD](/Imagens%20e%20vídeos/Circuito.png)



## Schematic

![Imagem SCH](/Imagens%20e%20vídeos/Esquemático.png)

[Schematic file](/Códigos%20e%20arquivos/simulador.sch)

---

### 💡 Tips

- Remember to adjust the LCD contrast.
- You can customize the pin configuration.
- All the timing can be changed to suit your needs.

---

# Simulador de Cartões Perfurados

> 🇧🇷 Português | [🇺🇸 English Version](#punched-card-simulator)

## Visão Geral

Este projeto simula o funcionamento de um cartão perfurado usando interruptores para representar as linhas de um cartão. O padrão selecionado é interpretado e exibido em um display LCD.

Ele foi projetado para fins pedagógicos para que os estudantes possam experimentar o esforço hercúleo necessário para programar com cartões perfurados e tenham um modelo mais palpável de como esse processo funcionava.

### Imagens e vídeos
![Funcionamento no Tinkercad](/Imagens%20e%20vídeos/Exemplo_tinker.png)




## Como Funciona
Cada interruptor está ligado a um pino do Arduino Nano, a posição "ligado" representa um furo no cartão, a combinação de furos é processada como um número binário pelo Arduino, que envia para o display o símbolo correspondente conforme o padrão IBM 029 ([referência](https://www.masswerk.at/keypunch/)).

A lógica do código consiste em vários switch cases agrupados de maneira análoga ao agrupamento das perfuradoras manuais. O código também funcionaria com um switch case único, mas quis trazer para o código essa noção de que as três linhas iniciais funcionam como um "shift" que altera a forma como as linhas principais são interpretadas.

Quando o botão é pressionado o cursor é movido para frente preservando o caractere na posicão anterior e permitindo a escrita de até 16 caracteres.

Para limpar o display é necessário pressionar o botão de reset do Arduino, assim o programa é reiniciado, mantendo o código sempre "limpo", evitando bugs inesperados devido ao uso contínuo.

**Outras funcionalidades:**

Para melhor visibilidade o caractere atual se alterna com um bloco sólido indicando a posição do cursor;

A primeira linha mostra uma correspondência binária da posição atual dos interruptores.

Padrão utilizado:

![gabarito](/Imagens%20e%20vídeos/gabarito.png)


## Materiais utilizados
| Quantidade |  Componente  | Modelo |  Valor (Unidade)  |
|------------|--------------|--------|---------|
| 1 | Display LCD | 16x2 HD44780 | R$13,90 |
| 1 | Módulo I2C | PCF8574 | R$12,00 |
| 1 | Arduino Nano | Atmega328 Ch340 | R$34,90 |
| 1 | Push Button | 6x6x5mm | R$0,15 |
| 12 | Interruptor | SS12D00G4 | R$0,30 |
| 1 | Header macho-fêmea | 40 pinos | R$4,00 |
| 1 | Placa fenolite | 10x10cm | R$8,45 |
|**Total**|||**R$77,00**|



# Instruções de uso / Construção
É possível testar o cicuito via internet pelo [Tinkercad](https://www.tinkercad.com/things/hIHtu1BwrTN-simulador-de-cartao-perfurado)

![Funcionamento no Tinkercad](/Imagens%20e%20vídeos/Exemplo_tinker.png)

Funciona exatamente como o protótipo, porém o timing do circuito está alterado para melhor visualização no programa visto que o tempo do simulador não corresponde à realidade.   
  
Para construção física, é recomendado testar antes em uma protoboard, mas para uso é indispensável o circuito impresso pois a quantidade de fios é enorme, o que faz com que o circuito tenha muito mal contato, fora que os interruptores são muito pequenos sendo mais fácil tirá-los da protoboard que mudar suas posições.

[Vídeo do projeto na protoboard](/Imagens%20e%20vídeos/protótipo.mp4)

Para a construção em circuito impresso é possível utilizar o [PDF](/Imagens%20e%20vídeos/trilhas.pdf) pronto das trilhas ou fazer alterações no arquivo esquemático e/ou no circuito usando o EAGLE.

## Circuito

[Arquivo do circuito](/Códigos%20e%20arquivos/simulador.brd)

![Imagem BRD](/Imagens%20e%20vídeos/Circuito.png)


## Esquemático

![Imagem SCH](/Imagens%20e%20vídeos/Esquemático.png)

[Arquivo do esquemático](/Códigos%20e%20arquivos/simulador.sch)


### 💡 Dicas

- Lembre-se de ajustar o contraste do display (caso contrário, o backlight acenderá, mas nenhuma letra será exibida).
- A leitura do botão, o tempo de piscar do cursor e a pinagem podem ser facilmente alterados dentro da função `void setup()`.
