#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Altura.h"
#include "TAD_Peso.h"
#include "TAD_PessoaIMC.h"

// Nome: Matheus Peixoto Menezes
// Nome: Manuelle Felix da Silva

int main(void) {

    IMC* vetor[4];

    Altura *a0 = alt_cria(1,70);
    Peso *p0 = peso_cria(47,500);
    vetor[0] = imc_cria("Henrique", a0, p0);

    Altura *a1 = alt_cria(1,63);
    Peso *p1 = peso_cria(54,300);
    vetor[1] = imc_cria("Ana", a1, p1);

    Altura *a2 = alt_cria(1,73);
    Peso *p2 = peso_cria(60,000);
    vetor[2] = imc_cria("Matheus", a2, p2);

    Altura *a3 = alt_cria(1,85);
    Peso *p3 = peso_cria(54,500);
    vetor[3] = imc_cria("Manuelle", a3, p3);

    for (int i = 0; i < 4; i++) {
        char *n;
        Altura *a;
        Peso *p;

        imc_acessa(vetor[i], &n, &a, &p); 
    
        char *cat = imc_categorizarIMC(vetor[i]);

        if (strcmp(cat, "Peso normal") == 0 || strcmp(cat, "Sobrepeso") == 0) {
            printf("Pessoa: %s - Categoria: %s Esta pessoa esta apta para trabalhar. \n", n, cat);
        }
        else {
            printf("Pessoa: %s - Categoria: %s Esta pessoa nao esta apta para trabalhar. \n", n, cat);
        }

    }

}


