#include <iostream>
#include <cmath>

using namespace std;

float somma (float a, float b);
void acquisizione (float &a, float &b);
void presentazione ();
float media (float a, float b);

int main()
{
	float valf, vals;
	
	presentazione ();
	acquisizione (valf, vals);
	cout << "\nLa somma e': " << somma (valf, vals);
	cout << "\nLa media e': " << media (valf, vals);
	
	
	
}

void presentazione ()
{
	cout << "	Benvenuto nel programma di calcolo della media aritmetica di due numeri!";
}

void acquisizione (float &a, float  &b)
{
	cout << "\n\nInserisci il primo valore: ";
	cin >> a;
	cout << "\nInserisci il secondo valore: ";
	cin >> b;	
}

float somma (float a, float b)
{
	float c;
	c = a + b;
	return c;
}

float media (float a, float b)
{
	float media;
	media = (a + b) / 2;
	return media;
}
