#include<stdio.h>

int main()
{
	long long int n, m, a, b;
	scanf("%lld %lld %lld %lld", &n, &m, &a, &b);

	if(b>(m*a))
	{
		printf("%lld", n*a);
	}

	else
	{
		if(n%m==0)
		{
			printf("%lld", (n/m)*b);
		}

		else if((n%m)*a<b)
		{
			printf("%lld", (n/m)*b + (n%m)*a);
		}

		else
		{
			printf("%lld", ((n/m)+1)*b);
		}


	}

	return 0;
}