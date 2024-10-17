## SuperMarkaton - Sistema de Carrinho de Compras

## Desenvolvimento
SuperMarkaton foi desenvolvido em linguagem C, visando criar um sistema simples e intuitivo para gerenciar um carrinho de compras. A implementação focou na usabilidade e na clareza do código, permitindo que qualquer usuário possa interagir facilmente com as funcionalidades disponíveis
## Bibliotecas Utilizadas
 stdio.h - Fornece funções para entrada e saída de dados, como printf e scanf, que são essenciais para interagir com o usuário.

 stdlib.h - Inclui funções para alocação de memórica, controle de processos e conversões, como system() para limpar a tela.

 string.h - Proporciona funções para a manipulação de strings, como strcspn() e strcmp(), que são utilizadas para remover caracteres indesejados e comparar strings, respectivamente.

## Funcionalidades 
1. _Adicionar Produto_: Permite ao usuário adicionar um produto com seu nome, quantidade e preço.

2. _Remover Produto_: Permite que o usuário remova um produto do carrinho pelo seu índice.

3. _Exibir Carrinho_: Mostra todos os produtos atualmente no carrinho, incluindo seus detalhes.

4. _Atualizar Produto_: Permite ao usuário atualizar a quantidade e o preço de um produto existente.

5. _Finalizar Compra_: Calcula a valor total devido e limpa o carrinho após a compra.

6. _Pesquisar Produto_: Permite que o usuário busque um produto pelo nome.

## Estrutura do Código

**Variáveis Globais**
 - _Produto p_[MAX_PRODUTOS]: Um array de estruturas Produto que contém os produtos.

 - _int totalprod_: Mantém o controle do número total de produtos no carrinho.

**Funções**

- _menu()_: Exibe o menu principal e gerencia a entrada do usuário para selecionar opções.

- _adprod()_: Adiciona um novo produto ao carrinho.

- _remorprod()_: Remove um produto do carrinho com base na entrada do usuário.

- _exibirprod()_: Exibe todos os produtos no carrinho.

- _attprod()_: Atualiza os detalhes de um produto existente.

- _finaprod()_: Finaliza a compra e calcula o valor total.

- _pesqprod()_: Busca um produto pelo nome no carrinho.
 

## Uso

1. Compile o programa usando um compilador C (ex: gcc): gcc -o SuperMarkaton SuperMarkaton.c

2. Execute o programa compilado: ./SuperMarkaton

3. Ao rodar o programa, você verá um menu com as opções para adicionar produtos, gerenciar o estoque, e finalizar compras.

## Limitações 

- o programa pode lidar com um máximo de 50 produtos.
- Ele é executado em um ambiente de linha de comando e requer entrada do usuario;

## Melhorias Futuras

- Implementar armazenamento em arquivo para salvar e carregar o estado do carrinho.
- Melhorar a funcionalidade de busca para incluir correspondências parciais.
- Adicionar autenticação de usuário para gerenciar múltiplos usuários. 
