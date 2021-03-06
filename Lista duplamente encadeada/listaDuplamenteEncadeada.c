#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *esq;
	struct sCelula *dir;
}Celula;

Celula *getNode(){
	return (Celula *)malloc(sizeof(Celula));
}

void freeNode(Celula *q){
	free(q);
}

int isEmpty(Celula *lista){
	if(lista == NULL){
		return 1;
	}else
		return 0;
}

void init(Celula **lista){
	*lista = NULL;
}

void insertInitial(Celula **lista, int x){
	Celula *q;
	q = getNode();
	
	if(q != NULL){
		q->info = x;
		q->esq = NULL;
		q->dir = *lista;
		
		if(isEmpty(*lista) == 0){
			(*lista)->esq = q;
		}
		*lista = q;
	}else{
		printf("ERRO: No Q nao alocadado!");
	}
}

void insertEnd(Celula **lista, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		
		q->info = x;
		q->esq = NULL;
		q->dir = NULL;
		
		if(isEmpty(*lista) == 1){
			*lista = q;
		}else{
			aux = *lista;
			while(aux->dir != NULL){
				aux = aux->dir;
			}
			aux->dir = NULL;
			q->esq = aux;
		}
	}else{
		printf("ERRO: No Q nao alocadado!");
	}		
}

void removeInitial(Celula **lista){
	Celula *q;
	q = *lista;
	if(isEmpty(*lista) == 0){
		*lista = q->dir;
		if(*lista != NULL){
			(*lista)->esq = NULL;
		}
		freeNode(q);
	}else{
		printf("Erro: Lista Vazia!");
	}
}


void removeEnd(Celula **lista){
	Celula *q;
	Celula *aux;
	q = *lista;
	if(isEmpty(*lista) == 0){
		aux = *lista;
		while(aux->dir->dir != NULL){
			aux = aux->dir;
		}
		freeNode(aux->dir->dir);
		aux->dir = NULL;
		
	}else{
		printf("Erro: Lista Vazia!");
	}
}



void showList(Celula **lista){
	Celula *aux;
	aux = *lista;
	
	int i = 0;
	
	printf("\n=============================================");
	printf("\n		Printando a Lista....			");
	printf("\n=============================================");

	// enquanto aux n�o encontrar o final, ele printa o conte�do do pr�ximo....
	do{
		printf("\n Posicao da lista encadeada [%d] = %d\n",i,aux->info);
		aux = aux->dir;
		i += 1;
	}while(aux != NULL );

	printf("\n=============================================");
	
}

int main (){
	Celula *l;
	init(&l);
	int input, chooseMenu, loopMenu = 1;
	while (loopMenu == 1){
		printf("\n==============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Lista Duplamente Encadeada.......");
		printf("\n 2) Insere valor no inicio da Lista Duplamente Encadeada.......");
		printf("\n 3) Insere valor no final da Lista Duplamente Encadeada.......");
		printf("\n 4) Remove valor no inicio da Lista Duplamente Encadeada.......");
		printf("\n 5) Remove valor no final da Lista Duplamente Encadeada.......");
		printf("\n 6) Sair.......");
		printf("\n==============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d", &chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				showList(&l);
				break;
			case 2:
				// case 2
				printf("\nInsere valor no inicio da Lista Encadeada: ");
				scanf("%d", &input);
				insertInitial(&l, input);
				break;
			case 3:
				// case 3
				printf("\nValor a ser colocado no final da Lista Encadeada: ");
				scanf("%d", &input);
				insertEnd(&l, input);
				break;
			case 4:
				// case 4
				removeInitial(&l);
				break;
			case 5:
				// case 5
				removeEnd(&l);
				break;
			case 6:
				// case 6
				printf("Encerrando o Loop do menu!");
				loopMenu = 0;
				break;	
			default:
				printf("Opcao Invalida!");
		}	
	}
	return 0;	
}
