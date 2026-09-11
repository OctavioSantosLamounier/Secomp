# Problema B

Um número é "de base K" quando **todos** os seus dígitos são menores que K. O caso binário (K = 2, só dígitos 0 e 1) é apenas um caso particular dessa mesma regra. Como N pode ter vários dígitos, ele é lido como string: basta percorrer cada caractere e comparar seu valor numérico com K. Se existir algum dígito `>= K`, N não é um número de base K.

## Algoritmo

1. Ler N como string e K como inteiro.
2. Para cada dígito de N, comparar `str[i]` com o caractere `K + '0'`; se `str[i] >= K + '0'`, esse dígito viola a condição.
3. Se nenhum dígito violar a condição, imprimir "SIM"; caso contrário, "NAO".

## Complexidade

- **Tempo:** `O(len(N))`, uma única passada pelos dígitos.
- **Memória:** `O(len(N))` para armazenar a string.