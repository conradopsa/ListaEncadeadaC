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

void adicionarI(No ** iniL, int valor){
	//(*no) é o ponteiro fora da função

	No* aux = novoNo(valor);
	aux->prox = (*iniL);
	(*iniL) = aux;
}

void adicionarF(No ** ini, int valor){
	//(*no) é o ponteiro fora da função

	if ((*ini) == NULL){
		(*ini) = novoNo(valor);
		return;
	}

	No *aux = (*ini);

	//Encontra o ultimo nó
	while (aux->prox != NULL)
		aux = aux->prox;	
	
	//Declaração do novo nó
	No * novo = novoNo(valor);
	
	//add o novo nó no próximo do ultimo nó
	aux->prox = novo;
}

void remover(No ** no, int valor){	
	//(*no) é o ponteiro fora da função
		
	No * ant = NULL;	
	No * aux = (*no);
	
	if (aux == NULL){
		printf("Lista Vazia\n");
		return;
	}		
		
	//Encontra o valor, sempre armazenando o nó anterior
	while (aux != NULL && aux->valor != valor){
		ant = aux;
		aux = aux->prox;
	}

	if (aux == NULL)
		printf("Valor (%d) não existente\n", valor);
	else{		
		if (ant!=NULL){
			ant->prox = aux->prox;	
		}					
		else		
			(*no) = aux->prox;	
			
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
	No * li = NULL;
	
	//Add elementos no inicio
	adicionarI(&li, 10);
	adicionarI(&li, 6);
	adicionarI(&li, 8);

	//Add elementos no fim
	adicionarF(&li, 16);
	adicionarF(&li, 56);
	adicionarF(&li, 88);	
	
	//Imprime
	imprimir(li);	
	printf("\n");
	
	//Busca e remoção
	remover(&li, 6);
	remover(&li, 10);
	
	//Imprime
	imprimir(li);
	printf("\n");
}
