#include<stdio.h>
char s[200005];

int main()
{
	long long int n;
	scanf("%lld", &n);

	scanf("%s", s);

	// long long int max=s[0];
	long long int index=n-1;

	for(long long int i=0; i<n-1; i++)
	{
		if(s[i+1]<s[i])
		{
			index=i;
			break;
		}
	}

	for(long long int j=0; j<n; j++)
	{
		if(j==index)
		{
			continue;
		}

		else
		{
			printf("%c", s[j]);
		}
	}



	return 0;
}