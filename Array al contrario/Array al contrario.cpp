#include <iostream>

using namespace std;

int main()
{
    int n;
    int y = 1;
    
    cout << "Benvenuto nel programma di stampa al contrario di una serie di valori!\n\n";
    cout << "Per iniziare inserisci il numero di valori dell'array: ";
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; i++)
    {
    	cout << "\nInserisci il valore in posizione " << y << " di " << n << ": ";
        cin >> a[i];
        
        y++;
	}
    
    for(int i = n - 1; i >= 0; i--)
    {
        cout << "\n" << a[i];  
    }
    
    return 0;
}

