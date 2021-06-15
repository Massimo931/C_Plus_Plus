#include <iostream>

using namespace std;

int main()
{
	int x1,x2,y1,y2,m,q;
	
	cout << "Inserisci le coordinate del primo punto:\nx1: ";
	cin >> x1;
	cout << "\ny1: ";
	cin >> y1;
	cout << "Inserisci le coordinate del secondo punto:\nx2: ";
	cin >> x2;
	cout << "\ny2: ";
	cin >> y2;
	
	
	m=(y1-y2)/(x1-x2);
	
	q=y1-(m*x1);
	
	cout << "y=" << m <<"x+" << q;
}
