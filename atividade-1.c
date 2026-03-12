struct opiniao {
  char nome[5];
  int idade;
  int vPref[4]; // nota que a pessoa deu
};
typedef struct opiniao tOp;

void preencher(tOp * p,int i)
{
  char vNomes[3][10]={"ze","ana","joca"};
  int vIdades[3]={10,22,16};
  strcpy(p->nome, vNomes[i]);
  p->idade=vIdades[i];
  for( int j=0;j<3;j++)
    p->vPref[j]=(j+1)* i+3;
  return;  
}
int main() {
  tOp vEnt[3];
  tOp * vNomes[3];
  tOp * vIdades[3];
  for(int i=0;i<3;i++)
    preencher(&vEnt[i],i);
  
  vNomes[0]=&vEnt[1];
  vNomes[1]=&vEnt[2];
  vNomes[2]=&vEnt[0];
  
  vIdades[0]=&vEnt[0];
  vIdades[1]=&vEnt[2];
  vIdades[2]=&vEnt[1];

  return 0;
}