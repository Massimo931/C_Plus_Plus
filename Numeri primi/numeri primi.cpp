#include <iostream>

using namespace std;

int main()
{
	int n = 2;
	int r = 0;

	cout << "| 2 |";
	

	for(int i = 0; i < 230; i++)
	{	
		for(int j = 2; n % j != 0 && j < n; j++)
		{
			if(j == n-1)
			{
				cout << " " << n << " |";		
			}																																									
		}	
		n++;
	}
	
	cout << endl;
	system("pause");
	
}
