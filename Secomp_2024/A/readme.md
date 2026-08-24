# Problema A 

A entrada sempre tem exatamente duas das três letras de `H2O`, na ordem correta. Como só existem três combinações possíveis (`H2`, `HO`, `2O`), basta checar qual delas foi lida e responder com a letra que falta:

- `H2` → falta `O`
- `HO` → falta `2`
- `2O` → falta `H`

## Complexidade

- **Tempo:** `O(1)`.
- **Memória:** `O(1)`.