# Grafos em C

Este projeto apresenta um programa simples em C que calcula o menor caminho
entre dois vértices de um grafo não direcionado com 10 vértices. O código
ilustra como essa estrutura de dados pode ser aplicada em diversas áreas e
serve como ponto de partida para experimentos e estudos.

## 1. Contexto
Grafos representam elementos (vértices) interconectados por relações
(arestas). Apesar de abstratos, estão presentes em muitos sistemas reais:

- **Sistemas de Navegação e Mapas:** vértices correspondem a pontos
  geográficos e arestas a trechos de ruas com pesos baseados em tempo ou
  distância.
- **Redes de Computadores e Internet:** vértices podem ser roteadores ou
  servidores e as arestas representam conexões com pesos de latência.
- **Ciência de Dados e Inteligência Artificial:** vértices modelam entidades
  (usuários, itens, neurônios) e as arestas representam relações ponderadas,
  como similaridade ou peso sináptico.

Calcular o menor caminho em um grafo é uma ferramenta fundamental para otimizar
rotas, o fluxo de pacotes em redes e diversas análises em grandes volumes de
dados.

## 2. Objetivo
- Carregar um grafo não direcionado contendo 10 vértices;
- Calcular o menor caminho entre dois vértices escolhidos pelo usuário
  utilizando o algoritmo de Dijkstra (para pesos positivos);
- Exibir o trajeto completo e o custo total do caminho;
- Demonstrar, de forma prática, como algoritmos de menor caminho podem ser
  aplicados nos contextos mencionados.

## 3. Requisitos Técnicos
- Representação do grafo por matriz de adjacência;
- Entrada e saída tratadas adequadamente;
- Código comentado destacando as principais etapas;
- Compilação em C padrão ANSI (utilizado aqui `-std=c99`).

## 4. Critérios de Avaliação
1. Algoritmo correto de menor caminho: **5 pontos**;
2. Estrutura de dados adequada: **3 pontos**;
3. Entrada e saída bem tratadas, com comentários: **2 pontos**.

## 5. Apresentação em Sala
O programa deve ser executado com pelo menos um grafo de teste diferente do
exemplo padrão. Durante a apresentação, o professor poderá questionar:

- Como o grafo foi representado;
- Funcionamento do algoritmo de Dijkstra;
- Limitações ou possíveis extensões (grafos direcionados, pesos negativos
  etc.).

A nota final só será atribuída após esta validação oral.

## 6. Compilando o Projeto
Para compilar, utilize um compilador compatível com ANSI C. Um exemplo com GCC:

```bash
gcc -std=c99 -Wall -Wextra -o grafos main.c
```

## 7. Executando
Ao executar o programa, informe o número de arestas, cada aresta com origem,
destino e peso (todos entre 1 e 10, com peso não negativo) e, em seguida,
os vértices de origem e destino. O programa imprime o custo total e o caminho
percorrido.

```bash
./grafos
Numero de arestas: 5
Aresta 1 (origem destino peso): 1 2 10
Aresta 2 (origem destino peso): 2 3 5
Aresta 3 (origem destino peso): 3 4 2
Aresta 4 (origem destino peso): 4 5 3
Aresta 5 (origem destino peso): 5 1 7
Vertice de origem (1-10): 1
Vertice de destino (1-10): 5
Custo total: 7
Caminho: 1 -> 5
```

## 8. Exemplo prático: caminho entre cidades

Neste exemplo, consideramos o grafo com 10 vértices que representam cidades brasileiras fictícias:

| Índice | Cidade           |
|--------|------------------|
| 1      | Porto Alegre     |
| 2      | Florianópolis    |
| 3      | Curitiba         |
| 4      | São Paulo        |
| 5      | Rio de Janeiro   |
| 6      | Belo Horizonte   |
| 7      | Brasília         |
| 8      | Salvador         |
| 9      | Fortaleza        |
| 10     | Recife           |

### Exemplo de execução

```bash
Escolha o grafo de teste:
1 - Grafo Joinville-BH
2 - Outro grafo de exemplo
Opcao: 2
Vertice de origem (1-10): 3
Vertice de destino (1-10): 10
```

### Saída esperada

```
Custo total: 2920
Caminho: 3 -> 6 -> 7 -> 10
```

### Interpretação do resultado

O caminho encontrado pelo algoritmo é:

- 3: Curitiba  
- 6: Belo Horizonte  
- 7: Brasília  
- 10: Recife  

Com custo total (distâncias somadas):

- Curitiba → Belo Horizonte = 900  
- Belo Horizonte → Brasília = 720  
- Brasília → Recife = 1300  

Total: 900 + 720 + 1300 = 2920
