# 🚗 Simulador de Seta de Carro com Arduino

Projeto que simula o funcionamento das setas (piscas) de um carro, usando um potenciômetro para representar o giro do volante e um botão para ativar o pisca-alerta.

🔗 **Simulação interativa no Tinkercad:** [Ver circuito e rodar simulação](https://www.tinkercad.com/things/gTLtL7y7Duy-setacarro?sharecode=njsWMAI4VfQNp1IrYL9Mq9Y8bNaDRYjI20dU04oOM_0)

## 📋 Descrição

Ao girar o potenciômetro totalmente para a direita, o LED direito pisca (simulando a seta direita ligada). Ao girar totalmente para a esquerda, o LED esquerdo pisca. Um botão adicional permite ligar o **pisca-alerta**: um toque rápido ativa o piscar simultâneo dos dois LEDs, e outro toque desativa.

## 🔧 Componentes utilizados

- 1x Arduino Leonardo
- 1x Protoboard
- 1x Potenciômetro
- 1x Botão (push-button)
- 2x LEDs
- 2x Resistores (220Ω ou 330Ω, para os LEDs)
- Jumpers

## 🔌 Esquema de ligação

**Potenciômetro:**
| Pino do potenciômetro | Conexão |
|---|---|
| Extremidade 1 | GND |
| Meio (wiper) | A0 |
| Extremidade 2 | 5V |

**LED direito:**
| Perna | Conexão |
|---|---|
| Anodo (+) | Resistor → Pino digital 9 |
| Catodo (-) | GND |

**LED esquerdo:**
| Perna | Conexão |
|---|---|
| Anodo (+) | Resistor → Pino digital 10 |
| Catodo (-) | GND |

**Botão:**
| Perna | Conexão |
|---|---|
| Perna 1 | Pino digital 7 |
| Perna 2 (diagonal oposta) | GND |

> O botão usa o resistor de pull-up interno do Arduino (`INPUT_PULLUP`), então não é necessário resistor externo para ele.

## ⚙️ Como funciona

1. O Arduino lê continuamente a posição do potenciômetro (`A0`), com valores de 0 a 1023.
2. Se o valor estiver acima de um limite (posição "direita"), o LED direito pisca.
3. Se estiver abaixo de outro limite (posição "esquerda"), o LED esquerdo pisca.
4. Na posição central, ambos os LEDs ficam apagados.
5. Um toque rápido no botão alterna o modo pisca-alerta: quando ativado, os dois LEDs piscam juntos continuamente, ignorando a posição do potenciômetro, até um novo toque desativá-lo.

O piscar é controlado com `millis()` (em vez de `delay()`), o que permite que o programa continue lendo o botão e o potenciômetro sem travar durante a piscada.

## 💻 Código

O código-fonte está no arquivo [`seta_carro.ino`](./seta_carro.ino).

## 🎛️ Simulação

O circuito completo pode ser visualizado e simulado diretamente no navegador, sem precisar dos componentes físicos:

👉 [Simulação no Tinkercad](https://www.tinkercad.com/things/gTLtL7y7Duy-setacarro?sharecode=njsWMAI4VfQNp1IrYL9Mq9Y8bNaDRYjI20dU04oOM_0)

## 🚀 Possíveis melhorias futuras

- Substituir o potenciômetro por um encoder rotativo, simulando um volante sem fim de curso.
- Adicionar um terceiro LED central para indicar visualmente que o pisca-alerta está ativo.
- Adicionar som (buzzer) sincronizado com o piscar, como em um carro real.

---

Projeto desenvolvido como exercício prático de eletrônica com Arduino.
