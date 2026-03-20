//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entregrador.h"

struct entregador {
    char nome[50];
    char veiculo[20];
    int disponivel; // 1 = livre, 0 = ocupado
    int entregas; // total de entregas realizadas
};

Entregador* entregador_criar(char* nome, char* veiculo) {
    Entregador* e = (Entregador*)malloc(sizeof(struct entregador));
    
    if (e==NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    strcpy(e->nome, nome);
    strcpy(e->veiculo, veiculo);
    e->disponivel = 1;
    e->entregas = 0;

    return e;
}

void entregador_liberar(Entregador* e) {
    free(e);
}

char* entregador_getNome(Entregador* e) {
    return p->nome;
}

int entregador_getEntregas(Entregador* e) {
    return e->entregas = entregas;
}
void entregador_setDisponivel(Entregador* e, int disp) {
    e->disp = disp;
}

int entregador_estaDisponivel(Entregador* e) {
    if (e->disp == 1) {
        return 1;
    }
    
    else {
        return 0;
    }
}

void entregador_contabilizarEntrega(Entregador* e) {
    e->entregas += 1;
}

char* entregador_paraString(Entregador* e) {
    char disponibilidade[30];
    char* str = (char*) malloc(500 * sizeof(char));
    
    if (entregador_estaDisponivel(e) == 1) {
        strcpy(disponibilidade, "Disponivel");
    }
    
    else {
        strcpy(disponibilidade, "Ocupado");
    }
    
    sprintf(str, "%s | %s | %s | Entregas:%d\n",
                   e->nome, e->veiculo, disponibilidade, entregas);
                   
    return str;
}