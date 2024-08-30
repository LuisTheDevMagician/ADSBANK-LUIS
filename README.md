# ADS Bank

**Professor:** Felipe Gonçalves dos Santos  
**Aluno:** Luis Eduardo Pinheiro Martins  
**Data de Entrega:** 30/08/2024  
**Link para o Vídeo no YouTube:** [Adicionar Link Aqui]

## Descrição do Projeto

O ADS Bank é um mini sistema bancário desenvolvido em C como parte de uma atividade acadêmica. O sistema oferece funcionalidades básicas para gerenciamento de contas bancárias, permitindo que clientes realizem operações financeiras e que gerentes gerenciem os cadastros de clientes.

## Funcionalidades

### 1. Função `main()`
**Descrição:**  
Ponto de entrada do programa. Exibe o menu principal do sistema, onde o usuário pode escolher entre acessar o sistema do cliente, o sistema do gerente ou sair do programa.

**Opções:**
- **Sistema Cliente:** Leva o usuário ao menu com operações disponíveis para clientes.
- **Sistema Gerente:** Solicita nome e senha do gerente para acessar o menu com operações administrativas.
- **Sair:** Encerra o programa.

### 2. Função `sistemagerente()`
**Descrição:**  
Gerencia as operações disponíveis para o gerente. Permite o cadastro, listagem, alteração e remoção de clientes, além de oferecer a opção de sair do sistema do gerente.

**Opções:**
- **Cadastrar Cliente:** Redireciona para a função `cadastrarcliente()`.
- **Listar Clientes:** Redireciona para a função `listarclientes()`.
- **Alterar Clientes:** Redireciona para a função `alterarclientes()`.
- **Remover Clientes:** Redireciona para a função `removerclientes()`.
- **Sair:** Retorna ao menu principal.

### 3. Função `sistemacliente()`
**Descrição:**  
Gerencia as operações disponíveis para os clientes. Permite visualizar saldo, depositar, sacar, transferir valores e depositar para terceiros.

**Opções:**
- **Visualizar Saldo:** Redireciona para a função `vizualizarsaldo()`.
- **Depositar Valor na Conta:** Redireciona para a função `depositar()`.
- **Sacar Valor da Conta:** Redireciona para a função `sacar()`.
- **Transferir Valor para Outra Conta:** Redireciona para a função `transferir()`.
- **Depositar em Conta de Terceiro:** Redireciona para a função `depositarTerceiro()`.
- **Sair:** Retorna ao menu principal.

### 4. Função `cadastrarcliente()`
**Descrição:**  
Permite ao gerente cadastrar novos clientes no sistema. O gerente insere o nome, CPF e saldo inicial do cliente. Os dados são armazenados em arrays globais.

**Limitação:**  
Impede o cadastro se o número máximo de clientes (7) for atingido.

### 5. Função `listarclientes()`
**Descrição:**  
Exibe uma lista de todos os clientes cadastrados, mostrando nome, CPF e saldo de cada cliente.

**Nota:**  
Se não houver clientes cadastrados, informa que a lista está vazia.

### 6. Função `alterarclientes()`
**Descrição:**  
Permite ao gerente alterar os dados de um cliente existente (nome, CPF ou saldo). O gerente deve fornecer o CPF do cliente a ser alterado e, em seguida, selecionar qual dado deseja modificar.

### 7. Função `removerclientes()`
**Descrição:**  
Permite ao gerente remover um cliente do sistema. O gerente deve fornecer o CPF do cliente a ser removido. Após a remoção, o número de clientes é decrementado e os dados do cliente removido são excluídos.

### 8. Função `vizualizarsaldo()`
**Descrição:**  
Permite ao cliente visualizar seu saldo atual. O cliente deve fornecer seu CPF para que o sistema encontre e exiba seu saldo.

### 9. Função `depositar()`
**Descrição:**  
Permite ao cliente depositar um valor em sua conta. O cliente deve fornecer seu CPF e o valor a ser depositado. O saldo da conta é então atualizado.

### 10. Função `sacar()`
**Descrição:**  
Permite ao cliente sacar um valor de sua conta. O cliente deve fornecer seu CPF e o valor a ser sacado. Se houver saldo suficiente, o valor é subtraído do saldo atual.

### 11. Função `transferir()`
**Descrição:**  
Permite ao cliente transferir um valor de sua conta para a conta de outro cliente. O cliente deve fornecer os CPFs de origem e destino, e o valor a ser transferido. A função verifica se há saldo suficiente antes de realizar a transferência.

### 12. Função `depositarTerceiro()`
**Descrição:**  
Permite ao cliente depositar um valor na conta de outro cliente. O cliente deve fornecer o CPF do terceiro e o valor a ser depositado. O saldo do terceiro é atualizado com o novo depósito.

## Considerações Finais

Essas funções colaboram para criar um sistema bancário básico, onde clientes podem realizar operações comuns e um gerente pode gerenciar o cadastro e a manutenção dos clientes. O código é estruturado de forma que tanto o gerente quanto os clientes possam realizar suas operações de forma independente.

## Como Compilar

Utilize um compilador da linguagem C como o gcc diretamente no terminal, ou um editor de código que já tenha um compilador embarcado como DEV C++ e o VS CODE.
