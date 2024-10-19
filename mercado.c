#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUTOS 50



typedef struct{
    char nome[50];
    int quant;
    float preco;
} Produto;

Produto p[MAX_PRODUTOS];
int totalprod = 0; 

void menu();
void adprod();
void remoprod();
void exibirprod();
void attprod();
void finaprod();

int main()
{
    menu();
    return 0;
}

void menu(){
    int op;

    do{
        system("cls");
        printf("-----SUPERMARKATON-----\n\n");
        printf("1. Adicionar Produto\n");
        printf("2. Remover Produto\n");
        printf("3. Exibir Carrinho\n");
        printf("4. Atualizar produto\n");
        printf("5. Finalizar compra\n");
        printf("6. Pesquisar Produto\n");
        printf("7. Sair\n");
        printf("O que deseja para hoje? ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                adprod();
                break;
            case 2:
                remoprod();
                break;
            case 3:
                exibirprod();
                break;
            case 4:
                attprod();
                break;
            case 5:
                finaprod();
                break;
                case 6:
                pesqprod();
                break;
            case 7:
                printf("Saindo do sistema... Até logo!\n");
                break;
            default:
                printf("Ops! Não reconhecemos...\n");
        }
        getchar();
    } while(op != 7);
}

void adprod(){
    char nome[50];
    int quant;
    float preco;
    int op;

    if (totalprod < MAX_PRODUTOS) {
        system("cls");
        printf("Digite o nome do produto: ");
        fflush(stdin);
        fgets(p[totalprod].nome, sizeof(p[totalprod].nome), stdin);
        p[totalprod].nome[strcspn(p[totalprod].nome, "\n")] = '\0';

        printf("Digite a quantidade do produto: ");
        scanf("%d", &p[totalprod].quant);

        printf("Digite o preço do produto: ");
        scanf("%f", &p[totalprod].preco);

        totalprod++;
    } else {
        printf("Carrinho cheio!\n");
    }
    
    printf("\nProduto adicionado! Pressione qualquer tecla para voltar ao menu.");
    getchar();
}

void exibirprod(){
    system("cls");
    printf("\n---- Seu Carrinho ----\n\n");
    
    if (totalprod == 0) {
        printf("Seu carrinho está vazio.\n");
    } else {
        for (int i = 0; i < totalprod; i++) {
            printf("Produto: %s - Quantidade: %d - Preço: R$%.2f\n", p[i].nome, p[i].quant, p[i].preco, i+1);
            printf("\n-------------------------------------------------------------\n");
        }
    }

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();
}

void remoprod(){
    int prod;
    
    if (totalprod == 0) {
        printf("O carrinho está vazio. Não há produtos para remover.\n");
        getchar();
        getchar();
        return;
    }

    exibirprod(); 

    printf("Digite o número do produto que deseja remover: ");
    scanf("%d", &prod);

    if (prod < 1 || prod > totalprod) {
        printf("Número de produto inválido!\n");
        getchar();
        getchar();
        return;
    }

    prod--;

    for (int i = prod; i < totalprod - 1; i++) {
        p[i] = p[i + 1];
    }

    totalprod--;
    printf("Produto removido com sucesso!\n");

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
}

void pesqprod() {
    system("cls");  
    char nome[50];
    int encontrado = 0;  
    int op;

    printf("Digite o nome do produto que deseja pesquisar: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  

    
    for (int i = 0; i < totalprod; i++) {
        if (strcmp(p[i].nome, nome) == 0) {
            printf("O produto %s já existe no carrinho!\n", p[i].nome);
            encontrado = 1; 
            break;  
        }
    }

    if (!encontrado) {
        printf("O produto %s não foi encontrado no carrinho.\n", nome);
    }

   
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();
    
}

void attprod() {
    if (totalprod == 0) {
        printf("Desculpe, o carrinho está vazio! Não há produtos para atualizar.\n");
        getchar();
        return;
    }

    exibirprod();

    int produ;
    printf("Digite o número do produto que deseja atualizar: ");
    scanf("%d", &produ);

  
    if (produ > 0 && produ <= totalprod) {
      
        Produto *prod_atual = &p[produ - 1];

        printf("Atualizando o produto: %s\n", prod_atual->nome);

    
        printf("Digite a nova quantidade: ");
        scanf("%d", &prod_atual->quant);

        printf("Digite o novo preço: ");
        scanf("%f", &prod_atual->preco);

        printf("Produto atualizado com sucesso!\n");
    } else {
        printf("Número de produto inválido! Tente novamente.\n");
    }

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar(); 
    getchar();  
}


void finaprod() {
    if (totalprod == 0) {
        printf("Seu carrinho está vazio. Não há compras para finalizar.\n");
        getchar(); 
        return;
    }

    float total = 0;
    printf("\n---- Finalizando a Compra ----\n\n");

    for (int i = 0; i < totalprod; i++) {
        total += p[i].quant * p[i].preco;
        printf("Produto: %s - Quantidade: %d - Preco: R$%.2f - Total: R$%.2f\n",
               p[i].nome, p[i].quant, p[i].preco, p[i].quant * p[i].preco);
    }

printf("\n--------------------------------------\n");
    printf("\nTotal a pagar: R$%.2f\n", total);

   
    printf("Obrigado por comprar conosco! Volte sempre.\n");

    
    totalprod = 0;  

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();  
}
