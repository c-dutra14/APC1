#include <stdio.h>

/*
O menu utiliza do-while para garantir que apareca pelo menos uma vez.
A condicao e verificada somente depois da primeira execucao.
Na opcao 1, o continue ignora as senhas negativas.
Assim, essas senhas nao sao contabilizadas como atendidas ou pares.
Na opcao 4, o break encerra a busca quando encontra a prioridade ou zero.
Sem o break, o programa continuaria solicitando novas senhas.
Isso impediria o encerramento correto da busca.
*/


int main(){
 int opcao;
 int senha;
 int atendidas;
 int ignoradas;
 int pares;
 int inicio;
 int fim;
 int passo;
 int i;
 int chamadas;
 int guiches;
 int senhas;
 int g;
 int s;
 int lidas;

 do {

  printf("\n===== PAINEL DE SENHAS =====\n");
  printf("1 - Registrar lote\n");
  printf("2 - Simular chamadas\n");
  printf("3 - Grade de guiches\n");
  printf("4 - Buscar senha prioritaria\n");
  printf("0 - Encerrar\n");
  printf("Opcao: ");
  scanf("%d", &opcao);

   switch (opcao) {

     // OPCAO 1 - REGISTRAR LOTE
     case 1:

      atendidas = 0;
      ignoradas = 0;
      pares = 0;

       printf("Senha: ");
       scanf("%d", &senha);

        while (senha != 0) {
         if (senha < 0) {
           ignoradas++;

           printf("Senha: ");
           scanf("%d", &senha);

            continue;
        }
        atendidas++;

        if (senha % 2 == 0) {
            pares++;
                    }

        printf("Senha: ");
        scanf("%d", &senha);
     }

     printf("Atendidas : %d\n", atendidas);
     printf("Ignoradas : %d\n", ignoradas);
     printf("Pares : %d\n", pares);

    break;

    // OPCAO 2 - SIMULAR CHAMADAS
    case 2:
     printf("Inicio: ");
     scanf("%d", &inicio);

     printf("Fim: ");
     scanf("%d", &fim);

     printf("Passo: ");
     scanf("%d", &passo);

     if (passo == 0) {
        printf("Passo invalido\n");

     } else {
        chamadas = 0;
        printf("Chamadas:");

        if (passo > 0) {

         for (i = inicio; i <= fim; i += passo) {
         printf(" %d", i);
         chamadas++;
        }
     } else {

        for (i = inicio; i >= fim; i += passo) {
         printf(" %d", i);
         chamadas++;
        }
     }

     if (chamadas == 0) {
       printf(" Nenhuma chamada");
     }
     printf("\n");
     }
     break;

     // OPCAO 3 - GRADE DE GUICHES
     case 3:
      printf("Guiches (1 a 4): ");
      scanf("%d", &guiches);

      printf("Senhas por guiche (1 a 5): ");
      scanf("%d", &senhas);

      if (guiches < 1 || guiches > 4 ||
         senhas < 1 || senhas > 5) {
         printf("Grade invalida\n");

      } else {
         for (g = 1; g <= guiches; g++) {
             printf("Guiche %d:", g);

             for (s = 1; s <= senhas; s++) {
                 printf(" %d", s);
                }
             printf("\n");
          }
     }
     break;

    // OPCAO 4 - BUSCAR SENHA PRIORITARIA
    case 4:
      lidas = 0;
      for (;;) {
       printf("Senha: ");
       scanf("%d", &senha);

       if (senha == 0) {
         printf("Nao encontrada\n");
         printf("Lidas : %d\n", lidas);
         break;
        }
        if (senha > 0 && senha % 10 == 0) {
         printf("Prioritaria : %d\n", senha);
         printf("Lidas antes : %d\n", lidas);
         break;
        }
        lidas++;
      }
      break;

    // OPCAO 0 - ENCERRAR
    case 0:
       break;

     // OPCAO INVALIDA
     default:
       printf("Opcao invalida\n");
       break;
    }

} while (opcao != 0);

printf("Painel encerrado.\n");

return 0;
}