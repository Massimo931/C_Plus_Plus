#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a,b,c;
	
	cout << "Benvenuto nel programma di calcolo delle radici di un' equazione di secondo grado!\n";
	cout << "Inserisci il valore di a: ";
	cin >> a;
	cout << "Inserisci il valore di b: ";
	cin >> b;
	cout << "Inserisci il valore di c: ";
	cin >> c;
	
	int x1,x2;
	float x;
	int delta=(b*b)-4*a*c;
	
	if(delta>0 && delta!=0)
	{
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		cout << "x1 e' uguale a " << x1 <<"\n";
		cout << "x2 e' uguale a " << x2;
	}
	else
	{
		if(delta==0)
		{
			x=(-b+sqrt(delta))/(2*a);
			cout << "Il risultato e': " << x;
		}
		else
		{
			cout << "Non ammette soluzioni";;
		}
	}
	return 0;
}
