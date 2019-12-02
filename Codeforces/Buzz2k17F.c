#include<stdio.h>
long long int arr[505];

int main()
{
	long long int N, K;
	scanf("%lld %lld", &N, &K);

	for(long long int i=0; i<N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	return 0;
}