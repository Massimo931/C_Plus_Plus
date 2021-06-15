#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int funzione_somma (int a, int b);

int main()
{
	int a, b;
	
    cout << "Inserisci i valori che vuoi sommare";
    cout << "\n\nInserisci il primo valore: ";
    cin >> a;
    cout << "\nInserisci il secondo valore: ";
    cin >> b;
    cout << "\nIl risultato e' " << funzione_somma(a, b);

    return 0;
}

int funzione_somma (int a, int b)
{
    int c;
    c = a + b;
    return c;
}
