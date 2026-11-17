
#include <stdio.h>
#include <string.h>

#define MAX 30

enum StatusAluno {
    REPROVADO = 0,
    RECUPERACAO = 1,
    APROVADO = 2
};

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

// Limpa o buffer de entrada
void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Calcula a media do aluno
float calcularMedia(float a1, float a2) {
    return 0.4f * a1 + 0.6f * a2;
}

// Define o status do aluno
enum StatusAluno calcularStatus(float media) {
    if (media >= 5.0f) {
        return APROVADO;
    } else if (media >= 3.0f) {
        return RECUPERACAO;
    } else {
        return REPROVADO;
    }
}

// Converte o status para texto
const char* textoStatus(enum StatusAluno status) {
    switch (status) {
        case APROVADO:
            return "APROVADO";
        case RECUPERACAO:
            return "RECUPERACAO";
        case REPROVADO:
            return "REPROVADO";
        default:
            return "DESCONHECIDO";
    }
}

// Exibe os dados de um aluno
void imprimirAluno(struct Aluno aluno) {
    float media = calcularMedia(aluno.a1, aluno.a2);

    printf("%d | %s | %.2f | %.2f | %.2f | %s\n",
           aluno.matricula,
           aluno.nome,
           aluno.a1,
           aluno.a2,
           media,
           textoStatus(aluno.status));
}

int main() {
    struct Aluno alunos[MAX];

    int quantidade = 0;
    int opcao;

    do {
        printf("\n===== CADASTRO DE TURMAS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar por matricula\n");
        printf("4 - Buscar por nome\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida!\n");
            limparEntrada();
            continue;
        }
        limparEntrada();

        switch (opcao) {

            case 1: {
                if (quantidade >= MAX) {
                    printf("Limite de alunos atingido!\n");
                    break;
                }

                struct Aluno novo;
                int repetida = 0;

                printf("Matricula: ");
                if (scanf("%d", &novo.matricula) != 1) {
                    printf("Matricula invalida!\n");
                    limparEntrada();
                    break;
                }
                limparEntrada();

                // Verifica matricula duplicada
                for (int i = 0; i < quantidade; i++) {
                    if (alunos[i].matricula == novo.matricula) {
                        repetida = 1;
                        break;
                    }
                }

                if (repetida) {
                    printf("Matricula ja cadastrada!\n");
                    break;
                }

                printf("Nome: ");
                if (fgets(novo.nome, sizeof(novo.nome), stdin) == NULL) {
                    printf("Erro ao ler nome!\n");
                    break;
                }

                // Remove a quebra de linha do fgets
                if (strchr(novo.nome, '\n') != NULL) {
                    novo.nome[strcspn(novo.nome, "\n")] = '\0';
                } else {
                    limparEntrada();
                }

                if (strlen(novo.nome) == 0) {
                    printf("Nome invalido!\n");
                    break;
                }

                printf("Nota A1: ");
                if (scanf("%f", &novo.a1) != 1) {
                    printf("Nota invalida!\n");
                    limparEntrada();
                    break;
                }
                limparEntrada();

                printf("Nota A2: ");
                if (scanf("%f", &novo.a2) != 1) {
                    printf("Nota invalida!\n");
                    limparEntrada();
                    break;
                }
                limparEntrada();

                if (!(novo.a1 >= 0 && novo.a1 <= 10 &&
                      novo.a2 >= 0 && novo.a2 <= 10)) {
                    printf("As notas devem estar entre 0 e 10!\n");
                    break;
                }

                float media = calcularMedia(novo.a1, novo.a2);
                novo.status = calcularStatus(media);

                alunos[quantidade] = novo;
                quantidade++;

                printf("Aluno cadastrado com sucesso!\n");
                break;
            }

            case 2: {
                if (quantidade == 0) {
                    printf("Nenhum aluno cadastrado!\n");
                    break;
                }

                printf("\nMatricula | Nome | A1 | A2 | Media | Status\n");
                printf("-----------------------------------------------\n");

                for (int i = 0; i < quantidade; i++) {
                    imprimirAluno(alunos[i]);
                }

                break;
            }

            case 3: {
                int matriculaBusca;
                int encontrado = 0;

                printf("Digite a matricula: ");
                if (scanf("%d", &matriculaBusca) != 1) {
                    printf("Matricula invalida!\n");
                    limparEntrada();
                    break;
                }
                limparEntrada();

                for (int i = 0; i < quantidade; i++) {
                    if (alunos[i].matricula == matriculaBusca) {
                        printf("\nAluno encontrado:\n");
                        printf("Matricula | Nome | A1 | A2 | Media | Status\n");
                        imprimirAluno(alunos[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Aluno nao encontrado!\n");
                }

                break;
            }

            case 4: {
                char trecho[41];
                int encontrado = 0;

                printf("Digite parte do nome: ");
                if (fgets(trecho, sizeof(trecho), stdin) == NULL) {
                    printf("Erro ao ler nome!\n");
                    break;
                }

                if (strchr(trecho, '\n') != NULL) {
                    trecho[strcspn(trecho, "\n")] = '\0';
                } else {
                    limparEntrada();
                }

                if (strlen(trecho) == 0) {
                    printf("Digite um trecho valido!\n");
                    break;
                }

                printf("\nResultados da busca:\n");

                for (int i = 0; i < quantidade; i++) {
                    if (strstr(alunos[i].nome, trecho) != NULL) {
                        imprimirAluno(alunos[i]);
                        encontrado = 1;
                    }
                }

                if (!encontrado) {
                    printf("Nenhum aluno encontrado!\n");
                }

                break;
            }

            case 5: {
                if (quantidade == 0) {
                    printf("Nenhum aluno cadastrado!\n");
                    break;
                }

                int aprovados = 0;
                int recuperacao = 0;
                int reprovados = 0;
                float somaMedias = 0;

                for (int i = 0; i < quantidade; i++) {
                    float media = calcularMedia(
                        alunos[i].a1, alunos[i].a2
                    );

                    somaMedias += media;

                    switch (alunos[i].status) {
                        case APROVADO:
                            aprovados++;
                            break;
                        case RECUPERACAO:
                            recuperacao++;
                            break;
                        case REPROVADO:
                            reprovados++;
                            break;
                    }
                }

                float mediaGeral = somaMedias / quantidade;

                printf("\n===== ESTATISTICAS =====\n");
                printf("Total de alunos: %d\n", quantidade);
                printf("Aprovados: %d\n", aprovados);
                printf("Recuperacao: %d\n", recuperacao);
                printf("Reprovados: %d\n", reprovados);
                printf("Media geral da turma: %.2f\n", mediaGeral);

                break;
            }

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
