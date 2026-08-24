
# Problema F

Uma batalha pokémon, simular turno a turno é inviável (vidas até `10^9`, até `10^5` pokémons por lado). A saída é pular direto para o momento em que a dupla ativa `A` (Ash) e `G` (Gary) resolve o embate:

```
// rodadas até A matar G ou G matar A, isoladamente
rodadasAteG = ceil(G.vida / danoEmG)   
rodadasAteA = ceil(A.vida / danoEmA)  
```

`danoEmG`/`danoEmA` já dobram quando há vantagem de tipo. Avança-se de uma vez `min(rodadasAteG, rodadasAteA) - 1` rodadas "seguras" (dano mútuo, ninguém morre), e só então trata a rodada final.

- **`Gary` morre primeiro:** ele é substituído, mas ainda é a vez de Gary — o novo pokémon já ataca `A` nessa mesma rodada.
- **`Ash` morre primeiro:** antes de sofrer o golpe fatal, `A` ainda ataca `G` (é sempre o primeiro a agir). Esse dano de `A` em `G` tem que ser aplicado antes de remover `A` da fila — senão perde-se esse ataque e `G` fica com vida a mais do que deveria.

## Algoritmo

1. Filas de pokémons por treinador, na ordem de entrada.
2. Enquanto ambas as filas tiverem pokémon:
   - Calcula danos, `rodadasAteG` e `rodadasAteA`.
   - Avança `min(rodadasAteG, rodadasAteA) - 1` rodadas de dano simultâneo.
   - Se `G` morre: remove `G`; se a fila não esvaziar, o próximo já contra-ataca `A`.
   - Senão: aplica `G.vida -= danoEmG` (ataque final de `A`) e remove `A`.
3. Quando uma fila esvaziar, o outro treinador vence.

## Complexidade

- **Tempo:** `O(n + m)`.
- **Memória:** `O(n + m)`.
