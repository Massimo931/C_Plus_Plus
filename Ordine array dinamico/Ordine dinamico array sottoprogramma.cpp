#include <iostream>

using namespace std;

void acquisizione_dinamica (int n, int v[]);
void stampa (int v[], int n);
void scambia (int &a, int &b);

int main()
{
	int n;
	
	cout << "Inserisci il numero di posizioni del vettore: ";
	cin >> n;
	n--;
	
	int v[n];
	
	acquisizione_dinamica (n, v);
	stampa (v, n);
	
	cout << endl;
	
	system("pause");
}

void acquisizione_dinamica (int n, int v[])
{
	int c,t,y;
	y = 1;
	
	
	for(int i = 0; i < n + 1; i++)
	{
		cout << "Inserisci il valore in posizione " << y << ": ";
		cin >> v[i];
		y++;
		
		t = i - 1;
		for(int s = i; s != 0; s--)
		{

			if(v[s] < v[t])
			{
				scambia (v[s],v[t]);
			}
			t--;
		}
	}
}

void stampa (int v[], int n)
{
	for(int m = 0; m < n + 1; m++)
	{
		cout << "| ";
		cout << v[m];
		cout << " ";
	}
	
	cout << "|";
}

void scambia (int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
