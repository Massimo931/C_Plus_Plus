#include <stdio.h>
#include <iostream>
#define RM 100
#define CM 100

using namespace std;

void acquisizione (int m[RM][CM], int &nr, int &nc);
void visualizzazione (int m[RM][CM], int nr, int nc, float a[RM], int max[RM], int min[RM]);
void media (int m[RM][CM], float a[RM], int nr, int nc);
void maxmin (int m[RM][CM], int max[RM], int min[RM], int nr, int nc);

int main()
{
	int m[RM][CM];
	int nr,nc;
	float a[RM];
	int max[RM];
	int min[RM];
	
	acquisizione (m, nr, nc);
	media (m, a, nr, nc);
	maxmin (m, max, min, nr, nc);
	visualizzazione (m, nr, nc, a, max, min);
	
	system ("pause");
	return 0;
}

void acquisizione (int m[RM][CM], int &nr, int &nc)
{
	printf("Inserisci le dimensioni della matrice.\n");
	printf("Righe: ");
	scanf("%d", &nr);
	printf("Colonne: ");
	scanf("%d", &nc);
	
	for(int ir = 0; ir < nr; ir++)
	{
		for(int ic = 0; ic < nc; ic++)
		{
			printf("Inserisci un valore: ");
			scanf("%d", &m[ir][ic]);
		}
	}
}

void media (int m[RM][CM], float a[RM], int nr, int nc)
{
	int somma;
	float med;
	for(int ir = 0; ir < nr; ir++)
	{
		somma = 0;
		for(int ic = 0; ic < nc; ic++)
		{
			somma = somma + m[ir][ic];
		}
		med = somma / nc;
		a[ir] = med;
	}
}

void maxmin (int m[RM][CM], int max[RM], int min[RM], int nr, int nc)
{	
	for(int ir = 0; ir < nr; ir++)
	{
		max[ir] = m[ir][0];
		min[ir] = m[ir][0];
		
		for(int ic = 0; ic < nc; ic++)
		{
			if(m[ir][ic] > max[ir])
			{
				max[ir] = m[ir][ic];
			}
			
			else if(m[ir][ic] < min[ir])
			{
				min[ir] = m[ir][ic];
			}
		}
	}
}

void visualizzazione (int m[RM][CM], int nr, int nc, float a[RM], int max[RM], int min[RM])
{
	for(int ir = 0; ir < nr; ir++)
	{
		for(int ic = 0; ic < nc; ic++)
		{
			printf("%d\t", m[ir][ic]);
		}
		
		printf("%f\t", a[ir]);
		printf("%d\t", max[ir]);
		printf("%d\t", min[ir]);
		printf("\n");
	}
}
