
//Arnoni Massimo 3F

#include <iostream>
#define nrmax 100
#define ncmax 100

using namespace std;

void acquisizione (int m[nrmax][ncmax], int &nr, int &nc, int v[]);
void uguali(int m[nrmax][ncmax], int &nr, int &nc, int v[], int g[]);
void visualizzazione (int m[nrmax][ncmax], int &nr, int &nc, int v[], int g[]);

int main()
{
	int m[nrmax][ncmax];
	int v[nrmax];
	int g[nrmax];
	int nr,nc;
	
	acquisizione(m, nr, nc,v);
	uguali(m, nr, nc, v, g);
	visualizzazione(m, nr, nc, v, g);
	
	cout << endl;
	system("pause");
	
	return 0;
}



void acquisizione(int m[nrmax][ncmax], int &nr, int &nc, int v[])
{
	cout << "Inserisci le dimensioni della matrice.\n";
	do{
		cout << "Righe: ";
		cin >> nr;
		cout << "Colonne: ";
		cin >> nc;
		
		if(nr > 99 || nc > 99)
		{
			cout << "Ti preghiamo di inserire valori inferiori a 100.";
			cout << endl;
			system("pause");
		}	
		
	}while(nr > 99 || nc > 99);
	
	for(int ir = 0; ir < nr; ir++)
	{
		for(int ic = 0; ic < nc; ic++)
		{
			cout << "Inserisci un valore nella matrice: ";
			cin >> m[ir][ic];
		}
	}
	
	for(int ir = 0; ir < nr; ir++)
	{
		cout << "Inserisci un valore nel vettore: ";
		cin >> v[ir];	
	}
}

void visualizzazione (int m[nrmax][ncmax], int &nr, int &nc, int v[], int g[])
{
	for(int ir = 0; ir < nr; ir++)
	{
		cout << "Matrice:	";
		for(int ic = 0; ic < nc; ic++)
		{
			cout << m[ir][ic] << "	|	";
		}
		cout << "	Vettore:  ";
		cout << v[ir];
		cout << "	I valori in comune nelle colonne della matrice sono: ";
		cout << g[ir] << "		";
		cout << endl;
	}
}

void uguali(int m[nrmax][ncmax], int &nr, int &nc, int v[], int g[])
{
	int y;
	
	for(int ir = 0; ir < nr; ir++)
	{
		y = 0;
		for(int ic = 0; ic < nc; ic++)
		{
			if(m[ir][ic] == v[ir])
			{
				y++;
			}
		}
		g[ir] = y;
	}
}
