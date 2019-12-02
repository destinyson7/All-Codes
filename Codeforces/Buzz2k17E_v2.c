#include<stdio.h>
long long int isprime[1000005];
long long int arr[1000005];
long long int sumprime[1000005];

int main()
{
	long long int e=0; 

	for(long long int k=2; k<1000005; k++)
	{
		isprime[k]=1;
	}

	for(long long int i=2; i<1000005; i++)
	{
		if(isprime[i]==1)
		{
			arr[++e]=i;

			for(long long int j=2*i; j<=1000000; j+=i)
			{
				isprime[j]=0;
			}

		}

		sumprime[i]=e;
	}

	long long int q;
	scanf("%lld", &q);

	while(q--)
	{
		long long int a, b, k=0;
		scanf("%lld %lld", &a, &b);

		// for(long long int c=a; c<=b; c++)
		// {
		// 	if(isprime[c]==1)
		// 	{
		// 		arr[++k]=c;
		// 	}
		// }

		k=sumprime[b]-sumprime[a-1];

		if(k==0)
		{
			printf("-1\n");
		}

		else if(k&1)
		{
			printf("%lld\n", arr[(sumprime[a-1] + ((k+1)/2))]);
		}

		else
		{
			printf("%lld\n", arr[(sumprime[a-1] + (k/2))]);
		}

	}

	return 0;
}