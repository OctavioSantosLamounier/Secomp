# Problema C

Toda troca substitui uma letra por outra "parecida", e essa relação pode ser encadeada (trocar `a→b` e depois `b→c` equivale a ir de `a` até `c` em 2 trocas). Isso é exatamente um grafo não-direcionado com 26 nós (uma letra do alfabeto = um nó) e uma aresta de peso 1 para cada par de letras parecidas informado na entrada. O número mínimo de trocas para transformar `strInicial[i]` em `strFinal[i]` é o **caminho mínimo** entre essas duas letras nesse grafo.

Como cada posição da palavra é independente das demais, a resposta final é só a soma das distâncias mínimas de cada posição — e se qualquer posição não tiver caminho, a transformação inteira é impossível.

Como o grafo tem só 26 vértices, calcular todas as distâncias de uma vez com **Floyd-Warshall** é barato e evita ter que rodar uma busca por consulta.

## Algoritmo

1. Monta uma matriz `dist[26][26]`, iniciando com `0` na diagonal e infinito no resto.
2. Para cada um dos `m` pares de letras parecidas, marca `dist[a][b] = dist[b][a] = 1`.
3. Roda Floyd-Warshall entre as 26 letras para obter a distância mínima entre qualquer par.
4. Para cada posição `i` de `0` a `n-1`, soma `dist[strInicial[i]][strFinal[i]]` ao total; se algum `dist` for infinito, imprime `-1` e encerra.
5. Imprime o total acumulado.

## Complexidade

- **Tempo:** `O(26³ + n + m)` — o Floyd-Warshall entre as letras é constante (26³) e a leitura `O(n + m)`.
- **Memória:** `O(26²)` para a matriz de distâncias, mais `O(n)` para as strings.
