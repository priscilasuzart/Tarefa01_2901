# Tarefa 01 - Unidade 04 - Capítulo 05 - Projeto Semáforo  
  
Este projeto implementa um semáforo simples utilizando um Raspberry Pi Pico W. O semáforo alterna entre as cores vermelho, amarelo e verde, com um intervalo de 3 segundos para cada estado.  
  
# Componentes Necessários
Microcontrolador: Raspberry Pi Pico W  
LEDs: 1 LED vermelho, 1 LED amarelo e 1 LED verde  
Resistores: 3 resistores de 330 Ω (um para cada LED)  

# Esquema de Conexão
Os componentes foram conectados da seguinte forma:

1) LED Vermelho:  
Anodo (perna longa) → GPIO 13  
Catodo (perna curta) → Resistor de 330 Ω → GND  

2) LED Amarelo:  
Anodo (perna longa) → GPIO 12  
Catodo (perna curta) → Resistor de 330 Ω → GND  

3) LED Verde:  
Anodo (perna longa) → GPIO 11  
Catodo (perna curta) → Resistor de 330 Ω → GND

# Funcionamento do Código
O código implementa um semáforo com três estados:  
1) Vermelho: O LED vermelho fica aceso por 3 segundos.  
2) Amarelo: O LED amarelo fica aceso por 3 segundos.  
3) Verde: O LED verde fica aceso por 3 segundos.  
Após o ciclo completo, o semáforo retorna ao estado vermelho e repete o processo indefinidamente.

# Link do vídeo  
https://drive.google.com/file/d/1r9Mm0cO16jNp0qrYbKyvOpa_r3O0gA9J/view?usp=sharing
  
# Desenvolvido por
Priscila Pereira Suzat de Carvalho
