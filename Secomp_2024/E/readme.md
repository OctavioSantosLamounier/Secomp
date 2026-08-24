# Problema E 

Todo dígito do número precisa ser primo (`2, 3, 5, 7`), e toda subsequência contígua também. Isso restringe tanto o espaço que só existe um conjunto **finito** de "sempre primos" — feita a analise, sobram exatamente 9:

```
2, 3, 5, 7, 23, 37, 53, 73, 373
```

## Algoritmo

Guarda esses valores num `set` e responde com uma consulta direta:

```cpp
set<int> s = {2, 3, 5, 7, 23, 37, 53, 73, 373};
cout << (s.count(n) ? "sim" : "nao");
```

## Complexidade

- **Tempo:** `O(1)`.
- **Memória:** `O(1)`.