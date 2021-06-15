#include <iostream>
#include <stdlib.h>

using namespace std;

struct intlist{
	int dato;
	struct intlist * next;
};

typedef struct intlist intlist;

intlist *createlist(void);

void traverse(intlist *p);

intlist *eliminaTesta(intlist *p);

intlist *insert(intlist *p, int elem);

int main()
{
	struct intlist *root = createlist();
	
	int scelta;
	
	int valore;
	
	do{
		system("cls");
		
		cout << "Menu'\n1) Aggiungi un valore allo stack (PUSH)\n2) Rimuovi un valore dallo stack (POP)\n3) Visualizza lo stack\n4) Esci\n";
		cout << "Effettua una scelta: ";
		cin >> scelta;
	
		switch(scelta)
		{
			case 1:
				system("cls");
				
				cout << "Scrivi il dato da aggiungere allo stack (PUSH): ";
				cin >> valore;
				
				root = insert(root,valore);
				cout << "Valore aggiunto\n";
				system("pause");
				break;
				
			case 2:
				system("cls");
				
				root = eliminaTesta(root);
				
				cout << "Valore rimosso\n";
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

intlist * createlist(void)
{
	return NULL;
}

intlist *insert(intlist *p, int elem)
{
	intlist *q = (intlist *)malloc(sizeof(intlist));
	
	if(q==NULL)
	{
		printf("Errore nell'allocazione del nuovo elemento\n");
		exit(-1);
	}
	
	q->dato = elem;
	q->next = p;
	
	return q;
}

intlist *eliminaTesta(intlist *p)
{
	if(p != NULL)
	{
		intlist *q = p;
		p = p->next;
		q->next = NULL;
		free(q);
		return p;
	}
}

void traverse(intlist *p)
{
	for(;p!=NULL;p=p->next)
	{
		cout << "|\t" << p->dato << "\t|";
		cout << endl;
	}
	
	cout << endl;
}
