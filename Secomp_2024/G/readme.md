# Problema G

Esse é o clássico **Subset Sum** (uma mochila 0/1 em que o "valor" de cada item é igual ao seu "peso"): cada tigela ou entra inteira, ou fica de fora.

Como `k <= 10^4`, dá para resolver com uma DP booleana: `dp[i]` indica se é possível formar a soma `i` usando algum subconjunto das tigelas já processadas. A cada tigela nova, atualiza-se `dp` de trás para frente (capacidades decrescentes), garantindo que cada tigela seja usada no máximo uma vez.

```cpp
vector<bool> dp(p+1, false);
dp[0] = true;

for (int num : v)
    for (int i=p; i>=num; --i)
        if (dp[i] || dp[i - num]) {
            best = max(best, i);
            dp[i] = true;
        }
```

## Algoritmo

1. Cria `dp[0..k]`, com `dp[0] = true` (soma zero sempre alcançável, com o conjunto vazio).
2. Para cada tigela `a_i`, percorre as capacidades de `k` até `a_i`, marcando `dp[i] = true` sempre que `dp[i]` ou `dp[i - a_i]` já for alcançável, guardando em `best` o maior índice atingido.
3. Responde `best`, a maior soma de doces alcançável sem ultrapassar `k`.

## Complexidade

- **Tempo:** `O(n * k)`.
- **Memória:** `O(k)` para o vetor de DP.
