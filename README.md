# Divisão de Tarefas – Projeto Sistema Modular em C

**Autores:** Joyce Cristina da Silva (RA: 1630482613044) e Gabriel de Oliveira (RA: 1630482613020)
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

---

## Documentação do Projeto

### 1. Modelagem do Problema (`struct Jogo`)

Para representar cada registro do catálogo, foi definida a estrutura `Jogo` no arquivo de cabeçalho `jogo.h`. Em memória, o sistema utiliza um vetor de ponteiros (`Jogo *vetor[MAX]`) inicializado com `NULL` em todas as posições. Cada novo jogo é alocado dinamicamente sob demanda via `malloc` e devidamente desalocado com `free` ao encerrar o programa, evitando desperdício de memória e vazamentos (*memory leaks*).

```c
#define MAX 100
#define TAM_TEXTO 50
#define ARQUIVO_DADOS "dados.txt"

typedef struct {
    int codigo;                     // Identificador numérico único do jogo
    char titulo[TAM_TEXTO];         // Nome do jogo
    char desenvolvedora[TAM_TEXTO]; // Estúdio ou empresa desenvolvedora
    float preco;                    // Valor pago pelo jogo (em R$)
    int horasJogadas;               // Quantidade de horas jogadas
} Jogo;
```

### 2. Estrutura Modular dos Arquivos

O código-fonte foi organizado em módulos independentes para separar a interface, a lógica de negócio e a interação com o usuário:

```text
├── jogo.h      # Constantes, definição da struct Jogo e protótipos das funções
├── jogo.c      # Implementação das operações do catálogo e persistência em arquivo
├── main.c      # Ponto de entrada e menu interativo (do-while e switch-case)
└── dados.txt   # Base de dados em texto plano gerada/lida pelo programa
```

### 3. Funcionalidades Implementadas

* **Inicialização e Carga Automática (`inicializar` e `carregar`):** Prepara o vetor de ponteiros e importa automaticamente os registros existentes em `dados.txt` ao iniciar a aplicação.
* **Cadastro (`1` – `cadastrar`):** Busca a primeira posição livre no vetor, valida se o código informado já não está em uso, aloca memória dinamicamente e lê os demais campos.
* **Listagem Geral (`2` – `listar`):** Percorre o vetor exibindo todos os jogos cadastrados ou informa caso o catálogo esteja vazio.
* **Busca por Código (`3` – `buscar`):** Localiza um jogo específico pelo seu identificador numérico e exibe seus dados completos.
* **Relatório Estatístico (`4` – `relatorio`):** Calcula a quantidade total de jogos, a média de preços, a soma total de horas jogadas e identifica o título com maior número de horas acumuladas.
* **Persistência e Encerramento (`5` – `salvar` e `liberar`):** Grava todos os registros ativos no arquivo `dados.txt` e libera a memória alocada antes de finalizar a execução.

### 4. Compilação e Execução

Com o compilador **GCC** instalado, abra o terminal na pasta do projeto e execute os comandos abaixo de acordo com o seu sistema operacional.

#### Linux / macOS
```bash
gcc -Wall -Wextra main.c jogo.c -o catalogo
./catalogo
```

#### Windows (CMD ou PowerShell com MinGW)
```bash
gcc -Wall -Wextra main.c jogo.c -o catalogo.exe
catalogo.exe
```

#### Exemplo de conteúdo para `dados.txt`
Caso deseje iniciar o sistema com uma base de testes já preenchida, crie um arquivo `dados.txt` na mesma pasta do executável com o seguinte conteúdo:

```text
1;Hades;Supergiant Games;47.99;32
2;Hollow Knight;Team Cherry;46.99;68
3;Celeste;Maddy Makes Games;36.99;24
4;The Witcher 3;CD Projekt Red;129.90;145
```
