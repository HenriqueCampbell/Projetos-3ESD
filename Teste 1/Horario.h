//Henrique Campbell Trechau
//Mariana da Conceição Albuquerque Machado

typedef struct horario Horario;
/**
* Cria um novo horário com hora e minuto especificados
* parâmetro: Hora (0-23)
* parâmetro: Minuto (0-59)
* retorna um ponteiro para o Horario alocado
*/
Horario* hor_criar(int hora, int minuto);
/**
* Cria um horário com o momento atual do sistema
* retorna um ponteiro para o Horario com a hora atual
*/
Horario* hor_atual();
/**
* Calcula a diferença absoluta em minutos entre dois horários
* parâmetro: Primeiro horário
* parâmetro: Segundo horário
* retorna Número de minutos de diferença (sempre positivo)
*/

int hor_diferencaMinutos(Horario* h1, Horario* h2);
/**
* Compara dois horários
* parâmetro: Primeiro horário
* parâmetro: Segundo horário
* retorna 0 se iguais, positivo se h1 > h2, negativo se h1 < h2
*/
int hor_comparar(Horario* h1, Horario* h2);
/**
* Retorna uma representação em string do horário no formato "HH:MM"
* parâmetro: Horário
* retorna uma String alocada dinamicamente (deve ser liberada com free())
*/
char* hor_paraString(Horario* h);
/**
* Libera a memória de um horário
* parâmetro: Horário a ser liberado
*/
void hor_liberar(Horario* h);