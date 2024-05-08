#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char tipo[50];
    double preco;
} Ingresso;

typedef struct {
    char nome[50];
    char cpf[12];
    int numeroBilhete;
} Cliente;

void mostrarIngressos(Ingresso ingressos[], int tamanho) {
    printf("Ingressos disponiveis:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d\n", ingressos[i].id);
        printf("Tipo: %s\n", ingressos[i].tipo);
        printf("Preco: R$%.2lf\n", ingressos[i].preco);
        printf("\n");
    }
}

void venderIngresso(Ingresso ingressos[], int tamanho) {
    int id;
    printf("Digite o ID do ingresso que deseja comprar: ");
    scanf_s("%d", &id);

    if (id >= 1 && id <= tamanho) {
        srand(time(NULL));
        Cliente cliente;
        FILE* arquivo;

        fopen_s(&arquivo, "bilhetes.csv", "a+");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo de bilhetes.\n");
            return;
        }

        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]s", cliente.nome);

        printf("Digite o CPF do cliente: ");
        scanf("%s", cliente.cpf);

        cliente.numeroBilhete = rand() % 1000;

        fprintf(arquivo, "Nome: %s\n", cliente.nome);
        fprintf(arquivo, "CPF: %s\n", cliente.cpf);
        fprintf(arquivo, "Número de Bilhete: %d\n\n", cliente.numeroBilhete);
        fprintf(arquivo, "Tipo de Ingresso: %s\n", ingressos[id - 1].tipo);
        fprintf(arquivo, "ID do Ingresso Adquirido: %d\n\n", ingressos[id - 1].id);

        fclose(arquivo);
        printf("Bilhete registrado com sucesso!\n");
        printf("Seu numero de bilhete e: %d\n", cliente.numeroBilhete);
        printf("Ingresso comprado com sucesso:\n");
        printf("Tipo: %s\n", ingressos[id - 1].tipo);
        printf("Preco: R$%.2lf\n", ingressos[id - 1].preco);
    }
    else {
        printf("ID de ingresso invalido.\n");
    }
}

int main() {
    Ingresso ingressos[] = {
        {1, "Ingresso Normal", 10.0},
        {2, "Ingresso Estudante", 7.0},
        {3, "Ingresso Crianca", 5.0},
    };

    int tamanho = sizeof(ingressos) / sizeof(ingressos[0]);
    int escolha;

    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n *         Ola, bem vindo a bilheteria do museu PIM!     *\n");
    printf(" *Classificacao: Livre \t                                 *\n");
    printf(" *                                                       *\n");
    printf(" *                 EM CARTAZ:                            *\n");
    printf(" * 150 anos de Santos Dumont.                            *\n");
    printf(" * 100 Anos da semana da arte moderna.                   *\n");
    printf(" * Jogos olimpicos de Paris 2024.                        *\n");
    printf(" * Exploracao espacial futuristica.                      *\n ");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n \t\t Escolha uma das opcoes abaixo \n\n");
    printf("\t\t\t  %c%c%c%c\n \n", 25, 25, 25, 25);

    do {
        printf(" %c 1. Mostrar Ingressos Disponiveis\n", 175);
        printf(" %c 2. Comprar Ingresso\n", 175);
        printf(" %c 3. Sair\n", 175);
        printf("Escolha uma opcao: ");
        if (scanf_s("%d", &escolha) != 1) {
            printf("Por favor, digite um numero valido.\n");
            while (getchar() != '\n');
            continue;
        }

        //system("cls");
        switch (escolha) {
        case 1:
            mostrarIngressos(ingressos, tamanho);
            break;
        case 2:
            venderIngresso(ingressos, tamanho);
            break;
        case 3:
            printf("Obrigado por usar o sistema de bilheteria.\n");
            return 0;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
        system("pause");
    } while (escolha != 3);

    return 0;
}