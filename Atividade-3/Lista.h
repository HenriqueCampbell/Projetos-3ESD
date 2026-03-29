typedef struct tipo_lista tLista; 

/*cria lista vazia*/ 
tLista * lista_cria_vazia(int maximo,int classif, int repet);
//lista está vazia? 
int lista_vazia( const tLista *pl);
//lista está cheia? 
int lista_cheia( const tLista *pl);
//lista com repetição? 
int lista_repet( const tLista *pl);
//lista classificada? 
int lista_classif( const tLista *pl);
//percorre a lista 
void lista_percorre(const tLista *pl);
//inclui novo elemento na lista
int lista_inclui(tLista *pl, int novo);
//exclui elemento da lista
int lista_exclui(tLista *pl, int elim);

// AUXILARES
//Retira vários
int retira_varios(tLista * pl, int no);
//Busca DESORDENADA sem repetição 
int busca_des_srep(tLista *pl,int chave,int *pos);
//Busca BINÁRIA 
int busca_bin(tLista *pl, int chave, int *pos);
// Encontra posInicial e qntdade de um elemento (valor) repetido numa lista
void encontra_posInicEqt(tLista*pl,int * posRet, int *qt, int valor);
//CHEGA PARA CÁ  ==> TRANSFORMAR PARA  memcpy
void chegaparaca(tLista *pl, int pos, int qt);
// CHEGA PARA LÁ ==> TRANSFORMAR PARA  memcpy
void chegaparala(tLista *pl, int pos);
