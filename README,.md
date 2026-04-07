# Bem-vindo ao projeto: Morse Sys - FLP

Um sistema de tradução simultânea de texto para Código Morse, utilizando feedback visual e auditivo em tempo real.

Enfim, vamos lá.

### Olá, sou Felipe Liandro 👋

Trabalho como analista de dados, e frequentemente produzo alguns projetos que envolvem bases de programação, engenharia e eletrônica. Se estiver interessado, considere conhecer meu LinkedIn:  
[Felipe de Jesus Alves Liandro](https://www.linkedin.com/in/felipe-de-jesus-alves-liandro-415890222/)

---

## Qual a ideia do projeto?

Criar um tradutor de Código Morse otimizado para microcontroladores. O programa recebe uma string de texto, processa caractere por caractere e converte a mensagem em sinais sonoros (bips curtos e longos) através de um speaker, enquanto exibe o status em um display LCD I2C. 

O grande diferencial deste projeto não é apenas o que ele faz, mas **como** ele faz: o código foi escrito seguindo padrões de *Clean Code* e arquitetura modular de sistemas embarcados.

---

## Materiais e Linguagens

Todo o ecossistema foi desenvolvido em **C++** utilizando o framework do **Arduino** por dentro da IDE do **PlatformIO**, o que nos permite uma separação profissional de bibliotecas e dependências.

### Materiais:
1. ESP32 Dev Kit V1 (ou qualquer placa compatível com o framework Arduino)
2. Display LCD 16x2 com módulo I2C
3. Buzzer Passivo ou Speaker (ligado ao pino 18)
4. Protoboard e Jumpers

---

## A Arquitetura do Código

Diferente de scripts simples de um único arquivo, este projeto foi refatorado para separar as Regras de Negócio do Hardware. 

### 1. O Coração do Projeto: `config.h`
Localizado na pasta `include/`, é o nosso painel de controle. Aqui definimos velocidades de reprodução (`PLAY_SPEED`), endereços I2C, pinos de saída e os tempos de espaçamento do código Morse. Se precisarmos mudar o hardware, alteramos apenas este arquivo.

### 2. O Módulo de Display (`display.cpp` / `.h`)
Responsável exclusivamente por conversar com a tela. 
* Instanciamos a classe `LiquidCrystal_I2C` aqui e a compartilhamos de forma segura usando a palavra-chave `extern`.
* Criamos funções limpas como `setupDisplay()` e `displayText()`, que centralizam o texto automaticamente na tela sem poluir o loop principal.

### 3. O Motor de Tradução (`translator.cpp` / `.h`)
Aqui acontece a mágica (e a performance).
* **Adeus, `Switch Case` gigante:** Em vez de dezenas de `ifs` lentos para descobrir qual letra é qual, utilizamos um Array Constante de ponteiros de char (`MORSE_ALPHABET`).
* **Complexidade O(1):** O processador pega a letra (ex: 'C'), subtrai pela base ASCII ('A') e pula direto para o índice correto da memória. É a forma mais rápida de fazer o *parsing* do texto em microcontroladores.
* O sistema então lê os `.` e `-` do dicionário e chama as funções `sendDot()` e `sendDash()`, que emitem as frequências no Speaker usando PWM.

---

## Dentro do ESP32

O `main.cpp` funciona apenas como um maestro, chamando os módulos:

1. No `setup()`, iniciamos a comunicação I2C e a tela de boas-vindas ("Morse Sys - FLP").
2. No `loop()`, passamos um texto constante (como `"Hello, world!"`) para o nosso `translator()`.
3. O ESP32 quebra o texto, ignora caracteres inválidos, aplica o atraso correto para os espaços (`SPACE_TIME`) e toca a mensagem com precisão de milissegundos.

---

## Simples assim, viu?

E dessa forma conseguimos um sistema modular, eficiente em memória RAM e extremamente fácil de dar manutenção.

Esse projeto foi um excelente exercício não apenas para entender a lógica temporal do Código Morse, mas principalmente para aplicar conceitos avançados de C++, como a diferença entre declarações e implementações (`.h` vs `.cpp`), gerenciamento de escopo global e otimização de memória usando `const char*` em vez de objetos `String` dinâmicos.

### Claro que sempre pode evoluir.
O próximo passo lógico seria adicionar botões para transformar o sistema em um telégrafo bidirecional! Mas vamos combinar que já é bem satisfatório ver o código modular rodando liso.

---

## Muito obrigado!

Muito prazer em ter você por aqui. Caso tenha se interessado pela estrutura do código ou pelo projeto, considere dar um like ou uma estrelinha por aqui. 

Até mais (:

— **Felipe Liandro**