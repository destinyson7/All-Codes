#include<stdio.h>
long long int arr[100005];
long long int L[100005], R[100005];

int main()
{
	long long int N, Q;
	scanf("%lld %lld", &N, &Q);

	for(long long int i=0; i<N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for(long long int j=1; j<=Q; j++)
	{
		scanf("%lld %lld", &L[j], &R[j]);
	}

	for(long long int k=1; k<=Q; k++)
	{
		
	}

	return 0;
}