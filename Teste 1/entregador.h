//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct entregador Entregador;

Entregador* entregador_criar(char* nome, char* veiculo);

void entregador_liberar(Entregador* e);

char* entregador_getNome(Entregador* e);

void entregador_setDisponivel(Entregador* e, int disp);

int entregador_getEntregas(Entregador* e);

int entregador_estaDisponivel(Entregador* e);

void entregador_contabilizarEntrega(Entregador* e);

char* entregador_paraString(Entregador* e);
