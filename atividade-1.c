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
void menu (tOp *vEnt, tOp **vNomes, tOp **vIdades, int *tam); //(tOp *vEnt, tOp **vNomes, tOp **vIdades, int *tam)
void adicionarEntrevistado(tOp **vEnt, tOp ***vNomes, tOp ***vIdades, int *tam); //  3 * porque é uma função que recebe os ponteiros de ponteiros ... enfim inception.

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

    //tOp *vEnt = malloc(totalEntrevistados * sizeof(tOp));
    //tOp **vNomes = malloc(totalEntrevistados * sizeof(tOp*));
    //tOp **vIdades = malloc(totalEntrevistados * sizeof(tOp*));

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
        printf("Escolha uma opçaoo: ");
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
                //adicionarEntrevistado(&vEnt, &vNomes, &vIdades, &tam);
                printf("Função de adicionar entrevistado nao foi implementada.\n");
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opçao inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
}

void adicionarEntrevistado(tOp **vEnt, tOp ***vNomes, tOp ***vIdades, int *tam)
{
    /* Não consigo cumprir este desafio de adicionar um entrevistando usando memória dinâmica.
    
    //O tempEnt do realloc vai diminuir uma * dos asteriscos que foram subindo por causa da função recebendo os ponteiros de ponteiros de ponteiros... Muita indexação, mas é isso mesmo.

    tOp *tempEnt = realloc(*vEnt, (*tam + 1) * sizeof(tOp));
    tOp **tempNome = realloc(*vNomes, (*tam + 1) * sizeof(tOp*));
    tOp **tempIdade = realloc(*vIdades, (*tam + 1) * sizeof(tOp*));

    if (tempEnt == NULL || tempNome == NULL || tempIdade == NULL) {
        printf("Erro ao re-alocar memória.\n");
        return;
    }

    // Atualiza os ponteiros na main
    *vEnt = tempEnt;
    *vNomes = tempNome;
    *vIdades = tempIdade;

    // Tem que usar o *tam como contador, ele ainda está apontando para a última posição válida para realizar a inserção.
    printf("Digite o nome do novo entrevistado: ");
    scanf("%s", (*vEnt)[*tam].nome); 
    
    printf("Digite a idade do novo entrevistado: ");
    scanf("%d", &((*vEnt)[*tam].idade));

    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%d", &((*vEnt)[*tam].vPref[i]));
    }

    // Atualiza os ponteiros para o novo entrevistado
    (*vNomes)[*tam] = &((*vEnt)[*tam]);
    (*vIdades)[*tam] = &((*vEnt)[*tam]);

    (*tam)++; 

    printf("Entrevistado adicionado com sucesso!\n");

    */
}