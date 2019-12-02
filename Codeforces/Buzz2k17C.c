#include<stdio.h>
long long int arr[100005];

long long int gcd(long long int x, long long int y)
{
	if(y==0)
	{
		return x;
	}

	return gcd(y, x%y);
}

int main()
{
	long long int N;

	// printf("gcd of 4 8 is %lld\n", gcd(4,8));

	scanf("%lld", &N);

	for(long long int i=0; i<N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long int hcf=arr[0];

	for(long long int j=0; j<N; j++)
	{
		hcf=gcd(hcf, arr[j]);
	}

	if(hcf==1)
	{
		printf("%lld\n", N);
		for(long long int j=0; j<N; j++)
		{
			printf("%lld ", arr[j]);
		}
	}

	else
	{
		printf("-1\n");
	}

	return 0;
}