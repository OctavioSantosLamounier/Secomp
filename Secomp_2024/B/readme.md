# Problema B 

Os mineiros trabalham simultaneamente, então a extração é linear no tempo: em `t` horas, juntos eles extraem `t * soma(m_i)` kg. Basta achar o menor `t` tal que `t * soma(m_i) >= k`.

Isso é só isolar `t`:

```
t = ceil(k / soma(m_i))
```

## Algoritmo

1. Somar as capacidades de todos os `n` mineiros.
2. Calcular `ceil(k / soma)`.

## Complexidade

- **Tempo:** `O(n)`, só para somar as capacidades.
- **Memória:** `O(1)`.

