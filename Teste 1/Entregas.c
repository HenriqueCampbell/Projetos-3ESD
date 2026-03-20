//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#include "pedido.h"
#include "Horario.h"
#include ""

struct entregas {
Entregador** entregadores; // vetor dinâmico
int qtdEntregadores;
int capEntregadores;
Pedido** pedidos; // vetor dinâmico
int qtdPedidos;
int capPedidos;
int proximoID; // próximo ID disponível (começa em 1)
}; 

Entregas* entrega_criar() {
    
    Entregas* e = (Entregas*)malloc(sizeof(struct Entregas)));
    e->qtdEntregadores = 0;
    e->proximoID = 1;
    e->*Pedido pedidos[5];
    e->*Entregadores entregadores[5];
    int capEntregadores = 3;
    
    e->entregadores = malloc(capEntregadores * sizeof(Entregadores*));

    for (int i = 0; i < capEntregadores; i++) {
        p->entregadores[i] = entregadores[i];
        exit(1);
    }
    
    e->pedidos = malloc(capPedidos * sizeof(Pedidos*));

    for (int i = 0; i < capPedidos; i++) {
        p->pedidos[i] = pedidos[i];
        exit(1);
    }

    return e;
}

void entregas_liberar(Entregas* e) {
    if (entregas) {
        free(entregas);
    }
    
    if (pedidos) {
        free(pedidos);
    }

    free(p); 
}

int entregas_buscarEntregadorLivre(Entregas* e)
{
    for (int i = 0; i < qtdEntregadores; i++)
    {
        if (entregadores[i].disponivel == 1)
        {
            return i+1;
        }
    }
}

void entregas_cadastrarEntregador(Entregas* e, Entregador* ent)
{
    
}

int entregas_novoPedido(Entregas* e, char* cliente, float valor, int hora, int minuto) {
    int idAtual;
    
    for (int = i;i= pedido_getId(e->ped);
    pedido_criar( d, char* cliente, float valor, int hora, int minuto);
    
    
}


int entregas_atribuirPedido(Entregas* e, int idPedido, int horaSaida, int minutoSaida) {
    int status; 
    int idPedidoVet;
    for (int i = 0; i< qtdPedidos;i++) {
        status = pedido_getStatus(e->Pedidos[i]);
        idPedidoVet = pedido_getId(e->Pedidos[i]);
        
        if (idPedidoVet == idPedido) {
            if (status == 1) {
                pedido_atribuir(e->pedidos[i]);
                entregador_setDisponivel(e, 0);
                return 1;
            }
        }
    }
}

int entregas_finalizarPedido(Entregas* e, int idPedido, int horaEntrega, int
minutoEntrega) {
    int status; 
    int idPedidoVet;
    for (int i = 0; i< qtdPedidos;i++) {
        status = pedido_getStatus(e->Pedidos[i]);
        idPedidoVet = pedido_getId(e->Pedidos[i]);
        
        if (idPedidoVet == idPedido) {
            if (status == 1) {
                pedido_entregar(e->pedidos[i]);
                entregador_setDisponivel(e, 1);
                return 1;
            }
        }
    }
    return 0;
}

char* entregas_listarPendentes(Entregas* e) {
    int status; 
    int idPedido;
    char* str = (char*) malloc(500 * sizeof(char));
    
    for (int i = 0; i< qtdPedidos;i++) {
        status = pedido_getStatus(e-pedidos[i]);
        idPedido = pedido_getId(e->pedidos[i]);
        
        if (status == 0 || status = 1) {
            sprintf(str, "Pedido:#%d pendente",
                   idPedido->id);
        }
    }
    free(str);
}

char* entregas_melhorEntregador(Entregas* e) {
    int maioQntEntregas = 0;
    char* melhorEntregador;
    
    for (int i = 0;i < qtdEntregadores;i++) {
        QtdEntrega = entregador_getEntregas(e[i]);
        if (QtdEntrega > maioQntEntregas) {
            maioQntEntregas = QtdEntrega;
            melhorEntregador = entregador_getNome(e[i]);
        }
    }
    return melhorEntregador;
}


