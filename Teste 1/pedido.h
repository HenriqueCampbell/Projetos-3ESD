//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#include "Horario.h"

typedef struct pedido Pedido;


Pedido* pedido_criar(int id, char* cliente, float valor, int hora, int minuto);

void pedido_liberar(Pedido* p);

int pedido_getID(Pedido* p);

int pedido_getStatus(Pedido* p);

void pedido_atribuir(Pedido* p, Entregador* ent, int horaSaida, int minutoSaida);

void pedido_entregar(Pedido* p, int horaEntrega, int minutoEntrega);

int pedido_tempoTotal(Pedido* p);

int pedido_tempoRota(Pedido* p);

char* pedido_paraString(Pedido* p);