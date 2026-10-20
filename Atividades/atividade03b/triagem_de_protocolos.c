#include <stdio.h>
int codigo;
char prioridade_de_atendimento;
const char *nome_prioridade;
int dia_da_semana;
const char *nome_dia;
const char *expediente;
int indice_servico = 0;
const char *servico[] = {
    
    "Codigo invalido",
    "Historico escolar",
    "Declaracao de matricula",
    "Declaracao de vinculo",
    "Trancamento",
    "Cancelamento",
    "Colacao de grau"
};

const char *categoria;
const char *status;
int prazo;
int taxa_base;
int guiche;
int acrescimo;
int taxa_final;


int main () {
    printf ("Codigo de servico:");
    scanf ("%d", &codigo);

    switch (codigo) {
        case 1:
         /* fall through */
        case 2:
         /*fall through */
        case 3:
         indice_servico = codigo;
         categoria = "Documento simples";
         prazo = 2;
         taxa_base = 15.00;
         status = "ACEITO";
         break;

        case 4:
         /* fall through */
        case 5:
         indice_servico = codigo;
         categoria = "Interrupcao de vinculo";
         prazo = 10;
         taxa_base = 0.00;
         status = "ACEITO";
         break;

        case 6:
         indice_servico = codigo;
         categoria = "Ato solene";
         prazo = 15;
         taxa_base = 80.00;
         status = "ACEITO";
         break;

        default:
         indice_servico = 0;
         categoria ="--";
         prazo = 0;
         taxa_base = 0.00;
         status = "RECUSADO";
    }
    printf("\nDigite a prioridade de atendimento (U, N, B): ");
    scanf(" %c", &prioridade_de_atendimento);
    switch(prioridade_de_atendimento){
        case 'U':
         /* fall through */
        case 'u':
         nome_prioridade = "Urgente";
         guiche = 1;
         acrescimo = 10.00;
         break;
        case 'N':
         /* fall through */
        case 'n':
         nome_prioridade = "Normal";
         guiche = 2;
         acrescimo = 0.00;
         break;
        case 'B':
         /* fall through */
        case 'b':
         nome_prioridade = "Balcao";
         guiche = 3;
         acrescimo = 0.00;
         break;
        default:
         nome_prioridade = "Invalido";
         guiche = 0;
         acrescimo = 0.00;
         break;
         
    }

    printf("\nDia da semana (1-7): ");
    scanf("%d", &dia_da_semana);

    switch (dia_da_semana){
        case 1:
         nome_dia = "Domingo";
         break;
        case 2 :
         nome_dia = "Segunda feira";
         break;
        case 3 :
         nome_dia = "Terca feira";
         break;
        case 4 :
         nome_dia = "Quarta feira";
         break;
        case 5 :
         nome_dia = "Quinta feira";
         break;
        case 6:
         nome_dia = "Sexta feira";
         break;
        case 7 :
         nome_dia = "Sabado";
         break;
        default:
         nome_dia = "Dia invalido";
         break;

    }

    switch (dia_da_semana) {
        case 2:
         /* fall through */
        case 3:
         /* fall through */
        case 4: 
         /* fall through */
        case 5:
         expediente = "Pleno";
         break;
        case 6:
         expediente = "Reduzido";
         break;
        case 1: 
         /* fall through */
        case 7:
         expediente = "Fechado";
         break;
        default:
         expediente = "Dia invalido";
         break;
    }

    taxa_final = taxa_base + acrescimo;
    
    printf ("\n==========================");
    printf ("\nTRIAGEM DE PROTOCOLO\n");
    printf ("==========================\n");
    printf ("Servico: %s\n", servico[indice_servico]);
    printf ("Categoria: %s\n", categoria);
    printf ("Prazo: %d dias uteis\n", prazo);
    printf ("Taxa base: R$ %.2f\n", (double)taxa_base);
    printf ("Prioridade: %s\n", nome_prioridade);
    printf ("Guiche: %d\n", guiche);
    printf ("Acrescimo: R$ %d\n", acrescimo);
    printf ("Dia: %s\n", nome_dia);
    printf ("Expediente: %s\n", expediente);
    printf ("---------------------------------");
    printf ("\nTaxa final: R$ %d\n", taxa_final);
    printf ("Status do servico: %s\n", status);
    printf ("==========================");

    return 0;
}