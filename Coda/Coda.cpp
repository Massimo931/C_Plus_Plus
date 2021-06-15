#include <iostream>
#include <stdlib.h>

using namespace std;

struct stringlist{
	char Nome[100];
	struct stringlist * next;
};

typedef struct stringlist stringlist;

stringlist *createlist(void);

void traverse(stringlist *p);

void insertCoda(stringlist *&p, char elem[100]);

stringlist *eliminaTesta(stringlist *p);

int main()
{
	struct stringlist *root = createlist();
	
	int scelta;
	
	char nominativo[100];
	
	do{
		system("cls");
		
		cout << "Menu'\n1) Aggiungi un nome alla coda\n2) Rimuovi un nome alla coda\n3) Visualizza la coda\n4) Esci\n";
		cout << "Effettua una scelta: ";
		cin >> scelta;
	
		switch(scelta)
		{
			case 1:
				system("cls");
				
				cout << "Scrivi il nome della persona da aggiungere alla coda: ";
				cin >> nominativo;
				
				insertCoda(root, nominativo);
				cout << "Nominativo aggiunto\n";
				system("pause");
				break;
				
			case 2:
				system("cls");
				
				root = eliminaTesta(root);
				
				cout << "Nominativo rimosso\n";
				system("pause");
				break;
				
			case 3:
				system("cls");
				
				traverse(root);
				
				cout << endl;
				
				system("pause");
				break;
				
			case 4:
				exit(1);
					break;
					
			default:
				cout << "Comando non valido, riprova.\n";
				system("pause");
				break;
			
		}
	}while(scelta != 0);
	
	return 0;
}

stringlist * createlist(void)
{
	return NULL;
}

void insertCoda(stringlist *&p, char elem[100])
{
	stringlist *q = (stringlist *)malloc(sizeof(stringlist));
	if(q==NULL) {
		cout << "Errore nell'allocazione del nuovo elemento\n";
		exit(-1);
	}
	
	
	for(int i = 0; i < 100; i++)
	{
		q->Nome[i]= elem[i];
	}
	
	q->next = NULL;
	
	if (p==NULL)
	{
		p=q;
	}
	
	else
	{
		stringlist *r;
		for(r = p; r->next!=NULL; r = r->next);
		r->next=q;
	}
}

stringlist *eliminaTesta(stringlist *p)
{
	if(p != NULL)
	{
		stringlist *q = p;
		p = p->next;
		q->next = NULL;
		free(q);
		return p;
	}
}

void traverse(stringlist *p)
{
	for(;p!=NULL;p=p->next)
	{
		cout << p->Nome;
		cout << "\t";
	}
	
	cout << endl;
}
