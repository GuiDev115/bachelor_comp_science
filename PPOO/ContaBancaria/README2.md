# Conta Bancaria - Parte 2

Este exercício tem como objetivo trabalhar o conceito de Coleções em Java.
Ele é uma continuação de um exercício anterior ([Conta Bancaria](https://github.com/ufla-ppoo/ContaBancaria)).

Para fazer o exercício basta seguir os passos abaixo.
Não se esqueça de fazer um commit e sincronizar suas alterações ao final de cada passo.

## Passo 0 - Código do exercício anterior

Neste passo, você deverá pegar o código do exercício anterior de conta bancária e utilizá-lo como o código inicial deste exercício.
Para isso, basta copiar os arquivos de extensão `.java` do exercício anterior para a pasta `src` deste projeto.

Observação: caso você não tenha feito todos os passos do exercício anterior, é necessário fazer isso agora, para que consiga fazer os passos abaixo.

## Passo 1 - Coleção de Contas

No exercício anterior, ao tratar a transferência entre as contas, nós criamos dois atributos na classe que trata o caixa eletrônico para tratar duas contas diferentes.
Mas agora que conhecemos o conceito de coleções, vamos substituir esses dois atributos por uma lista de contas, utilizando a classe `ArrayList`.
Com isso, o usuário poderá criar quantas contas ele quiser.

Além disso, você deve incluir uma nova opção no menu para listar todas as contas já criadas.

- Ao acessar esta opção, o programa deve exibir os dados de cada conta (número e nome do cliente) em uma linha separada.

Lembre-se que no exercício anterior já alteramos nosso código para que o usuário informe o código da(s) conta(s) a ser(em) utilizada(s) nas operações de consultar saldo, saque, depósito e transferência.

- Agora você deverá alterar a implementação para que a conta solicitada pelo usuário seja buscada na lista de contas.

Obs.: lembre-se que não devem existir duas contas com o mesmo número na lista de contas (o Passo 6 do exercício anterior já garante que cada objeto conta tem um número diferente).

## Passo 2 - Remoção de Contas

Vamos agora adicionar uma nova opção no menu do nosso programa para que o usuário consiga remover uma conta da lista.

- O usuário deverá informar o número da conta a ser removida.
- A conta só poderá ser removida se o seu saldo for igual a zero.

  - Se tiver dinheiro na conta, deve ser exibida uma mensagem para o usuário dizendo que não é possível cancelar contas com saldo disponível.
  - Se a conta estiver usando o limite (ou seja, tiver saldo negativo), deve ser exibida mensagem dizendo que não é possível cancelar contas em débito.

## Passo 3 - Filtrar contas pelo nome do cliente

Agora vamos adicionar uma nova opção de menu para filtrar as contas de acordo com o nome do cliente.
Esta opção deve funcionar da seguinte forma:

- O usuário deverá informar uma string com o nome (ou parte do nome) de um cliente.
- O programa exibirá então os dados (número da conta e nome do cliente) das contas que tenham o nome (ou a parte do nome) informada pelo usuário.

Exemplo:

Suponha que existam as seguintes contas (números de conta e nomes de clientes):

```text
1000 - João da Silva
1001 - Joaquim Ferreira
1002 - Maria Pereira
1003 - Pedro José
```

E suponha que o usuário informe a string `"Jo"`.

- Nesse caso, deverão ser exibidos os dados das contas 1000, 1001 e 1003, pois em todas elas os nomes dos clientes possuem a substring `"Jo"`.

> **Dica 1: método `contains`**
> 
> A classe String do Java possui um método chamado `contains` que indica se uma string possui uma determinada substring.
> O programa abaixo ilustra a utilização de tal método.
> Experimente implementá-lo em seu computador.
> 
> ```java
> Scanner entrada = new Scanner(System.in);
> 
> System.out.println("Digite uma frase:");
> String frase = entrada.nextLine();
> 
> System.out.println("Digite uma palavra:");
> String palavra = entrada.nextLine();
> 
> if (frase.contains(palavra)) {
>     System.out.println("Palavra existe na frase");
> }
> else {
>     System.out.println("Palavra não encontrada!");
> }
> ```


> **Dica 2: maiúsculas e minúsculas**
> 
> A princípio, não é necessário tratar a questão de maiúsculas e minúsculas.
> Por exemplo, se o usuário digitasse `"jo"` no exemplo acima, nenhuma conta seria exibida.
> 
> Mas, note que não é difícil permitir que o usuário digite uma substring sem se preocupar com isso.
> Basta fazer uma busca na internet por métodos da classe `String` do Java que convertam strings para minúsculo/maiúsculo, ou que comparem strings ignorando essa questão.

## (Opcional) Passo 4 – Entendendo as vantagens da classe HashMap

No Passo 1 nós criamos um objeto `ArrayList` para gerenciar a coleção de contas no nosso programa.
Agora veremos quais são as vantagens de se utilizar um objeto `HashMap` para fazer a mesma coisa.

- Obs.: a implementação deste passo deve ser feita em uma nova classe, pois ele vai alterar o que você fez nos passos anteriores e eu preciso ver sua implementação anterior para corrigir seu exercício. Portanto, você deve primeiro criar uma nova classe para representar o caixa eletrônico (exemplo: `CaixaEletronicoComHashMap`).

Nesta nova classe você deverá:

- Substituir o objeto `ArrayList` de contas por um objeto `HashMap` de contas, no qual a chave é o número da conta e o valor é um objeto do tipo conta.
- Alterar a opção de listar contas para utilizar o `HashMap`.
- Alterar as opções de operação das contas (saldo, depósito, etc.) para buscar a conta do `HashMap`.
  - O que achou de como o código ficou em comparação com o anterior?
- Alterar a opção de remoção de contas para remover do HashMap.
  - O que achou de como o código ficou em comparação com o anterior?
