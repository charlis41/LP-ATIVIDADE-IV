#include <stdio.h>


struct Produto {
    char nome[200];
    float preco;
    int quantidade;
};


float calcularTotal(struct Produto *produto) {
    return produto->preco * produto->quantidade;
}


void realizarCompra(struct Produto *produto) {
    int quantidadeCompra;
    printf("Informe a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidade) {
        produto->quantidade -= quantidadeCompra;
        printf("===============================================");
        printf("\nCompra realizada com sucesso!\n");
    } else {
        printf("\nQuantidade inv�lida. Verifique o estoque.\n");
    }
}


int main() {
    
    struct Produto meuProduto = {"Amora", 1.0, 50};

    int opcao;
    printf("\nAMORA "); 
    printf("\nPre�o unitrario: R$:1,00 ");
    printf("\nEstoque dispon�vel: 50 unidades\n");
    
    
    do {
        
        printf("\nMenu:\n");
        printf("1. Realizar uma compra\n");
        printf("2. Consultar estoque\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

       
        switch (opcao) {
            case 1:
                realizarCompra(&meuProduto);
                break;
            case 2:
                printf("Estoque dispon�vel: %d unidades\n", meuProduto.quantidade);
                printf("Valor total em estoque: R$ %.2f\n", calcularTotal(&meuProduto));
                break;
            case 3:
                printf("Saindo do programa. At� mais!\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
