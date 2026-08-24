# Problema D

O balão sempre percorre uma reta horizontal completa, de `x = 0` até `x = w`, numa altura `y` fixa (real). Isso significa que, para qualquer macaco em `(x_i, y_i)`, o balão vai passar exatamente pela coordenada `x = x_i` em algum momento — logo a distância mínima entre o macaco e a trajetória do balão é simplesmente `|y - y_i|`.

Ou seja: **a posição `x_i` do macaco não importa**. Cada macaco só cobre uma faixa vertical de alturas:

```
[max(0, y_i - r_i), min(h, y_i + r_i)]
```

O problema vira 1D: só existe furo na defesa se esses intervalos de altura, unidos, não cobrirem `[0, h]` por completo.

## Algoritmo

1. Para cada macaco, calcula o intervalo `[li, ls]` que ele cobre.
2. Ordena os intervalos por `li`.
3. Varre os intervalos mantendo `inicio` = até onde a cobertura chegou:
   - se o próximo intervalo começa depois de `inicio` (`li > inicio`), tem buraco → sobra espaço pra um balão passar.
   - senão, estende `inicio = max(inicio, ls)`.
4. No final, se `inicio >= h`, a defesa é total (`sim`); caso contrário, existe brecha (`nao`).

É o clássico problema de **cobertura de intervalos** (interval covering / merge intervals).

## Complexidade

- **Tempo:** `O(n log n)`, dominado pelo sort.
- **Memória:** `O(n)`.
