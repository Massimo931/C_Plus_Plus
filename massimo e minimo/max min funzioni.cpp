#include <iostream>

using namespace std;

int max(int a, int max);
int min(int a, int min);

int main()
{
	int n,a,massimo,minimo,x;
	
	cout << "Quanti numeri si desidera inserire? ";
	cin >> n;
	for(int i=1; i<n+1; i++)
	{
		cout << "Inserisci il valore numero " << i << " : ";
		cin >> a;
		
		if(i == 1)
		{
			massimo = a;
			minimo = a;
		}
		
		massimo=max(a,massimo);
		minimo=min(a,minimo);
	}
	
	cout << "Il valore minimo e': " << minimo << endl;
	cout << "Il valore massimo e': " << massimo << endl;
	cin >> x;
	
	cout << endl;
	system("pause");
	
	return 0;
	
}

int max(int a, int max)
{
	if(a>max)
	{
		max=a;
		return max;
	}
	else
	{
		return max;
	}
}

int min(int a, int min)
{
	if(a<min)
	{
		min=a;
		return min;
	}
	else
	{
		return min;
	}
}
