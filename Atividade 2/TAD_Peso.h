// Nome: Matheus Peixoto Menezes
// Nome: Manuelle Felix da Silva
/* Tipo exportado */
/* cria uma medida de peso como em kg e g*/
typedef struct peso Peso;

/* Funções exportadas */
/* Função cria - Aloca e retorna um peso (kg e g) */
Peso *peso_cria(int kg, int g);

/* Função libera - Libera a memória de um peso previamente criado */
void peso_libera(Peso *p);

/* Função acessa - Retorna os valores de um peso */
void peso_acessa(Peso *p, int *kg, int *g);

/* Função atribui - Atribui novos valores às partes de um peso */
void peso_atribui(Peso *p, int kg, int g);


void peso_exibe(Peso* p);

/* Função getPeso- Retorna uma string com os valores do PESO  no formato
kg,g*/
char *peso_getPeso(Peso *p);


int peso_compara(Peso *p1, Peso *p2);

Peso *peso_soma(Peso *p, int g);

Peso *peso_copia(Peso *p);