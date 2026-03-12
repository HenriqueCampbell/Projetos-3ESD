#include <string.h>
#include <stdio.h>

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

  for(int i=0;i<10;i++)
    preenche(&vEnt[i],i);

    for(int i=0; i<10; i++) 
    {
        vNomes[i] = &vEnt[i];
        vIdades[i] = &vEnt[i];
    }

    ordenarIdades (vIdades, 10);
    exibirEntrevistados (vIdades, 10);
    ordenarNomes (vNomes, 10);
    exibirEntrevistados (vNomes, 10);
    exibirOrdemOriginal (vEnt, 10);

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

