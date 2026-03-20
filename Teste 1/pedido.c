//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#include "pedidos.h"
#include "Horario.h"

struct pedido {
int id;
char cliente[50];
float valor;
Horario* horaPedido; // criado internamente
Horario* horaSaida; // criado internamente (NULL se não atribuído)
Horario* horaEntrega; // criado internamente (NULL se não entregue)
Entregador* entregador; // referência para entregador
int status; // 0, 1 ou 2

};

Pedido* pedido_criar(int id, char* cliente, float valor, int hora, int minuto) {
    Pedido* p = (Pedido*)malloc(sizeof(struct pedido));
    
    Horario* horaSaida;
    Horario* horaEntrega;:
    //char horaEntrega, horaPedido;
    
    p->id = id;
    strcpy(p->cliente, cliente);
    p->valor = valor;
    Horario* horaPedido = hor_criar(hora, minuto);
    Horario* horaPedido = hor_criar(NULL);;
    Horario* horaPedido = hor_criar(NULL);;
    status = 0;

    return p;
}

void pedido_liberar(Pedido* p) {
    if (horaEntrega) {
        free(horaEntrega);
    }
    
    if (horaSaida) {
        free(horaSaida);
    }
    
    free(p); //Imp-edir liberar entregador???w??w?
}

int pedido_getID(Pedido* p) {
    return p->id;
}

int pedido_getStatus(Pedido* p) {
    return p->status;
}

float pedido_getValor(Pedido* p) {
    return p->valor;
}

void pedido_atribuir(Pedido* p, Entregador* ent, int horaSaida, int minutoSaida) {
    Horario* horaSaidaNovo;
    p->horaEntrega = hor_criar(horaSaida, minutoSaida);
    p->ent = ent;
    p->status = 1;
}

void pedido_entregar(Pedido* p, int horaEntrega, int minutoEntrega) {
    Horario* horaEntregaNovo;
    p->horaEntrega = hor_criar(horaEntrega, minutoEntrega);
    entregador_contabilizarEntrega(p->Entregador);
    p->status = 2;
}

int pedido_tempoTotal(Pedido* p) {
    if (status != 2) {
        return -1;
    }
    
    int tempoTotal = hor_diferencaMinutos(p->horaEntrega, p->horaPedido);
    return tempoTotal;
}

int pedido_tempoRota(Pedido* p) {
    if (status != 2) {
        return -1;
    }
    
    int tempoRota = hor_diferencaMinutos(p->horaEntrega, p->horaSaida);
    return tempoRota;
}

char* pedido_paraString(Pedido* p) {
    char* str = (char*) malloc(500 * sizeof(char));
    
    if (p->status == 0)  {
        sprintf(str, "#%s | %s | %.2f | Aguardando\n",
                   p->id, p->cliente, p->valor);
    }
    
    
    if (p->status == 1)  {
        sprintf(str, "#%s | %s | %.2f | Em rota | %s | Saida:%s\n",
                   p->id, p->cliente, p->valor, p->entregador, p->horaSaida);
    }
    
    else  {
        tempoRota = tempoTotal(p);
        sprintf(str, "#%s | %s | %.2f | Entregue | %s | tempo:%s\n",
                   p->id, p->cliente, p->valor, p->entregador, tempoRota);
    }
                   
    return str;
}