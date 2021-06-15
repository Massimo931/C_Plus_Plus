#include <iostream>
#include <stdlib.h>
#define N 5

using namespace std;

int main()
{
	char parola[N];
	int numero;
	
	cout << "Inserisci un numero di massimo " << N << " cifre: ";
	cin >> parola;
	cout << "Hai inserito la parola: " << parola << endl;
	
	numero = atoi(parola);

	cout << "Adesso e' un intero: " << numero << endl;
	
	cout << endl;
	
	return 0;
	
}
