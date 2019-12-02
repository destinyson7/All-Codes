#include<stdio.h>
#include<math.h>
long long int isprime[100005];
long long int primes[100005];

// void subtrate(long long int n, long long int cnt[])
// {
// 	if(n==0)
// 	{
// 		return;
// 	}

// 	n-=lp[n];
// 	cnt[0]++;

// 	return subtrate(n, cnt);

// }

int main()
{
	long long int n, cnt=0, cp=0;
	scanf("%lld", &n);

	for(long long int i=2; i<=100000; i++)
	{
		if(isprime[i]==0)
		{
			primes[cp++]=i;
			for(long long int j=2*i; j<=100000; j+=i)
				isprime[j]=1;
		}
	}

	// for(int i=2;i<100005;i++)
	// {
	// 	if(lp[i]==0)
	// 	{
	// 		lp[i]=i;
	// 		for(int j=2*i;j<100005;j+=i)
	// 		{
	// 			if(lp[j]==0)
	// 				lp[j]=i;
	// 		}
	// 	}
	// }

	// printf("lp[5] is %lld\n", isprime[5]);
	// long long int flag=0;

	if(n&1)
	{
		for(long long int k=0; k<cp && n>0 && n&1; k++)
		{
			if(n%primes[k]==0)
			{
				n-=primes[k];
				// printf("%lld\n", n);
				cnt++;
			}
		}
	}

	if(n%2==0)
	{
		cnt+=n/2;
		n=0;
	}

	if(n)
	{
		cnt++;
	}

	printf("%lld\n", cnt);

	return 0;
}