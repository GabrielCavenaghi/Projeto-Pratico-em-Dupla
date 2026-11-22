# Divisão de Tarefas – Projeto Sistema Modular em C

**Autores:** Joyce Cristina da Silva e Gabriel de Oliveira  
**Data:** Nov 22, 2026

## Tema escolhido: Catálogo de Jogos Digitais

A dupla escolheu o **tema 1 (Catálogo de Jogos Digitais)** porque os dois têm o mesmo interesse por jogos, e isso deixa o desenvolvimento mais fácil por quatro motivos:

- Os dois entendem os dados sem explicação (título, desenvolvedora, preço, horas jogadas), então ninguém perde tempo descobrindo o que cada campo significa.
- É simples criar dados de teste reais, com jogos que a dupla conhece, e perceber de cara quando algo sai errado na listagem ou no relatório.
- A `struct` cobre os tipos exigidos: inteiro (`código` e `horas jogadas`), texto (`título` e `desenvolvedora`) e ponto flutuante (`preço`).
- O relatório pedido (média de preço ou jogo com mais horas jogadas) é fácil de conferir à mão.

**Campos da `struct Jogo`:**  
`código`, `título`, `desenvolvedora`, `preço` e `horas jogadas`.

---

## Quem faz o quê

### Joyce
- Escreve o `jogo.h`: `struct Jogo`, `#define MAX 100` e os protótipos de todas as funções.
- Escreve `inicializar`, `cadastrar`, `listar` e `buscar` no `jogo.c`.
- Escreve no `README` a identificação da dupla, o motivo do tema e o relato de como modelaram o problema.

### Gabriel
- Escreve `carregar` e `salvar` (leitura e gravação do `dados.txt`) no `jogo.c`.
- Escreve `relatorio` e `liberar` no `jogo.c`.
- Escreve o `main.c`, com o menu em `do-while` e `switch-case`.
- Escreve no `README` as instruções de compilação e execução.

### Juntos
- Criar o repositório no GitHub, juntar o código, compilar e testar o programa completo.
- Cada um revisa o código do outro antes de enviar.

---

## Combinados

- **Formato do `dados.txt`:** um jogo por linha, campos separados por `;`, por exemplo:
  ```text
  1;Hades;Supergiant Games;47.99;32
  ```
- **Controle de versão:** Cada um faz commit só nos arquivos que são seus; o `jogo.h` só muda com acordo dos dois.
