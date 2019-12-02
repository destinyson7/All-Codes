#include<stdio.h>
long long int arr[10005];

long long int product(long long int a, long long int b, long long int c)
{
	long long int ans=0;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans+a)%c);
		}

		b >>= 1;
		a=(a*2)%c;
	}

	return ans%c;
}

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		long long int N, K;
		scanf("%lld %lld", &N, &K);
		long long int mod = 1000000007;

		long long int flag=0;

		if(N < (K*(K+1))/2)
		{
			printf("-1\n");
		}

		else
		{

			long long int a = N - ((K*(K+1))/2);

			long long int pr;		
			long long int rem = a%K;
			long long int min = a/K;			

			for(long long int b=0; b<10005; b++)
			{
				arr[b]=0;
			}

			for(long long int i=0; i<K; i++)
			{
				arr[i]=++min;
			}

			for(long long int j=K-1; rem; j--)
			{
				arr[j]++;
				rem--;
			}

			pr=1;

			for(long long int p=0; p<K; p++)
			{
				pr=product(pr, arr[p], mod);
				pr=product(pr, arr[p]-1, mod);
			}

			// for(long long int p=0; p<K; p++)
			// {
			// 	pr=(pr*arr[p])%mod;
			// 	pr=(pr*(arr[p]-1))%mod;
			// }
		
			printf("%lld\n", pr);
		}
		
	}

	return 0;
}