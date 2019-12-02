#include<stdio.h>

int main()
{
	long long int N;
	scanf("%lld", &N);
	
	long long int X, Y, Z;

	if(N&1)
	{
		X=1;
		Y=3;
		Z=N-4;

		if(X<Y && Y<Z)
		{
			printf("%lld %lld %lld", X, Y, Z);
		}

		else
		{
			printf("-1");
		}
	}

	else
	{
		X=2;
		Y=4;
		Z=N-6;

		if(X<Y && Y<Z)
		{
			printf("%lld %lld %lld", X, Y, Z);
		}

		else
		{
			printf("-1");
		}
	}

	return 0;
}