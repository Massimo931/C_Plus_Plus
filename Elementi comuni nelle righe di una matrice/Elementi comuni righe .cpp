
//Arnoni Massimo 3F

#include <iostream>
#define nrmax 100
#define ncmax 100

using namespace std;

void acquisizione (int m[nrmax][ncmax], int &nr, int &nc, int v[]);
void uguali(int m[nrmax][ncmax], int &nr, int &nc, int v[], int h[]);
void visualizzazione (int m[nrmax][ncmax], int &nr, int &nc, int v[], int h[]);

int main()
{
	int m[nrmax][ncmax];
	int v[nrmax];
	int h[ncmax];
	int nr,nc;
	
	acquisizione(m, nr, nc,v);
	uguali(m, nr, nc, v, h);
	visualizzazione(m, nr, nc, v, h);
	
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
	
	for(int ic = 0; ic < nc; ic++)
	{
		cout << "Inserisci un valore nel vettore: ";
		cin >> v[ic];	
	}
}

void visualizzazione (int m[nrmax][ncmax], int &nr, int &nc, int v[], int h[])
{
	for(int ir = 0; ir < nr; ir++)
	{
		cout << "Matrice:	";
		for(int ic = 0; ic < nc; ic++)
		{
			cout << m[ir][ic] << "	|	";
		}
		cout << endl;
	}
	
	cout << "\nVettore:   ";
	
	for(int ic = 0; ic < nc; ic++)
	{
		cout << v[ic] << "	|	";
	}
	
	cout << endl;
	
	for(int ic = 0; ic < nc; ic++)
	{
		cout << "I valori in comune nelle righe della matrice sono: ";
		cout << h[ic] << endl;
	}
}

void uguali(int m[nrmax][ncmax], int &nr, int &nc, int v[], int h[])
{
	int f;
	
	for(int ic = 0; ic < nc; ic++)
	{
		f = 0;
		for(int ir = 0; ir < nr; ir++)
		{
			if(m[ir][ic] == v[ic])
			{
				f++;
			}
		}
		h[ic] = f;
	}
}
