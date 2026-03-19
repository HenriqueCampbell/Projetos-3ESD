#include "TAD_Altura.h"
#include "TAD_Peso.h"

// Nome: Matheus Peixoto Menezes
// Nome: Manuelle Felix da Silva

/* Tipo exportado */
/* cria a medida do Indice de Massa Corporal */
typedef struct pessoaIMC IMC;

/* Funções exportadas */
/* Função cria - Aloca e retorna um IMC (altura e peso) */
IMC *imc_cria(char *nome, Altura *alt, Peso *peso);

/* Função altera peso - Altera o peso de um IMC */
void imc_alteraPeso(IMC *imc, Peso *g);

/* Função altera altura - Altera a altura de um IMC */
void imc_alteraAltura(IMC *imc, Altura *cm);

/* Função libera - Libera a memória de um IMC previamente criado */
void imc_libera(IMC *imc);

/* Função acessa - Retorna os valores de um IMC */
void imc_acessa(IMC *imc, Altura **alt, Peso **peso);

void imc_exibe(IMC* imc);

/* Função getIMC- Retorna uma string com os valores do IMC no formato
kg/m² */
char *imc_getIMC(IMC *imc);

int imc_compara(IMC *p1, IMC *p2);

IMC *imc_copia(IMC *p);

/* Função Calcula IMC - Calcula o Índice de Massa Corporal */
float imc_calculaIMC(IMC *p);

/* Função categorizar - Categoriza o IMC */
char *imc_categorizarIMC(IMC *p);