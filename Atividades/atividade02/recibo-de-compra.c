/*-O scanf("%s") lê somente uma palavra, pois para de ler quando encontra um espaço. Para permitir nomes compostos, 
o programa utiliza fgets(), que lê toda a linha, incluindo os espaços.*/


#include<stdio.h>

    char nome_completo[100];  
    char nome_do_produto[100];
    int codigo_do_produto;
    char categoria;
    int quantidade;
    float preco;


    int main(){
        printf("nome completo:");
        fgets(nome_completo, 100, stdin);

        printf("nome do produto:");
        scanf("%s", nome_do_produto);
        
        printf("codigo do produto:");
        scanf("%d", &codigo_do_produto);

        printf("Categorias disponiveis\n");
        printf("A - Papelaria\n");
        printf("B - Farmácia\n");
        printf("C - Alimentação\n");
        printf("Digite a categoria do produto:");
        scanf(" %c", &categoria);


        printf("\nquantidade:");
        scanf("%d", &quantidade);

        printf("\npreco:");
        scanf("%f", &preco);

        float total = preco * quantidade;

        printf("========================\n");
        printf("RECIBO\n");
        printf("========================\n");
        printf("nome completo:%s\n", nome_completo);
        printf("nome do produto:%s\n", nome_do_produto);
        printf("codigo do produto:%d\n", codigo_do_produto);
        printf("categoria:%c\n", categoria);
        printf("quantidade:%d\n", quantidade);
        printf("preco:%.2f\n", preco);
        printf("Total: R$ %.2f\n", total);
        printf("======================\n");

        return 0;
    }

