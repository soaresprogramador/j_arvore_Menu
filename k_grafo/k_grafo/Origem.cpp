#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct vtc
{
	char r;
	struct adj *a;
	struct vtc *p;
};

struct adj
{
	struct vtc *d;
	struct adj *p;
};

struct vtc *g;
char menu();
void pausa();
void inserir_vertice();
void pesquisar_vertice();
void listar_vertices();
void inserir_adjacencia();
struct vtc * inserir_vertice_no(char);
struct vtc * pesquisar_vertice_no(char);

int main()
{
	char op;
	g = NULL;
	do
	{
		op = menu();
	} while (op != '0');
}

char menu()
{
	char op;
	printf("\n---------------------------------------\n");
	printf("\tMENU\n");
	printf("---------------------------------------\n");
	printf("0 - ENCERRAR\n");
	printf("1 - INSERIR VERTICE\n");
	printf("2 - LISTAR VERTICES\n");
	printf("3 - PESQUISAR VERTICES\n");
	printf("\nEscolha uma opcao\n");
	op = _getch();
	switch (op)
	{
	case '0':
		break;
	case '1':
		inserir_vertice();
		break;
	case '2':
		listar_vertices();
		break;
	case '3':
		pesquisar_vertice();
		break;
	default:
		printf("\nEscolha uma opcao\n");
		pausa();
		break;
	}
	return op;
}

void pausa()
{
	printf("\nTecle algo...");
	_getch();
}



/*void titulo(char *texto)
{
	system("cls");
	printf("---------------------------------------\n");
	printf("%s\n", texto);
	printf("---------------------------------------\n");
}*/

void inserir_vertice()
{
	struct vtc *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tINSERIR VERTICE\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo: ");
	scanf_s("%p", &r);
	_getch();
	aux = inserir_vertice_no(r);
	if (aux != NULL)
		printf("\nInserido com sucesso no endereco: %p", aux);
	else
		printf("\nErro na insercao!\n");
	pausa();
}


void listar_vertices()
{
	struct vtc*aux;
	printf("\n---------------------------------------\n");
	printf("\tLISTAR VERTICES\n");
	printf("---------------------------------------\n");
	aux = g;
	while (aux != NULL)
	{
		printf("\n%p - %c", aux, aux->r);
		aux = aux->p;
	}
	pausa();
}

void pesquisar_vertice()
{
	struct vtc *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tPESQUISAR VERTICE\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo: ");
	r = _getche();
	printf("\n");
	aux = pesquisar_vertice_no(r);
	if (aux != NULL)
		printf("\nInserido com sucesso no endereco: %p", aux);
	else
		printf("\nNao encontrado!\n");
	pausa();
}

void inserir_adjacencia()
{
	struct vtc *o, *d;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tINSERIR ADJACENCIA\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo de origem: ");
	r = _getche();
	printf("\n");
	o = pesquisar_vertice_no(r);
	if (o == NULL)
	{
		printf("Informe o rotulo de destino: ");
		r = _getche();
		printf("\n");
		d = pesquisar_vertice_no(r);
		if (d != NULL)
		{

		}
	}

	else
	{
		aux = g;
		while (aux->p != NULL)
			aux = aux->p;
		aux->p = novo;
	}
}

struct vtc * pesquisar_vertice_no(char r)
{
	struct vtc *aux;
	aux = g;
	while (aux != NULL && aux->r != r)
		aux = aux->p;
	return aux;
}

struct vtc * inserir_vertice_no(char r)
{
	struct vtc *novo, *aux=nullptr;
	novo = (struct vtc *)malloc(sizeof(struct vtc));
	if (novo != NULL)
	{
		novo->r = r;
		novo->a = NULL;
		novo->p = NULL;
		if (g == NULL)
		{
			g = novo;
			aux = g;
		}

		else
		{
			aux = g;
			while (aux->p != NULL)
				aux = aux->p;
			aux->p = novo;
		}

	}
	return aux;
}
