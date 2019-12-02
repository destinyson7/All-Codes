#include<stdio.h>

int main()
{
	long long int P, Q;
	scanf("%lld %lld", &P, &Q);

	if(P==1 && Q!=1)
	{
		printf("A\n");
	}

	else if(P!=1 && Q==1)
	{
		printf("A\n");
	}

	else if(P==1 && Q==1)
	{
		printf("B\n");
	}

	else if((P+Q-4)&1)
	{
		printf("A\n");
	}

	else
	{
		printf("B\n");
	}

	return 0;
}