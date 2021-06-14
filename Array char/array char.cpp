#include <iostream>
#define MAX_CARATTERI 20

using namespace std;

int main()
{
	char parola[MAX_CARATTERI];
	
	
	for(int i = 0; i < MAX_CARATTERI; i++)
	{
		parola[i] = '\0';
	}
	
	cout << "Inserisci un parola: ";
	cin >> parola;
	cout << "Hai inserito la parola: " << parola << endl;	
	
	for(int i = 0; i < MAX_CARATTERI; i++)
	{
		cout << (i+1) <<"' carattere = " << parola[i] << endl;
	}

	return 0;
}
