#include<stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		long long int N;
		scanf("%lld", &N);

		printf("%lld\n", (N+1)/2);
	}

	return 0;
}