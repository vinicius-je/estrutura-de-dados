/*********************************
#
# ESTRUTURA DE DADOS
#
# tadlista.h
#
*********************************/
typedef void *tdado;

typedef struct tnoh{
	tdado dado;
	struct tnoh *proximo;
} tnode;

typedef tnode* pnoh;

typedef struct{
	pnoh primeiro;
	pnoh ultimo;
	int tamanho;
} tcabec;

typedef tcabec* Lista;
/*********************************
#
# ESTRUTURA DE DADOS DA LISTA
#
**********************************/
Lista criaLista();
Lista appendLista(Lista lst, tdado dado);
Lista insertLista(Lista lst, tdado dado, int index);
Lista removeLista(Lista lst, int index);
tdado dadoLista(Lista lst, int index);
tdado primlista(Lista lst);
tdado ultLista(Lista lst);
int lenLista(Lista lst);
int indexLista(Lista lst, tdado dado);