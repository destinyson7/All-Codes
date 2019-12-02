#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int T;
	scanf("%lld", &T);

	T%=30;
	T++;

	srand(T);

	printf("%lld\n", T);

	while(T--)
	{
		long long int N = rand();
		N%=1000;
		N++;

		printf("%lld\n", N);

		for(long long int j=0; j<N; j++)
		{
			printf("%lld ", rand()%(2*N) + 1);
		}
		printf("\n");
	}

	return 0;
}