#include <iostream>

using namespace std;

int main()
{
	int n,c;
	
	cout << "Inserisci un numero: ";
	cin >> n;
	
	for(int i=2; i<n; i++)
	{
		if(n % i != 0)	
		{
			c++;
		}
	}	
	
	if(c == n-2)
	{
		cout << "Il numero " << n << " e' primo.";
	}
	else
	{
		cout << "Il numero " << n << " non e' primo.";
	}
	
	cout << endl;
	system("pause");
}
