#define ERRO_LISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2

typedef struct ele{
  void *info;
  struct ele *proximo;
}Elemento;

typedef struct{
  Elemento *cabeca;
  int tamInfo;
	int num_ele;
}Lista;

void inicializa_lista(Lista *p, int t);
int lista_vazia(Lista l);
int insereNoInicio(Lista *p, void *info);
int removeDoInicio(Lista *p, void *info);
void mostra_float(void *x);
void mostra_lista(Lista l, void (*mostra)(void*));
int insereNoFim(Lista*l, void *info);
int removeDoFim(Lista *l, void *info);
int insereNaPos(Lista *l, void *info, int pos);
int conta_elementos(Lista l);
int removeNaPos(Lista *l, void *info, int pos);
int modificaNaPos(Lista *l, void *info, int pos);
int leNaPos(Lista *l,void *info, int pos);
int insereEmOrdem(Lista *l, void *info,int (*compara)(void*,void*));
int posicao_do_ele(Lista *l, void *info, int(*compara)(void*, void*));
int compara_float (void *x, void *y);
void desaloca_Lista( Lista *m);
