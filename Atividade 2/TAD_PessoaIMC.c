// Nome: Matheus Peixoto Menezes
// Nome: Manuelle Felix da Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_PessoaIMC.h"

/* Tipo exportado */
/* cria a medida do Indice de Massa Corporal */
struct pessoaIMC {
    char *nome;
    Altura *altura;
    Peso *peso;
};

/* Função cria - Aloca e retorna um IMC (altura e peso) */
IMC *imc_cria(char *nome, Altura *alt, Peso *peso) {
  IMC *p = (IMC *)malloc(sizeof(IMC));
  if (p == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  
  p->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
  if (p->nome == NULL) {
    exit(1);
  }
  strcpy(p->nome, nome);

  p->altura = alt;
  p->peso = peso;
  return p;
}

/* Função altera peso - Altera o peso de um IMC */
void imc_alteraPeso(IMC *p, Peso *g) {
  Peso *novo_peso = peso_soma(p->peso, g);
  peso_libera(p->peso);
  p->peso = novo_peso;
}

/* Função altera altura - Altera a altura de um IMC */
void imc_alteraAltura(IMC *p, Altura *cm) {
  Altura *nova_altura = alt_soma(p->altura, cm);
  alt_libera(p->altura);
  p->altura = nova_altura;
}

/* Função libera - Libera a memória de um IMC previamente criado */
void imc_libera(IMC *p) {
    alt_libera(p->altura);
    peso_libera(p->peso);
    free(p->nome);
    free(p);
}

/* Função acessa - Retorna os valores de um IMC */
void imc_acessa(IMC *p, char **nome, Altura **alt, Peso **peso) {
    *nome = p->nome;
    *alt = p->altura;
    *peso = p->peso;
}

void imc_exibe(IMC* p) {
    printf("Nome: %s\n", p->nome);
    alt_exibe(p->altura);
    peso_exibe(p->peso);
}

/* Função getIMC- Retorna uma string com os valores do IMC no formato kg/m² */
char *imc_getIMC(IMC *p) {
    float valor = imc_calculaIMC(p);
    char *pt = (char *) malloc(30 * sizeof(char));
    if (pt == NULL) exit(1);

    sprintf(pt, "%.2fkg/m²", valor);
    return pt;
}

int imc_compara(IMC *p1, IMC *p2) {
    float imc1 = imc_calculaIMC(p1);
    float imc2 = imc_calculaIMC(p2);
    if (imc1 < imc2) {
        return -1;
    } else if (imc1 > imc2) {
        return 1;
    } else {
        return 0;
    }
}

IMC *imc_copia(IMC *p) {
    if (p == NULL) {
        return NULL;
    }
    else if (p->nome == NULL || p->altura == NULL || p->peso == NULL) {
        return NULL;
    }
    else {
        Altura *a_clone = alt_copia(p->altura);
        Peso *p_clone = peso_copia(p->peso);
        return imc_cria(p->nome, a_clone, p_clone);
    }
}

/* Função Calcula IMC - Calcula o Índice de Massa Corporal */
float imc_calculaIMC(IMC *p) {
    int altura_cm = converteParacm(p->altura);
    int peso_g = converteParag(p->peso);
    float altura_m = altura_cm / 100.0;
    float peso_kg = peso_g / 1000.0;
    return peso_kg / (altura_m * altura_m);
}

/* Função categorizar - Categoriza o IMC */
char *imc_categorizarIMC(IMC *p) {
    float imc = imc_calculaIMC(p);
    if (imc < 18.5) {
        return "Abaixo do peso";
    } else if (imc < 25) {
        return "Peso normal";
    } else if (imc < 30) {
        return "Sobrepeso";
    } else {
        return "Obesidade";
    }
}