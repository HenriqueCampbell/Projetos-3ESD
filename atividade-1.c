#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct opiniao {
  char nome[10];
  int idade;
  int vPref[4]; // nota que a pessoa deu
};
typedef struct opiniao tOp;
void ordenarNomes (tOp **vNomes, int tamanho);
void ordenarIdades (tOp **vIdades, int tamanho);
void exibirOrdemOriginal (tOp *vEnt, int tamanho);
void exibirOrdemAlternativa (tOp **v, int tamanho);
void menu (tOp *vEnt, tOp **vNomes, tOp **vIdades, int *tam);
void adicionarEntrevistado(tOp **vEnt, tOp ***vNomes, tOp ***vIdades, int **tam);

void preenche(tOp * p,int i)
{
  char vNomes[10][10]={"ze","ana","joca","melissa","maria","joao","pedro","alissa","oruam","mario"};
  int vIdades[10]={10,22,16,21,14,31,55,67,54,12};
  strcpy(p->nome, vNomes[i]);
  p->idade=vIdades[i];
  for( int j=0;j<3;j++)
    p->vPref[j]=(j+1)* i+3;
  return;  
}

int main() 
{
    tOp vEnt[10];
    tOp * vNomes[10];
    tOp * vIdades[10];

    int i, totalEntrevistados;
    totalEntrevistados = 10;

    for(i=0;i<10;i++)
        preenche(&vEnt[i],i);

        for(i=0; i<10; i++) 
        {
            vNomes[i] = &vEnt[i];
            vIdades[i] = &vEnt[i];
        }

        menu (vEnt, vNomes, vIdades, &totalEntrevistados);

    /* vNomes[0]=&vEnt[1];
    vNomes[1]=&vEnt[2];
    vNomes[2]=&vEnt[0];

    vIdades[0]=&vEnt[0];
    vIdades[1]=&vEnt[2];
    vIdades[2]=&vEnt[1]; */

    return 0;
}

void ordenarIdades (tOp **vIdades, int tamanho)
{
    int i, j;
    tOp *temp;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (vIdades[j]->idade > vIdades[j + 1]->idade)
            {
                temp = vIdades[j];
                vIdades[j] = vIdades[j + 1];
                vIdades[j + 1] = temp;
            }
        }
    }
}

void ordenarNomes (tOp **vNomes, int tamanho)
{
     int i, j;
    tOp *temp;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (strcmp(vNomes[j]->nome, vNomes[j+1]->nome) > 0)
            {
                temp = vNomes[j];
                vNomes[j] = vNomes[j + 1];
                vNomes[j + 1] = temp;
            }
        }
    }
}

void exibirOrdemOriginal (tOp *vEnt, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n Nome: %s \n Idade: %d \n Nota 1: %d \n Nota 2: %d \n Nota 3: %d \n", vEnt[i].nome, vEnt[i].idade, vEnt[i].vPref[0], vEnt[i].vPref[1], vEnt[i].vPref[2]);
    }
}

void exibirOrdemAlternativa (tOp **v, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n Nome: %s \n Idade: %d \n Nota 1: %d \n Nota 2: %d \n Nota 3: %d \n", v[i]->nome, v[i]->idade, v[i]->vPref[0], v[i]->vPref[1], v[i]->vPref[2]);
    }
}

void menu (tOp *vEnt, tOp **vNomes, tOp **vIdades, int *tam)
{
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Exibir ordem original\n");
        printf("2. Exibir ordem por idade\n");
        printf("3. Exibir ordem por nome\n");
        printf("4. Adicionar entrevistado\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirOrdemOriginal(vEnt, *tam);
                break;
            case 2:
                ordenarIdades(vIdades, *tam);
                exibirOrdemAlternativa(vIdades, *tam);
                break;
            case 3:
                ordenarNomes(vNomes, *tam);
                exibirOrdemAlternativa(vNomes, *tam);
                break;
            case 4:
                adicionarEntrevistado(&vEnt, &vNomes, &vIdades, &tam);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
}

// Tem que lembrar que tudo que era 2 ** nas funções anteriores agora tem que ser 3 *** ACHO que porque essa é uma função dentro de uma função dentro da main ou seja inception.

void adicionarEntrevistado(tOp **vEnt, tOp ***vNomes, tOp ***vIdades, int **tam)
{
    tOp *tempEnt = realloc(*vEnt, (*tam + 1) * sizeof(tOp));
    tOp **tempNome = realloc(*vNomes, (*tam + 1) * sizeof(tOp*));
    tOp **tempIdade = realloc(*vIdades, (*tam + 1) * sizeof(tOp*));

    if (vEnt == NULL || vNomes == NULL || vIdades == NULL) {
        printf("Erro ao re-alocar memória.\n");
        return;
    }
    (*tam)++;

    *vEnt = tempEnt;
    *vNomes = tempNome;
    *vIdades = tempIdade;

    printf("Digite o nome do novo entrevistado: ");
    scanf("%s", vEnt[*tam - 1].nome);
    printf("Digite a idade do novo entrevistado: ");
    scanf("%d", &vEnt[*tam - 1].idade);
    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d do novo entrevistado: ", i + 1);
        scanf("%d", &vEnt[*tam - 1].vPref[i]);
    }

    (*vNomes)[*tam] = &((*vEnt)[*tam]);
    (*vIdades)[*tam] = &((*vEnt)[*tam]);

    (*tam)++;

    printf("Entrevistado adicionado com sucesso!\n");
    return;
}
