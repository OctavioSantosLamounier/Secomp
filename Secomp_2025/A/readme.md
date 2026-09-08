# Problema A

Mariano quer testar os itens antigos que encontrou seguindo uma ordem de prioridade baseada na idade de cada um. Isso se resume a **ordenar os itens por idade** e reportar seus índices originais na ordem final.

Pelo texto do enunciado, a prioridade seria dos itens mais velhos para os mais novos, mas a tabela de saída esperada mostra ordem crescente (mais novo primeiro). o código segue a tabela, que é o critério real de correção. Em caso de empate na idade, vale a ordem de entrada.

## Algoritmo

1. Lê os `N` valores de idade, guardando cada um junto com seu índice original (`pair<idade, índice>`).
2. Ordena o vetor de pares por idade crescente usando `stable_sort`. a estabilidade garante que empates preservem a ordem original de entrada, como pede o enunciado.
3. Imprime apenas os índices (`second`), na ordem final.

## Complexidade

- **Tempo:** `O(N log N)` — dominado pela ordenação;
- **Memória:** `O(N)` para o vetor de pares.