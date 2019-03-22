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
	//Encontra o ultimo nó
	while (ini->prox != NULL)
		ini = ini->prox;	
	
	//Declaração do novo nó
	No * novo = novoNo(valor);
	
	//add o novo nó no próximo do ultimo nó
	ini->prox = novo;
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
	while (aux->valor != valor && aux != NULL){
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
		printf("Valor não existente\n");
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
	
	//Busca e remoção
	remover(&li, 6);
	remover(&li, 10);		
	
	//Imprime
	imprimir(li);
	printf("\n");
}
