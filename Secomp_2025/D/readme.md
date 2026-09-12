# Desespero pelas Notas

O problema pede para escolher exatamente K das N notas de forma a maximizar a razão entre a soma das notas escolhidas e a soma dos pesos escolhidos: soma(a_i)/soma(b_i). Não dá pra resolver isso de forma gulosa direta, porque uma nota alta com peso baixo nem sempre é boa escolha — ela também afeta o denominador. E testar todos os subconjuntos de tamanho K é inviável para N até 1e5.

A saída é mudar a pergunta: em vez de "qual é a razão máxima?", perguntamos "existe algum subconjunto de K notas com razão maior ou igual a um valor x?". Essa pergunta é fácil de responder: a condição soma(a_i)/soma(b_i) ≥ x é equivalente a soma(a_i - x·b_i) ≥ 0 (multiplicando os dois lados por soma(b_i), que é sempre positiva). Então o problema vira: escolha as K notas que maximizam soma(a_i - x·b_i); se esse máximo for ≥ 0, x é atingível.

Como cada peso b_i é positivo, aumentar x sempre diminui esse máximo — a função é estritamente decrescente em x, e existe um único ponto x* onde ela vale exatamente 0. Esse x* é a resposta do problema (prova: no subconjunto que atinge o máximo 0, soma(a_i) - x*·soma(b_i) = 0, ou seja, a razão desse subconjunto é exatamente x*; e nenhum outro subconjunto pode superar x*, senão o máximo seria positivo).

Isso é exatamente o algoritmo de Dinkelbach: em vez de fazer busca binária cega em x até a precisão desejada, cada iteração usa o próprio subconjunto ótimo do x atual para calcular o próximo x (a razão real desse subconjunto). Como a função que estamos zerando é linear por partes (máximo de N retas, uma por nota), isso equivale a aplicar o método de Newton nela, e converge em poucas iterações — bem menos que as ~50-60 que uma busca binária ingênua exigiria para a mesma precisão.

## Algoritmo

1. Comece com um valor inicial x (0 já é suficiente).
2. Para o x atual, calcule c_i = a_i - x·b_i para cada uma das N notas.
3. Selecione as K notas com maior c_i. Argumento de troca: se alguma nota fora do conjunto escolhido tem c_i maior que alguma nota dentro dele, trocá-las aumenta a soma — logo, no ótimo, o conjunto é exatamente as K maiores.
4. Calcule a razão real dessas K notas escolhidas: novo_x = soma(a_i escolhidos) / soma(b_i escolhidos).
5. Se novo_x for praticamente igual ao x atual (diferença menor que uma tolerância pequena, ex. 1e-10), pare — essa é a resposta. Caso contrário, volte ao passo 2 usando novo_x.

## Complexidade

- Tempo: O(N) por iteração (seleção das K maiores via `nth_element`, que roda em O(N) médio), multiplicado pelo número de iterações do Dinkelbach — poucas dezenas no pior caso, geralmente bem menos na prática. Total: O(N · T).
- Memória: O(N), para armazenar notas, pesos e os valores auxiliares de cada iteração.