// Nome: Matheus Peixoto Menezes
// Nome: Manuelle Felix da Silva
#include "TAD_Peso.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
/* cria uma medida de peso em kg e g*/
struct peso {
  int kg, g;
};
/* funções auxiliares */
int converteParag(Peso *p) { return p->kg * 1000 + p->g; }
/* Funções exportadas */
/* Função cria - Aloca e retorna um peso (kg e g) */
Peso *peso_cria(int kg, int g) {
  Peso *p = (Peso *)malloc(sizeof(Peso));
  if (p == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  p->kg = kg;
  p->g = g;
  return p;
}
/* Função libera - Libera a memória de um peso previamente criado */
void peso_libera(Peso *p) { free(p); }

/* Função acessa - Retorna os valores de um peso */
void peso_acessa(Peso *p, int *kg, int *g) {
  *kg = p->kg;
  *g = p->g;
}
/* Função atribui - Atribui novos valores às partes de um peso */
void peso_atribui(Peso *p, int kg, int g) {
  p->kg = kg;
  p->g = g;
}
/* Função exibe -Escreve na tela o peso  no formato  kg,g */

void peso_exibe(Peso *p) { printf("\n %d,%03dkg", p->kg, p->g); }

/* Função getPeso- Retorna uma string com os valores do PESO  no formato
 * kg,g*/
char *peso_getPeso(Peso *p) {
  char *pt;
  int tam = sizeof(*p) + 5;
  pt = (char *)malloc(tam);
  sprintf(pt, "%d,%03dkg", p->kg, p->g);
  return pt;
}


int peso_compara(Peso *p1, Peso *p2) {
  int a1 = converteParag(p1);
  int a2 = converteParag(p2);
  int dif = a1 - a2;
  return dif;
}


Peso *peso_soma(Peso *p, int g) {
  int total_g = converteParag(p) + g;
  int novos_kg = total_g / 1000;
  int novos_gramas = total_g % 1000;
  return peso_cria(novos_kg, novos_gramas);
}

Peso *peso_copia(Peso *p) {
  if (p == NULL) {
    return NULL;
  }
  return peso_cria(p->kg, p->g);
}