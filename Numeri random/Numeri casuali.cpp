#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand (unsigned(time(NULL)));
	
	int numeridagenerare = 10;
	for(int i = 0; i < numeridagenerare; i++)
	{
		int numerogenerato = rand() % 100;       //genera un numero casuale tra 0 a 99
		cout << numerogenerato << endl;
	}
	
	for(int i = 0; i < numeridagenerare; i++)
	{
		int numerogenerato = (rand() % 100) -50; //generea un numero casuale tra -50 e + 50;
		cout << numerogenerato << endl;
	}
	
	int x;
	cin >> x;
	
	return 0;
	
}
