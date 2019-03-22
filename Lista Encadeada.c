#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int valor;
	struct No * prox;
} No;

No * novoNo(int valor){
	No * novo = malloc(sizeof(No));
	novo->valor = valor;
	novo->prox = NULL;
	
	return novo;
}

void adicionar(No * ini, int valor){
	//Encontra o ultimo n�
	while (ini->prox != NULL)
		ini = ini->prox;	
	
	//Declara��o do novo n�
	No * novo = novoNo(valor);
	
	//add o novo n� no pr�ximo do ultimo n�
	ini->prox = novo;
}

void remover(No ** no, int valor){	
	//(*no) � o ponteiro fora da fun��o
		
	No * ant = NULL;	
	No * aux = (*no);
	
	if (aux == NULL){
		printf("Lista Vazia\n");
		return;
	}		
	
	//Encontra o valor, sempre armazenando o n� anterior
	while (aux->valor != valor && aux != NULL){
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		printf("Valor n�o existente\n");
	else{		
		if (ant!=NULL){
			ant->prox = aux->prox;	
		}					
		else		
			*no = aux->prox;	
			
		free(aux);
	}	
}

void imprimir(No * no) {	
	while (no!=NULL){	
 		printf("%d ", no->valor);
 		no=no->prox;
 	}
}

int main(){
	No * li = novoNo(10);
	
	//Add elementos
	adicionar(li, 6);
	adicionar(li, 8);
	adicionar(li, 16);
	adicionar(li, 56);
	adicionar(li, 88);	
	
	//Imprime
	imprimir(li);	
	printf("\n");
	
	//Busca e remo��o
	remover(&li, 6);
	remover(&li, 10);		
	
	//Imprime
	imprimir(li);
	printf("\n");
}
