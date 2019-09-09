#include "Lista.h"

typedef struct{
	int coluna;
	float valor;
}EntradaMatriz;

typedef struct{
	int lin, col;
	Lista l;
}MatrizEsparsa;

void inicializaMatriz(MatrizEsparsa *m, int lin, int col);
void setValor(MatrizEsparsa *m, int lin, int col, float info);
void mostraMatriz(MatrizEsparsa m);
float getNaPos(MatrizEsparsa *m1, int lin, int col);
void somaDeMatriz(MatrizEsparsa *m1, MatrizEsparsa *m2, MatrizEsparsa *soma);
void multiplicacaoDeMatriz(MatrizEsparsa *m1, MatrizEsparsa *m2, MatrizEsparsa *produto);
void desaloca_Matriz(MatrizEsparsa *m);



//usar o insereEmOrdem
/*set(endereço matriz, linha, coluna, valor);

*/
