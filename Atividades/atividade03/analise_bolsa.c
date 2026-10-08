/*
O operador ternario foi mais vantajoso no calculo do bonus de pontualidade.
Se o pagamento estiver em dia ('S'), o bonus recebe 5%; caso contrario, recebe 0%.
Como existem apenas dois valores possiveis, ele deixa o codigo mais curto e simples.
O if aninhado foi necessario para analisar o desconto dentro de cada faixa social.
Primeiro, o programa verifica a faixa de renda do aluno.
Depois, verifica a media academica para definir o desconto daquela faixa.
*/

#include <stdio.h>

char nome_completo[100];
int idade;
float renda_familiar_mensal;
float media_academica;
char status_da_pontualidade_pagamento;
float bonus_de_pontualidade;
float desconto_base;
float desconto_total;
char faixa_social;

int main(void) {
    printf("Nome completo: ");
    fgets(nome_completo, 100, stdin);

    printf("Idade do aluno: ");
    scanf("%d", &idade);

    if (idade < 16) {
        printf("Erro: Idade invalida.\n");
        return 1;
    }

    printf("Renda Familiar Mensal: R$ ");
    scanf("%f", &renda_familiar_mensal);

    if (renda_familiar_mensal <= 0) {
        printf("Erro: Renda invalida.\n");
        return 1;
    } else if (renda_familiar_mensal <= 2000) {
        faixa_social = 'A';
    } else if (renda_familiar_mensal <= 5000) {
        faixa_social = 'B';
    } else {
        faixa_social = 'C';
    }

    printf("Media Academica: ");
    scanf("%f", &media_academica);

    if (media_academica < 0 || media_academica > 10) {
        printf("Erro: Media academica invalida.\n");
        return 1;
    }

    if (faixa_social == 'A') {
        if (media_academica >= 8.5) {
            desconto_base = 50.0f;
        } else {
            desconto_base = 30.0f;
        }
    } else if (faixa_social == 'B') {
        if (media_academica >= 9.0) {
            desconto_base = 25.0f;
        } else {
            desconto_base = 10.0f;
        }
    } else {
        if (media_academica >= 9.5) {
            desconto_base = 10.0f;
        } else {
            desconto_base = 0.0f;
        }
    }

    printf("Pagamento em dia: (S/N) ");
    scanf(" %c", &status_da_pontualidade_pagamento);

    if (status_da_pontualidade_pagamento == 'S') {
        printf("Pagamento em dia\n");
    } else if (status_da_pontualidade_pagamento == 'N') {
        printf("Pagamento atrasado\n");
    } else {
        printf("Erro: Status de pagamento invalido.\n");
        return 1;
    }

    bonus_de_pontualidade =
        (status_da_pontualidade_pagamento == 'S') ? 5.0f : 0.0f;

    desconto_total = desconto_base + bonus_de_pontualidade;

    printf("\n========================================\n");
    printf("    SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno         : %s", nome_completo);
    printf("Faixa Social  : Faixa %c\n", faixa_social);
    printf("Media         : %.2f\n", media_academica);
    printf("Desconto Base : %.1f%%\n", desconto_base);
    printf("Bonus Pontual : %.1f%%\n", bonus_de_pontualidade);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", desconto_total);

    if (desconto_total > 0) {
        printf("Status        : APROVADO PARA BOLSA\n");
    } else {
        printf("Status        : NAO APROVADO PARA BOLSA\n");
    }

    printf("========================================\n");

    return 0;
}