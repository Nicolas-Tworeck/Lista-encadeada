#include<stdio.h>
#include<malloc.h>
struct lista{
	int info;
	struct lista*prox;
};
typedef struct lista Lista;

/*inicialização*/
Lista*inicializa(){
	return NULL;
}

/*inserção no inicio*/
Lista*insere(Lista* l,int i){
	Lista*novo=(Lista*) malloc(sizeof(Lista));
	novo->info=i;
	novo->prox=l;
	return novo;
}
/*mostra*/
void mostra(Lista*l){
	Lista*p;
	for(p=l;p!=NULL;p=p->prox )
		printf("info-%d\n",p->info);
}
/*busca*/
Lista*busca(Lista*l, int i){
	Lista*p;
	for (p=l;p!=NULL;p=p->prox)
		if(p->info==i)
		return p;
	return NULL;
}
/*destroi*/
void destroi (Lista*l){
	Lista*p=l;
	while(p!=NULL){
		Lista*t=p->prox;
		free(p);
		p=t;
	}
}
/*exclui*/
Lista*exclui(Lista*l, int v){
	Lista*ant=NULL;
	Lista*p=l;
	while (p!=NULL&&p->info!=v){
		ant=p;
		p=p->prox;
	}
	if(p==NULL)
	return l;
	if(ant==NULL)
	l=p->prox;
	else
	ant->prox=p->prox;
	free(p);
	return l;
}
	int main(void){
		Lista*l;
		Lista*b;
		int elem,opcao=-1;
	l=inicializa();
	b=inicializa();
	
	while (opcao!=0){
		printf("\n1-Insere elemento no inicio");
		printf("\n2-Mostra lista\n3-Busca elemento ");
		printf("\n4-exclui elemento\n0-sair\n");
		printf("Digite sua opção");
		scanf("%d",&opcao);
		switch(opcao)
	{
			
	case 1:printf("Digite o elemento a inserir");
	scanf ("%d",&elem);
	l=insere(l,elem);
	printf ("Elemento incluido\n");
	break;
	
	case 2:mostra(l);
	break;
	
	case 3:printf ("Digite o elemento a buscar");
	scanf("%d",&elem);
	b=busca(l,elem);
	if(b!=NULL) printf("elemento existente!!! \n");
	else printf("Elemento existe!!! \n");
	break;
	
	case 4: printf("Digite o elemento a excluir \n");
	scanf("%d",&elem); 
	l=exclui(l,elem);
	printf("elemento excluido \n");
	break;
	case0:break;
	default: printf("opçãoinvalida \n");
	}
}
destroi(l);
}
	
