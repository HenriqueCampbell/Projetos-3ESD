//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Entregas.h"
#include "entregador.h"
#include "pedido.h"


int main(void)
{
    
    Entregador* vetorEntregadores[3];
    vetorEntregadores[0] = entregador_criar("Carlos Moto", "Moto");
    vetorEntregadores[1] = entregador_criar("Ana Bike", "Bike");
    vetorEntregadores[2] = entregador_criar("Pedro Carro", "Carro");
    
    Pedido* vetorPedidos[4];
    vetorPedidos[0] = pedido_criar(1, "João Silva", 32.50, 8,15);
    vetorPedidos[1] = pedido_criar(2, "Maria Santos", 45.90, 8,30);
    vetorPedidos[2] = pedido_criar(2, "Maria Santos", 45.90, 8,45);
    vetorPedidos[3] = pedido_criar(3, "Ana Costa", 67.30, 9,0);
    
    //Exibição de entregadores cadastrados e pedidos feitos
    
    printf("=== SISTEMA DE ENTREGAS RÁPIDO EXPRESS ===\n\n");
    printf("=== ENTREGADORES CADASTRADOS ===\n");
    
    
    char* exibicao;
    int i;
    
    for (i = 0; i < 3; i++)
    {
        exibicao = entregador_paraString(vetorEntregadores[i]);
        printf("%s\n", exibicao);
    }

    for (i = 0; i < 4; i++)
    {
        exibicao = pedido_paraString(vetorPedidos[i]);
        printf("%s\n", exibicao);
    }
    
    int hora, minuto;
    
    printf("\n=== CONSULTA ===\n");
    printf("Horário atual para simulação (hora minuto): ");
    scanf("%d %d", &hora, &minuto);
    
    // Declaração de variaveis usadas nas operações
    Horario *h = hor_criar(hora, minuto);
    char *exibicaoHorario = hor_paraString(h);
    char* nome;
    int id, status, disponivel, estaDisponivel;
    float valor;
    
    printf("\n=== INICIANDO OPERAÇÕES (referência: %s) ===\n", exibicao;)
    
    //Funcao setEntregador pedido 1 Carlos com horario hora e  minuto
    //Funcao setEntregador pedido 2 Ana com hora e minuto
    
    Entregas* vetorEntregas[4];
    
    
    int IDpedido = pedido_getID(vetorPedidos[i]);
    vetorEntregas[i] = entrega_criar();
    entregas_atribuirPedido(vetorEntregas[i], IDpedido , hora, minuto);
        
    pedido_paraString(vetorPedidos[i]);
        
    nome = entregador_get(vetorEntregadores[i]);
    id = pedido_getID(vetorPedidos[i]);
    status = pedido_getStatus(vetorPedidos[i]);
    disponivel = entregador_estaDisponivel(vetorEntregadores[i]);
    valor = pedido_getValor(vetorPedidos[i]);
        
    if (disponivel == 1) {
    printf("%s - Atribuindo Pedido %d para %s\n", exibicaoHorario, id, nome);
    }
        
    printf("\n=== PEDIDOS EM ROTA (%s) ===\n", exibicaoHorario);
        
    for (i = 0; i < 2; i++) {
            
    if (status == 1) {
        printf("%d | %s | R$%.2f | Em rota | %s | Saída: %s", id, nome, valor, nome, exibicaoHorario);
        }
    }
}


