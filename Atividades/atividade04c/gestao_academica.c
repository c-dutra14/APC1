
/*
ATIVIDADE PRATICA 04C - VETORES E MATRIZES EM C

Em char nome[50], podemos armazenar no maximo 49 caracteres
uteis, pois a ultima posicao e reservada para o caractere
nulo '\0', que indica o final de uma string em C.
Em int M[3][4], o primeiro indice representa a linha
e o segundo indice representa a coluna da matriz.
A linguagem C armazena os elementos em memoria contigua,
organizados por linhas, uma apos a outra.
*/

#include <stdio.h>
#include <string.h>

int main(void) {

    int opcao;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos\n");
        printf("2 - Estatisticas de Desempenho\n");
        printf("3 - Matriz de Notas da Turma\n");
        printf("4 - Consultar Aluno em Destaque\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }

            opcao = -1;
            continue;
        }

        switch (opcao) {

            case 1: {
                char alunos[5][50];

                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                }

                printf("\n===== CADASTRO DE ALUNOS =====\n");

                for (int i = 0; i < 5; i++) {
                    printf("Digite o nome do aluno %d: ", i + 1);

                    if (fgets(alunos[i], sizeof(alunos[i]), stdin) == NULL) {
                        return 1;
                    }

                    alunos[i][strcspn(alunos[i], "\n")] = '\0';
                }

                printf("\n===== LISTA DE ALUNOS =====\n");

                for (int i = 0; i < 5; i++) {
                    printf("%d - %s\n", i + 1, alunos[i]);
                }

                break;
            }

            case 2: {
                float notas_finais[5];
                float soma = 0;
                float media;
                int quantidade = 0;

                printf("\n===== ESTATISTICAS DE DESEMPENHO =====\n");

                for (int i = 0; i < 5; i++) {
                    printf("Digite a nota do aluno %d: ", i + 1);
                    if (scanf("%f", &notas_finais[i]) != 1) {
                        printf("Nota invalida!\n");
                        return 1;
                    }
                }

                for (int i = 0; i < 5; i++) {
                    soma += notas_finais[i];
                }

                media = soma / 5;

                for (int i = 0; i < 5; i++) {
                    if (notas_finais[i] >= media) {
                        quantidade++;
                    }
                }

                printf("\nMedia geral da turma: %.2f\n", media);
                printf("Alunos com nota maior ou igual a media: %d\n",
                       quantidade);

                break;
            }

            case 3: {
                float boletim[3][4];

                printf("\n===== MATRIZ DE NOTAS DA TURMA =====\n");

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 4; j++) {
                        printf("Aluno %d - Bimestre %d: ", i + 1, j + 1);

                        if (scanf("%f", &boletim[i][j]) != 1) {
                            printf("Nota invalida!\n");
                            return 1;
                        }
                    }
                }

                printf("\nAluno\tB1\tB2\tB3\tB4\tMedia\n");

                for (int i = 0; i < 3; i++) {
                    float soma = 0;

                    printf("%d\t", i + 1);

                    for (int j = 0; j < 4; j++) {
                        printf("%.2f\t", boletim[i][j]);
                        soma += boletim[i][j];
                    }

                    printf("%.2f\n", soma / 4);
                }

                break;
            }

            case 4: {
                float notas[5];
                float maior;
                int indice = 0;

                printf("\n===== CONSULTAR ALUNO EM DESTAQUE =====\n");

                for (int i = 0; i < 5; i++) {
                    printf("Digite a nota do aluno %d: ", i + 1);

                    if (scanf("%f", &notas[i]) != 1) {
                        printf("Nota invalida!\n");
                        return 1;
                    }
                }

                maior = notas[0];

                for (int i = 1; i < 5; i++) {
                    if (notas[i] > maior) {
                        maior = notas[i];
                        indice = i;
                    }
                }

                printf("\nMaior nota da turma: %.2f\n", maior);
                printf("Indice encontrado: %d\n", indice);
                printf("Posicao do aluno: %d\n", indice + 1);

                break;
            }

            case 0:
                printf("\nSistema encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
