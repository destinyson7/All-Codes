#include<stdio.h>

typedef long long int ll;

ll isprime[1000005];
ll primes[1000005];
ll cnt1[1000005];

unsigned int nextPowerOf2(unsigned int n) 
{ 
unsigned count = 0; 

if (n && !(n & (n - 1))) 
    return n; 
  
while( n != 0) 
{ 
    n >>= 1; 
    count += 1; 
} 
  
return 1 << count; 
}

int main()
{
	ll n, cnt=0;
	scanf("%lld", &n);

	ll n2 = n;

	for(int i=2;i<=n;i++)
	{
		// printf("1\n");
		if(isprime[i]==0)
		{
			// printf("2\n");
			primes[cnt++]=i;

			for(int j=2*i;j<=n;j+=i)
				isprime[j]=1;
		}
	}
	ll max=0, min=1000005, flag=0;
	// printf("cnt %lld\n", cnt);
	for(ll k=0; k<cnt; k++)
	{
		// printf("n %lld\n", n);
		while(n%primes[k]==0)
		{
			cnt1[k]++;

			if(cnt1[k]>max)
				max=cnt1[k];

			flag=1;

		

			n/=primes[k];
			// printf("%lld\n", n);
		}

			if(cnt1[k]<min && flag==1)
				min=cnt1[k];

			flag=0;
	}
	// printf("max %lld\n", max);
	ll ans=1;
	for(ll a=0; a<cnt; a++)
	{
		if(cnt1[a])
		{
			ans*=primes[a];
		}
	}
	// printf("min %lld max%lld\n", min, max);
	ll ans2=0;

	if(n2==1)
	{
		printf("1 0\n");
	}

	else if(max>min)
	{	
		// if(min==1)
		// 	ans2++;

		min=max;
		if(min)
		{
			// if(nextPowerOf2(min)==min)
			// 	ans2--;

			min=nextPowerOf2(min);
			// printf("min is %lld\n", min);

			if(min==1)
				min++;

			ans2++;
			while(min!=1)
			{
				ans2++;
				// printf("ans2 %lld\n", ans2);
				min/=2;
				// printf("min %lld\n", min);
			}	

			max=min;
		}

		printf("%lld %lld\n", ans, ans2);
	}

	else if(min>1)
	{	
		if(nextPowerOf2(min)==min && min!=1)
			ans2--;

		min=nextPowerOf2(min);

		if(min==1)
			min++;

		ans2++;
		while(min!=1)
		{
			ans2++;
			// printf("ans2 %lld\n", ans2);
			min/=2;
			// printf("min %lld\n", min);
		}

		max=min;

		printf("%lld %lld\n", ans, ans2);
	}	
	// ans2=min;

	else
	{
		ans2=0;

	// printf("ans2 is %lld\n", ans2);
	// max-=min;
	// printf("max %lld\n", max);
	// max--;

		printf("%lld %lld\n", ans, ans2);

	}





	return 0;
}