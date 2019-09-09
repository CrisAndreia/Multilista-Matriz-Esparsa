
#include "MatrizEsparsa.h"
#include <stdio.h>


void inicializaMatriz(MatrizEsparsa *m, int lin, int col){
	m->lin=lin;
	m->col=col;
	int i;
	Lista sub;
	inicializa_lista(&m->l,sizeof(Lista));
	for(i=0;i<m->lin;i++){
		inicializa_lista(&sub, sizeof(EntradaMatriz));
		insereNoFim(&m->l, &sub);
	}
}

int comparaEntrada(void *x, void *y){
	EntradaMatriz *a=x, *b=y;

	if(a->coluna>b->coluna)
		return 1;
	if(a->coluna<b->coluna)
		return -1;
	return 0;
}

void setValor(MatrizEsparsa *m, int lin, int col, float info){
	Lista p, sub;
  int ind;
	EntradaMatriz novo,x;
	int i;
  lin= lin-1;
  col=col-1;

  
  if(lin<0 || col <0){
    printf("%.1f inserido em posicao invalida\n", info);
  }
  else{
	  if(lin+1 > m->lin){
		  for(i=m->lin;i<lin+1;i++){
		  inicializa_lista(&sub, sizeof(EntradaMatriz));
		  insereNoFim(&m->l, &sub);
		  }
		  m->lin = lin+1;
	  }
	  if(col+1 > m->col)
	  	m->col = col+1;

    leNaPos(&m->l, &p, lin);
    novo.valor=info;
    novo.coluna=col;

    ind = posicao_do_ele(&p, &novo, comparaEntrada);
    if(ind!=-1){
      if(info==0)
        removeNaPos(&p, &x, ind);
      else
        modificaNaPos(&p, &novo, ind);
    }
	  else		
		  insereEmOrdem(&p, &novo, comparaEntrada);

    modificaNaPos(&m->l, &p, lin);
  }
}

float getNaPos(MatrizEsparsa *m1, int lin, int col){
  Lista p;
  int ind;
  EntradaMatriz b;
  if ((lin < 0 || col <0) || (lin >m1->lin || col> m1->col)){
    printf("Erro posicao [%d,%d] inválida!\n",lin,col);
  } 
  else{  
    lin= lin-1;
    col=col-1;
    b.coluna = col;
    leNaPos(&m1->l, &p, lin);
    ind = posicao_do_ele( &p, &b, comparaEntrada);
    if(ind == -1 ){
      //printf("[%d , %d] = 0",lin+1, col+1);
      return 0;
    }
    else{
      leNaPos(&p, &b, ind);
      //printf("[%d , %d] = %.1f", lin+1, col+1, b.valor);
      return b.valor;
    }
    
  }
  return 0;
}

void mostraMatriz(MatrizEsparsa m){
	Lista l;
	int i,j,k,w;

	for(i=0;i < m.lin;i++){
		leNaPos(&m.l, &l, i);
		j=0;
		k=0;
		EntradaMatriz e;
		if(!lista_vazia(l))
			while(leNaPos(&l, &e, k)!=ERRO_POS_INVALIDA){
				for(w=j;w<e.coluna;w++){
					printf("0.0   ");
				}
				printf("%.1f   ",e.valor);
				k++;
				j=e.coluna+1;
			}
		for(w=j;w<m.col;w++){
			printf("0.0   ");
		}
		printf("\n");
	}
  printf("\n");
}

void somaDeMatriz(MatrizEsparsa *m1, MatrizEsparsa *m2, MatrizEsparsa *soma){
  int i, j;
  float x, y;
	if(m1->lin == m2->lin && m1->col == m2->col){
		inicializaMatriz(soma, m1->lin, m1->col);
    for (i=1;i<m1->lin+1;i++){
      for(j=1;j<m1->col+1;j++){
        x = getNaPos(m1, i, j);
        y = getNaPos(m2, i, j);
        setValor(soma, i, j, x+y);
      }
    } 
  } 
	else{
		printf("Matrizes com dimensões diferentes! Não é possivel realizar a soma.");
  } 
}

void multiplicacaoDeMatriz(MatrizEsparsa *m1, MatrizEsparsa *m2, MatrizEsparsa *produto){
  int i, j,k;
  float x, y,soma;
	if(m1->col == m2->lin){
		inicializaMatriz(produto, m1->lin, m2->col);
    for(i=1; i<m1->lin+1; i++){
    	for(j=1; j<m2->col+1; j++){ 
      	soma=0; 
      	for(k=1; k<m1->col+1; k++){
					x = getNaPos(m1,i,k);
					y = getNaPos(m2,k,j);
					soma+=x*y; 
				}
				setValor(produto,i,j,soma);
    	}
		} 
  } 
	else{
		printf(" A número de colunas da Matriz A não é mesmo  do número de linhas da Matriz B! Não é possivel realizar a multiplicação.");
  }
}
void desaloca_Matriz(MatrizEsparsa *m){
	int i;
	Lista sub;
	for(i=0;i<m->lin;i++){
		leNaPos(&m->l, &sub, i);
		desaloca_Lista(&sub);
	}
	desaloca_Lista(&m->l);
}
