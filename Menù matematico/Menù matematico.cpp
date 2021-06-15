#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	int scelta;
	float x;
	
	
	do{
		cout << "1\til quadrato\n2\tla radice quadrata\n3\tl'inverso\n4\tl'opposto\n5\til cubo\n0\tesci dal programma\nScegli l'operazione da fare:\t";
		cin >> scelta;
		
		if(scelta != 0 )
		{
			cout << "Inserisci un numero:\t";
			cin >> x;
			
			switch(scelta)
			{
				case 1:
					x = pow(x,2);
					cout << "Il quadrato e':\t" << x <<endl;
					system("pause");
					system("cls");
					break;
				case 2:
					x = sqrt(x);
					cout << "La radice quadrata e':\t" << x<<endl;
					system("pause");
					system("cls");
					break;
				case 3:
					if(x>0)
					{
						cout << "L'inverso e':\t1/" << x<<endl;
					}
					
					else if(x<0)
					{
						x = x-(x*2);
						cout << "L'inverso e':\t-1/" << x<<endl;
					}
					
					else if(x==0)
					{
						cout << "L'inverso e':\t" << x<<endl;
					}
					system("pause");
					system("cls");
					break;
				case 4:
					x = x - (x*2);
					cout << "L'opposto e':\t" << x<<endl;
					system("pause");
					system("cls");
					break;
				case 5:
					x = pow(x,3);
					cout << "Il cubo e':\t" << x<<endl;
					system("pause");
					system("cls");
					break;	
				default:
					cout << "scelta non valida, riprovare."<<endl;
					system("pause");
					system("cls");
					break;
			}
		}
	}while(scelta!=0);
	
	system("cls");
	cout << "Fine programma";
}
