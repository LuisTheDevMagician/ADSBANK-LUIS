#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das constantes para o máximo de clientes e tamanho do nome
#define MAX_NOMES 3
#define TAM_NOME 50

// Variáveis globais para armazenar informações dos clientes
char nomes[MAX_NOMES][TAM_NOME];// Armazena os nomes dos clientes
char cpf[MAX_NOMES][15]; // Armazena os CPFs dos clientes (14 dígitos + 1 para '\0')
double saldo[MAX_NOMES]; // Armazena os saldos dos clientes
int num_clientes = 0; // Número de clientes cadastrados
int i, j;// Variáveis auxiliares para loops

// Declaração das funções
void sistemagerente();
void sistemacliente();
void cadastrarcliente();
void listarclientes();
void alterarclientes();
void removerclientes();
void vizualizarsaldo();
void depositar();
void sacar();
void transferir();
void depositarTerceiro();


int main() {
    int escolha, senha, verificar;
    char gerente[] = "Luis"; // Nome do gerente
    char entradaGerente[10]; // Variável para capturar o nome do gerente
    
    // Loop principal do sistema
    while (1) {
        printf("======= Bem-vindo ao AdsBank ======\n");
        printf("Digite o numero da opcao abaixo:\n");
        printf("1 - Sistema cliente\n");
        printf("2 - Sistema gerente\n");
        printf("3 - Sair do sistema\n");
        scanf("%d", &escolha);
        getchar();  // Limpa o buffer para evitar problemas com fgets

        // Verifica a escolha do usuário e chama a função correspondente
        switch (escolha) {
            case 1:
                sistemacliente(); // Acessa o sistema dos clientes
                break;
            case 2:
                // Solicita o nome e senha do gerente
                printf("Informe o nome do gerente:\n");
                fgets(entradaGerente, sizeof(entradaGerente), stdin);
                entradaGerente[strcspn(entradaGerente, "\n")] = '\0';  // Remove o caractere '\n'

                printf("Informe a senha do gerente:\n");
                scanf("%d", &senha);
                getchar();  // Limpa o buffer

                // Verifica se o nome e a senha são corretos
                verificar = strcasecmp(entradaGerente, gerente);

                if (verificar == 0 && senha == 3216) {
                    printf("======= Acesso concedido ======\n");
                    sistemagerente(); // Acessa o sistema do gerente
                } else {
                    printf("======= Usuario ou senha incorretos =======\n");
                }
                break;
            case 3:
                // Sai do sistema
                printf("======= Voce saiu do sistema AdsBank =======\n");
                return 0;
            default:
                printf("======= Opcao invalida, tente novamente ======\n");
        }
    }


    return 0;
}

// Função que gerencia as opções do sistema do gerente
void sistemagerente(){
	
	while(1){
	int opcao;
	printf("======= Sistema Gerente =======\n");
	printf("Digite o numero da opcao abaixo que deseja realizar:\n");
	printf("1 - Cadastrar cliente\n");
    printf("2 - Listar clientes\n");
    printf("3 - Alterar clientes\n");
    printf("4 - Remover clientes\n");
    printf("5 - Sair do sistema Gerente\n");

    scanf("%d", &opcao);
    getchar(); // Limpa o buffer após a leitura do inteiro
        
        // Verifica a opção do gerente e chama a função correspondente
        switch (opcao) {
            case 1:
                cadastrarcliente();
                break;
            case 2:
                listarclientes();
                break;
            case 3:
                alterarclientes();
                break;
            case 4:
            	removerclientes();
                break;
            case 5:
                printf("======= Voce saiu do sistema gerente =======\n");
            	return;
            default:
                printf("======= Opcao invalida =======\n");
        }
	
}
}

// Função que gerencia as opções do sistema do cliente
void sistemacliente(){
	
	while(1){
	int opcao;
	printf("======= Sistema Cliente =======\n");
	printf("Digite o numero da opcao abaixo que deseja realizar:\n");
	printf("1 - Visualizar saldo\n");
    printf("2 - Depositar valor na conta\n");
    printf("3 - Sacar valor da conta\n");
    printf("4 - Transferir valor para outra conta\n");
    printf("5 - Depositar em conta de terceiro\n");
    printf("6 - Sair do sistema clientes\n");
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer após a leitura do inteiro
        
        switch (opcao) {
            // Verifica a opção do cliente e chama a função correspondente
            case 1:
                vizualizarsaldo();
                break;
            case 2:
                depositar();
                break;
            case 3:
                sacar();
                break;
            case 4:
            	transferir();
                break;
            case 5:
                depositarTerceiro();
                break;
            case 6:
                printf("======= Voce saiu do sistema de clientes =======\n");
                return;
            default:
                printf("====== Opcao invalida ======\n");
        }
	
}
}

// Função para cadastrar um novo cliente
void cadastrarcliente() {
    //Se o numero de clientes determinada na variavel global chegar ao maximo, o sistema impede de criar mais
    if (num_clientes >= MAX_NOMES) {
        printf("Numero maximo de clientes atingido.\n");
        return;
    }
    
    // Captura o nome do cliente
    printf("Digite o nome completo do cliente %d: ", num_clientes + 1);
    fgets(nomes[num_clientes], TAM_NOME, stdin);
    nomes[num_clientes][strcspn(nomes[num_clientes], "\n")] = '\0'; // Remove o newline no final do nome
    
    // Captura o CPF do cliente
    printf("Digite o CPF do cliente %d: ", num_clientes + 1);
    fgets(cpf[num_clientes], 15, stdin);
    cpf[num_clientes][strcspn(cpf[num_clientes], "\n")] = '\0'; // Remove o newline no final do CPF
    
    // Captura o saldo do cliente
    printf("Digite o saldo do cliente %d: ", num_clientes + 1);
    scanf("%lf", &saldo[num_clientes]);
    getchar(); // Limpa o buffer após a leitura do saldo
    
    num_clientes++; // Atualiza o número de clientes
    
    printf("======= Cliente cadastrado com sucesso =======\n");
}

// Função para listar todos os clientes cadastrados
void listarclientes() {
    //Se nenhum cliente tiver sido cadastrado mostarará que nenhum cliente foi cadatrado ainda
    if (num_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    // Loop para imprimir todos os clientes cadastrados
    printf("======= Lista de clientes =======\n");
    for (i = 0; i < num_clientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", nomes[i]);
        printf("CPF: %s\n", cpf[i]);
        printf("Saldo: %.2f\n", saldo[i]);
        printf("\n");
    }
}

// Função para alterar os dados de um cliente existente
void alterarclientes() {
    if (num_clientes < 1) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    
    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o CPF do cliente que deseja alterar: \n");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF
    
    // Procura o cliente com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("Cliente encontrado!\n");
            printf("Nome: %s\n", nomes[i]);
            printf("CPF: %s\n", cpf[i]);
            printf("Saldo: %.2f\n", saldo[i]);
            
            // Exibe o menu de alteração de dados
            printf("Qual dado do cliente voce deseja alterar\n");
            printf("1 - Nome\n2 - CPF\n3 - Saldo\n\n");
            int escolha;
            scanf("%d",&escolha);
            getchar();
            
            // Verifica qual dado o usuário deseja alterar e faz a alteração correspondente
		    switch(escolha){
            	case 1:  
			printf("Digite o novo nome para o cliente: \n");
            fgets(nomes[i], TAM_NOME, stdin);
            nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove o newline no final do nome
            printf("======= Cliente atualizado com sucesso =======\n");
            return;
            	case 2:
            printf("Digite o novo CPF para o cliente:\n");
            fgets(cpf[i], 15, stdin);
            cpf[i][strcspn(cpf[i], "\n")] = '\0'; // Remove o newline no final do CPF
            printf("======= Cliente atualizado com sucesso =======\n");
            return;
            	case 3:
            printf("Digite o novo saldo para o cliente:\n");
            scanf("%lf", &saldo[i]);
            getchar(); // Limpa o buffer após a leitura do saldo
            printf("======= Cliente atualizado com sucesso =======\n");
            return;
			}
        }
    }
    
    printf("Cliente com CPF %s nao encontrado.\n", cpfD);
}

// Função para remover um cliente
void removerclientes() {
    if (num_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o CPF do cliente que deseja remover: \n");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF
    
    // Procura o cliente com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("Cliente encontrado.\n");
            printf("Nome: %s\n", nomes[i]);
            printf("CPF: %s\n", cpf[i]);
            printf("Saldo: %.2f\n", saldo[i]);

            // Confirmar remoção
            printf("Tem certeza que deseja remover este cliente? (s/n): ");
            char confirmacao;
            scanf("%c", &confirmacao);
            getchar(); // Limpa o buffer após a leitura da confirmação

            if (confirmacao == 's' || confirmacao == 'S') {
                // Remover cliente, deslocando os elementos à esquerda
                for (j = i; j < num_clientes - 1; j++) {
                    strcpy(nomes[j], nomes[j + 1]);
                    strcpy(cpf[j], cpf[j + 1]);
                    saldo[j] = saldo[j + 1];
                }
                num_clientes--; // Atualiza o número de clientes
                printf("======= Cliente removido com sucesso =======\n");
            } else {
                printf("======= Remocao cancelada =======\n");
            }
            return;
        }
    }
    
    printf("Cliente com CPF %s nao encontrado.\n", cpfD);
}

// Funcao para vizualizar o saldo
void vizualizarsaldo() {
    if (num_clientes < 1) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    
    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o seu CPF para visualizar seu saldo: \n");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF
    
    // Procura o cliente com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("Nome: %s\n", nomes[i]);
            printf("Saldo: %.2f\n", saldo[i]);
        }
    }
}

// Funcao para depositar na propia conta
void depositar(){
 if (num_clientes < 1) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    
    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o seu CPF para depositar: \n");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF
    
    double depositar;//declara variavel responsavel pela operacao de depositar
    
    // Procura o cliente com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("Nome: %s\n", nomes[i]);
            printf("Saldo: %.2f\n", saldo[i]);
            printf("Informe o valor que voce deseja depositar:\n");
            scanf("%lf", &depositar);
            getchar();
        
            saldo[i] += depositar;//adiciona o valor informado no saldo da conta
            printf("======= Valor do deposito: %.2lf ======\n", depositar);
            printf("======= Saldo atual: %.2lf =======\n", saldo[i]);
        }
    }
}

// Funcao para sacar o dinheiro da propia conta
void sacar(){
 if (num_clientes < 1) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    
    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o seu CPF para poder sacar: \n");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF

    double sacar;//declara variavel responsavel pela operacao de sacar
    
    // Procura o cliente com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("Nome: %s\n", nomes[i]);
            printf("Saldo: %.2f\n", saldo[i]);
            printf("Informe o valor que quer sacar:\n");
            scanf("%lf", &sacar);
            getchar();
            if(sacar > saldo[i]){
                printf("Valor excede o valor do Saldo, informe um valor que seja menor que o saldo\n");
                break;
            }
            saldo[i] -= sacar;// realiaza operacao subtraindo o valor informado do saldo
            printf("======= Valor do saque: %.2lf =======\n", sacar);
            printf("======= Saldo atual: %.2lf =======\n", saldo[i]);
        }
    }
}

// Funcao para transferir dinheiro da conta do usuario para conta de um terceiro
void transferir() {
    if (num_clientes < 1) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    
    char cpfOrigem[15];
    printf("Digite o seu CPF: \n");
    fgets(cpfOrigem, 15, stdin);
    cpfOrigem[strcspn(cpfOrigem, "\n")] = '\0'; // Remove o newline no final do CPF

    // Procura o cliente de origem com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfOrigem) == 0) {
            printf("Nome: %s\n", nomes[i]);
            printf("Saldo: %.2f\n", saldo[i]);

            char cpfDestino[15];
            printf("Digite o CPF da pessoa para qual voce deseja transferir: \n");
            fgets(cpfDestino, 15, stdin);
            cpfDestino[strcspn(cpfDestino, "\n")] = '\0'; // Remove o newline no final do CPF

            // Procura o cliente de destino com o CPF fornecido
            for (int j = 0; j < num_clientes; j++) {
                if (strcmp(cpf[j], cpfDestino) == 0) {
                    printf("Nome do destinatario: %s\n", nomes[j]);

                    double valorTransferir;//declara variavel responsavel pela transferencia

                    printf("Informe o valor que deseja transferir:\n");
                    scanf("%lf", &valorTransferir);
                    getchar(); // Limpa o buffer após a leitura do valor

                    if (valorTransferir > saldo[i]) {
                        printf("Valor excede o saldo disponivel, informe um valor menor ou igual ao saldo.\n");
                        return;
                    }

                    saldo[i] -= valorTransferir;//retira o valor da conta de origem
                    saldo[j] += valorTransferir;//adiciona o valor na conta de destino

                    printf("======= Seu saldo atual: %.2lf =======\n", saldo[i]);// mostra o saldo do usuario ao final da transacao
                    printf("======Transferencia realizada com sucesso======\n");
                    return;
                }
            }
            printf("Cliente com CPF %s nao encontrado.\n", cpfDestino);
            return;
        }
    }

    printf("Cliente com CPF %s nao encontrado.\n", cpfOrigem);
}

//Funcao para depositar na conta de um terceiro
void depositarTerceiro(){
 if (num_clientes < 1) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    
    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o seu CPF da pessoa que voce deseja depositar: \n");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF
    
    double depositar;//declara variavel para ser utilizada no deposito
    
    // Procura o cliente com o CPF fornecido
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("Nome: %s\n", nomes[i]);
            printf("Informe o valor que voce deseja depositar:\n");
            scanf("%lf", &depositar);
            getchar();
        
            saldo[i] += depositar;// reakiza o deposito na conta de destino
            printf("======= Valor do deposito: %.2lf ======\n", depositar);
        }
    }
}
