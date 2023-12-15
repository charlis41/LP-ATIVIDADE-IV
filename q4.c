#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


struct ContaBancaria {
    int numeroConta;
    char nome[200];
    float saldo;
    char tipoConta[200]; 
};


void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("===============================================");
    printf("\nDepósito de R$ %.2f realizado com sucesso!\n", valor);
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("===============================================");
        printf("\nSaque de R$ %.2f realizado com sucesso!\n", valor);
    } else {
    	printf("===============================================");
        printf("\nSaldo insuficiente ou valor inválido para saque!\n");
    }
}


void imprimirSaldo(struct ContaBancaria *conta) {
	printf("===============================================");
    printf("\nSaldo atual: R$ %.2f\n", conta->saldo);
}


int main() {
    
    struct ContaBancaria minhaConta ; 

    int opcao,escolha;
    float valor,numero;
    
  printf("Nome: ");
  gets(minhaConta.nome);
  printf("Número da conta: ");
  scanf("%f",&minhaConta.numeroConta); 
  fflush(stdin);
  
  do{
  
  printf("Tipo de conta\n : ");
  printf("1:Corrente\n : ");
  printf("2:Poupança\n : ");
  scanf("%d",&minhaConta.tipoConta);
  
  switch (escolha) {
  
  	case 1:
	  printf("\nConta Corrente...");
  	 
  	break;
  	case 2:
	  printf("\nConta Poupança...");

  	break;  	
}	
}
while(escolha);



    do {
        printf("\nMenu:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Consultar saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        
       
        switch (opcao) {
            case 1:
                printf("Informe o valor para depósito: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Informe o valor para saque: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(&minhaConta);
                break;
            case 4:
            	printf("===============================================");
                printf("\nSaindo do programa. Até mais!\n");
                break;
            default:
            	printf("===============================================");
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}
