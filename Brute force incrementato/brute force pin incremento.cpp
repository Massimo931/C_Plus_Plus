#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#define MAX 9999999999

using namespace std;

int main()
{
	int z,j;
	j = 0;

	do{

		cout << "Inserisci il tuo pin: ";
		cin >> z;
	
	}while(z >= MAX);	
	
	srand (unsigned(time(NULL)));
	
	while(z != j)
	{
		j++;
		cout << j;
		cout << "\n";		
	}
	
	cout << "Il pin inserito e': " << j;	

	cout << endl;
	system("pause");
	
	return 0;
}
