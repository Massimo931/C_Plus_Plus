#include <stdio.h>
#define MAX 1000

void palindroma();

int main()
{
	palindroma();
		
	return 0;
}


void palindroma()
{
	char s[MAX];
	int i;
	int j;
	int n;
	bool palindroma;
	
	printf("Inserisci una parola: ");
	scanf("%s", &s);
		
	for(i=0; s[i]!='\0'; i++)
	{
		j = i;
	}
	
	n = j;
	
	if(n > 0)
	{
		for(i=0; i != n; i++, j--)
		{
			if(s[i] != s[j])
			{
				palindroma = false;
				break;
			}
			
			else
			{
				palindroma = true;
			}
		}
		
		if(palindroma == false)
		{
			printf("La parola non e' palindroma.\n\n");	
		}
			
		else
		{
			printf("La parola e' palindroma.\n\n");
		}		
	}
	
	else
	{
		printf("La parola e' palindroma.\n\n");
	}	
}
