# Simulador de Semáforo com Raspberry Pi Pico W - Temporizador Periódico 

Este projeto simula um semáforo de trânsito usando um Raspberry Pi Pico W e três LEDs (vermelho, amarelo e verde). Os LEDs acendem em uma sequência repetida (vermelho, amarelo, verde) para simular o comportamento de um semáforo real. Cada estado do semáforo (LED aceso) dura 3 segundos.

## Funcionalidades

*   Sequência de LEDs Vermelho, Amarelo e Verde.
*   Temporização de 3 segundos por LED.
*   Mensagens de status impressas no console serial (indicando a cor do semáforo atual).
*   Utilização da biblioteca `hardware/timer` para temporização precisa.
*   Utilização da biblioteca `pico/stdlib` para funções padrão do Pico.

## Hardware

| Componente       | GPIO no Pico |
| ---------------- | ------------- |
| LED Vermelho     | 13            |
| LED Amarelo      | 12            |
| LED Verde        | 11            |
| Resistor (x3)    | 300 ohms      |

## Instalação

1. **Hardware:**
    *   Raspberry Pi Pico W
    *   3 LEDs (um vermelho, um amarelo, um verde)
    *   3 resistores de 300 ohms

2. **Execução**
   *  Assim que executado, o programa inicia sem necessidade de ação externa.
  
3. Link do experimento com led RGB na placa BitDogLab: https://youtube.com/shorts/Xx2vxSQm5MI?feature=share
