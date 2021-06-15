#include <iostream>

const int nmax = 100;

using namespace std;

void acquisizione (int vet[], int &n); //prototipo procedura che acquisisce il vettore
void visualizza (int vet[], int n); //prototipo procedura che visualizza il vettore originale
void visualizza1 (int vet[], int n); //prototipo procedura che visualizza il vettore in ordine crescente
void visualizza2 (int vet[], int n); //prototipo procedura che visualizza il vettore in ordine decrescente
void selectionsort (int vet[], int n); //prototipo procedura che ordina il vettore in ordine crescente
void selectionsort2 (int vet[], int n); //prototipo procedura che ordina il vettore in ordine decrescente
void scambia (int &a, int &b); //prototipo procedura che scambia il valore di due variabili

const int nummax=200;

int main()   //inizio programma principale   
{
	int n;
	int vet[nmax];

	acquisizione(vet,n);       //richiamo procedura acquisizione 
	visualizza (vet,n);        //richiamo procedura visualizza
	selectionsort(vet,n);      //richiamo procedura selectionsort 
	visualizza1 (vet,n);       //richiamo procedura visualizza1
	selectionsort2(vet,n);     //richiamo procedura selectionsort2 
	visualizza2 (vet,n);       //richiamo procedura visualizza2
	
	return 0;
}          //fine programma principale



void acquisizione (int vet[], int &n) //inizio procedura acquisizione
{
	int i;
	do {
		cout<<"Inserisci il numero di elementi del vettore: ";
		cin>>n;
	} while (n < 1);
	
	for(i=0;i<n;i++)
	{
		cout<<"Inserire un valore intero: ";
		cin>>vet[i];
	}
}                                       //fine procedura acquisizione

void visualizza(int vet[], int n)      //inizio procedura visualizza
{
	int i;
	cout<<"\nIl vettore originale e': ";
	
	for (i=0;i<n;i++)
	{
		cout<<vet[i];
		cout << " | ";
	}
}                                     //fine procedura visualizza

void selectionsort(int vet[], int n)  //inizio procedura selectionsort
{
	for( int i=0; i<(n-1); i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(vet[i]>vet[j])
			{
				scambia(vet[i], vet[j]);
			}
		}
	}
}                                  //fine procedura selectionsort

void selectionsort2(int vet[], int n)   //inizio procedura selectionsort2
{
	for( int i=0; i<(n-1); i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(vet[i]<vet[j])
			{
				scambia(vet[i], vet[j]);
			}
		}
	}
}                                      //fine procedura selectionsort2


void scambia (int &a, int &b)         //inizio procedura scambia
{
	int c;
	c = a;
	a = b;
	b = c;
}                                   //fine procedura scambia

void visualizza1(int vet[], int n)  //inizio procedura visualizza1
{
	int i;
	cout<<"\nIl vettore in ordine crescente e': ";
	
	for (i=0;i<n;i++)
	{
		cout<<vet[i];
		cout << " | ";
	}
}                                  //fine procedura visualizza1

void visualizza2(int vet[], int n) //inizio procedura visualizza2
{
	int i;
	cout<<"\nIl vettore in ordine decrescente e': ";
	
	for (i=0;i<n;i++)
	{
		cout<<vet[i];
		cout << " | ";
	}
}                                //inizio procedura visualizza2
