#include <iostream>

using namespace std;

int main()
{
	int vet[9];
	int x = 1;
	int pari = 0;
	int dispari = 0;
	
	
	for(int i = 0; i<10; i++)
	{
		cout << "Inserisci il numero in posizione " << x << ": ";
		cin >> vet[i];
		x++;
	}
	
	for(int i = 0; i<10; i++)
	{
		cout << " " << vet[i] << " |";
	}
	
	for(int i = 0; i<10; i++)
	{
		if(vet[i] % 2 == 0)
		{
			pari++;
		}
		
		if(vet[i] % 2 == 1)
		{
			dispari++;
		}
	}
	
	cout << "\n\nI numeri pari sono: " << pari;
	cout << "\n\nI numeri dipari sono: " << dispari;
	cout << "\n\n";
	
	system("pause");
	
	return 0;
}
