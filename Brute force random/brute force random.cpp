#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#define MAX 10

using namespace std;

int main()
{
	char carattere;
	char p[MAX];
	char r[MAX];
	int z,j;
	int numero,indicerandom,f;
	for(int i = 0; i < MAX; i++)
	{
		p[i] = '\0';
		r[i] = '\0';
	}

	cout << "Inserisci il tuo pin: ";
	cin >> p;	
	
	z = atoi(p);

	srand (unsigned(time(NULL)));
	
	while(z != j)
	{
		for(int i = 0; i < MAX; i++)
		{
			r[i] = '\0';
		}
		
		f = rand() % 10;
		indicerandom = f;
		cout << indicerandom << "		";
		
		for(int i = 0; i <= indicerandom; i++)
		{
			numero = rand() % 10;
			stringstream ss;  
	  		ss<<numero;  
	  		char s;  
	  		ss>>s;
	  		
			r[i] = s;
		}
 	
		j = atoi(r);

		cout << "		" << j;
		cout << "\n";		
	}
	
	cout << "Il pin inserito e': " << j;	

	cout << endl;
	system("pause");
	
	return 0;
}
