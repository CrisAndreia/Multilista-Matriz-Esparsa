#include "MatrizEsparsa.h"
#include <stdio.h>
#include <stdlib.h>
int main (void){
	MatrizEsparsa m1, m2, resultante;
	int opcao;
	
	do{
		printf("\n\tCALCULADORA DE MATRIZES\n\n");
	
		printf("[1] Criar matriz vazia.\n");
		printf("[2] Mostrar dados da matriz.\n");
		printf("[3] Modificar dado da Matriz.\n");
		printf("[4] Somar Matrizes.\n");
		printf("[5] Multiplicar Matrizes.\n");
		printf("[6] Desalocar Matriz.\n");
		printf("[0] Sair.\n");
		printf("\nEscolha uma opção do MENU: ");
		scanf("%d",&opcao);
		switch(opcao){
			int lin, col, opcao1;
			float valor;
			case 1:
				printf("[1] Matriz 1\n");
				printf("[2] Matriz 2\n");
				fflush(stdin);
				scanf("%d",&opcao1);
				switch(opcao1){
					case 1:
						printf("Digite o número de Linhas e de Colunas da Matriz 1: ");
						scanf(" %d %d", &lin, &col);
						inicializaMatriz(&m1, lin, col);					
					break;
					case 2:
						printf("Digite o número de Linhas e de Colunas da Matriz 2: ");
						scanf(" %d %d", &lin, &col);
						inicializaMatriz(&m2, lin, col);
					break;
					default:
						printf("Opção Inválida!");
				}
			break;
			case 2:
				printf("[1] Matriz 1\n");
				printf("[2] Matriz 2\n");
				printf("[3] Resultante\n");
				scanf("%d",&opcao1);
				switch(opcao1){
					case 1:
						mostraMatriz(m1);
					break;
					case 2:
						mostraMatriz(m2);
					break;
					case 3:
						mostraMatriz(resultante);
					break;
					default:
					printf("opção Inválida!");
				}
			break;
			case 3:
				printf("[1] Matriz 1\n");
				printf("[2] Matriz 2\n");
				scanf("%d",&opcao1);
				printf("Digite a linha, a colunao e o valor:");
				scanf("%d %d %f",&lin,&col,&valor);
				switch(opcao1){
					case 1:
						setValor(&m1, lin, col, valor);
					break;
					case 2:
						setValor(&m2, lin, col, valor);
					break;
					default:
					printf("opção Inválida!");
				}
			break;
			case 4:
				somaDeMatriz(&m1, &m2, &resultante);
			break;
			case 5:
				multiplicacaoDeMatriz(&m1, &m2, &resultante);
			break;
			case 6:
				printf("[1] Matriz 1\n");
				printf("[2] Matriz 2\n");
				scanf("%d",&opcao1);
				switch(opcao1){
					case 1:
						desaloca_Matriz(&m1);
					break;
					case 2:
						desaloca_Matriz(&m2);
					break;
					default:
					printf("opção Inválida!");
				}
			break;
			case 0:
			break;
			default:
					printf("opção Inválida!");
		}
	}while(opcao!=0);
  
	return 0;
}

