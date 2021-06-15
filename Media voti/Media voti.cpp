#include <iostream>
#include <cmath>

//Inserire 0 per terminare

using namespace std;

int main()
{
	float somma,voto,media;
	int numvoti;
	somma=0;
	numvoti = 0;
	
	cout << "Benvenuto nel programma di calcolo della media dei voti\n";
	
	do{
		cout << "Inserisci voto: ";
		cin >> voto;
		somma = somma + voto;
		numvoti = numvoti + 1;
	}while(voto!=0);
	
	numvoti=numvoti-1;
	
	if(numvoti != 0)
	{
		media=somma/numvoti;
		cout << "La media e': " << media;
	}
	else
	{
		cout << "L'elenco e' vuoto!";
	}
	
	cout << endl;
	system("pause");
	
	return 0;
}
