#include<stdio.h>

int main()
{
	long long int n;

	scanf("%lld", &n);

	if(n>=0)
	{
		printf("%lld", n);
	}

	else
	{
		n=n*(-1);

		if((n%10)<((n%100)/10))
		{
			long long int x= ((n/100)*10) + (n%10);
			printf("%lld", x*(-1));
		}

		else
		{
			long long int x= ((n/100)*10) + (((n%100)/10));
			printf("%lld", x*(-1));
		}

	}

	return 0;
}