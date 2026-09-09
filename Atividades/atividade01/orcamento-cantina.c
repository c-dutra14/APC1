#include <stdio.h>

#define valor_refeicao 12.50
#define valor_cafe 4.00

int main(){
    int refeicoes, cafes;
    float valor_disponivel_cartao;
    
   
    printf("quantidade de refeicoes da semana: ");
    scanf("%d", &refeicoes);

    printf("quantidade de cafes da semana: ");
    scanf("%d", &cafes);

    printf("valor disponivel no cartao: ");
    scanf("%f", &valor_disponivel_cartao);

    float gasto_refeicoes = refeicoes * valor_refeicao;
    float gasto_cafes = cafes * valor_cafe;
    float gasto_total = gasto_refeicoes + gasto_cafes;
    float saldo_restante = valor_disponivel_cartao - gasto_total;

    printf("gasto com refeicoes: R$ %.2f\n", gasto_refeicoes);
    printf("gasto com cafes: R$ %.2f\n", gasto_cafes);
    printf("gasto total: R$ %.2f\n", gasto_total);
    printf("valor disponivel no cartao: R$ %.2f\n", saldo_restante);

    return 0;
}