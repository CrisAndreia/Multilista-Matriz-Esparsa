#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compara_float (void *x, void *y){
	float *a=x, *b=y;
	if(*a > *b)
		return 1;
	if(*a < *b)
		return-1;
	return 0;
}


void inicializa_lista(Lista *p, int t){
  p->cabeca=NULL;
  p->tamInfo=t;
	p->num_ele=0;
}

int lista_vazia(Lista l){
  return l.cabeca==NULL;
}
Elemento *aloca_ele(void *info, int t){
	Elemento *p=malloc(sizeof(Elemento));
	if(p==NULL)
	 return  NULL;
	p->info=malloc(t);
	if(p->info==NULL){
		free(p);
		return NULL;
	}
	memcpy(p->info, info, t);
	return p;
}

int insereNoInicio(Lista *p, void *info){

  Elemento *novo=aloca_ele(info, p->tamInfo);
  if(novo==NULL)
    return 0;

	novo->proximo=p->cabeca;
	p->cabeca=novo;
	p->num_ele++;
	return 1;//sucesso
}
int removeDoInicio(Lista *p, void *info){
	if(lista_vazia(*p))
		return ERRO_LISTA_VAZIA;
	memcpy(info, p->cabeca->info, p->tamInfo);//destino, origem, tamanho
	Elemento *aux = p->cabeca;
	p->cabeca = aux->proximo; //p->cabeca = p->cabeca->proximo;
	free(aux->info);
	free(aux);
	p->num_ele--;
	return 1;//Sucesso
}


void mostra_lista(Lista l, void (*mostra)(void*)){
	if(lista_vazia(l))
		printf("Lista Vazia!\n");
	else{
		printf("Dados da Lista:\n");
		Elemento *p=l.cabeca;
		int cont = 0;
		while(p!=NULL){ //Se p não é nulo ele aponta pra um valor
			printf("[%d] ",cont);
			mostra(p->info);
			p=p->proximo;	//aponta pro proximo
			cont++;
		}
	}
}

int insereNoFim(Lista*l, void *info){
	if(lista_vazia(*l))
		return insereNoInicio(l,info);
	Elemento *p = l ->cabeca;
	while(p->proximo!=NULL){
		p=p->proximo;
	}
	Elemento *novo=aloca_ele(info,l->tamInfo);
	if(novo==NULL)
	 return 0;//faltou memória
	p->proximo=novo;
	novo->proximo=NULL;
	l->num_ele++;
	return 1;//sucesso
}


int removeDoFim(Lista *l, void *info){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(l->cabeca->proximo == NULL)// Somente 1
		return removeDoInicio(l, info);
	Elemento *p = l->cabeca;
	while(p->proximo->proximo!=NULL){//penúltimo
		p=p->proximo;
	}
	Elemento *aux = p->proximo;
	memcpy(info, aux->info, l->tamInfo);
	free(aux->info);
	free(aux);
	p->proximo = NULL;
	l->num_ele--;
	return 1;
}

int insereNaPos(Lista *l, void *info, int pos){
	if(pos<0 || pos>l->num_ele)
		return ERRO_POS_INVALIDA;
	if(pos==0)
		return insereNoInicio(l,info);
	if(pos==l->num_ele)
		return insereNoFim(l,info);
	Elemento *p=l->cabeca;
	int cont = 0;
	while(cont < pos-1){
		p=p->proximo;
		cont++;
	}
	Elemento *novo=aloca_ele(info,l->tamInfo);
	if(novo==NULL)
	 return 0;//faltou memória
	novo->proximo=p->proximo;
	p->proximo=novo;
	l->num_ele--;
	return 1;
}


int removeNaPos(Lista *l, void *info, int pos){
	if (lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0 || pos>l->num_ele)
		return ERRO_POS_INVALIDA;
	if(pos == 0)
		return removeDoInicio(l, info);
	if(pos == l->num_ele)
		return removeDoFim(l, info);
	Elemento *p = l->cabeca;
	int cont=0;
	while(cont<pos-1){
		p=p->proximo;
		cont++;
	}
	Elemento *aux = p->proximo;
	p->proximo = aux->proximo;
	l->num_ele--;
	return 1;	//Sucesso
}

int modificaNaPos(Lista *l, void *info, int pos){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0 || pos>=l->num_ele)
		return ERRO_POS_INVALIDA;
	Elemento *p = l->cabeca;
	int cont =0;
	while(cont<pos){
		p=p->proximo;
		cont++;
	}
	memcpy (p->info, info, l->tamInfo);
	return 1;
}

int leNaPos(Lista *l,void *info, int pos){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0 || pos>=l->num_ele)
		return ERRO_POS_INVALIDA;
	Elemento *p = l->cabeca;
	int cont =0;
	while(cont<pos){
		p=p->proximo;
		cont++;
	}
	memcpy(info, p->info, l->tamInfo);
	return 1;
}

int insereEmOrdem(Lista *l, void *info,int (*compara)(void*,void*)){
	int cont=0;
	Elemento *p=l->cabeca;
	while(p!=NULL && compara(info,p->info)>0){
		cont++;
		p=p->proximo;
	}
	return insereNaPos(l,info,cont);
}
int posicao_do_ele(Lista *l, void *info, int(*compara)(void*, void*)){
	if (lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	else{
	  Elemento *p = l->cabeca;
	  int cont =0;
	  while(p!=NULL){// percorre a lista toda 
		  if(compara(info, p->info)==0)
			  return cont;
		  p=p->proximo;//vai pro proximo elemento
	    cont++;
	  }
  }
  return -1; 
}
void desaloca_Lista( Lista *m){
	Elemento *p = m->cabeca, *aux;
    while (p != NULL)
    {
        aux = p;
        p = p->proximo;
        free (aux);
    }
    m->cabeca = NULL;
}
//indica que valor nao foi encontrado;
//sizeof de uma lista = 16
