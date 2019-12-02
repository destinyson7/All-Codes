#include<stdio.h>
#include<math.h>

long long int gcd(long long int a, long long int b)
{
	if(b==0)
	{
		return a;
	}

	return gcd(b, a%b);
}

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		long long int N;
		scanf("%lld", &N);

		if(N&1)
		{
			long long int x = pow(2, N) + 1 ;
			long long int y = 3*pow(2, N);

			long long int hcf = gcd(x, y);
		
			x/=hcf;
			y/=hcf;

			printf("%lld %lld ", x, y);

		}	

		else
		{
			long long int x = pow(4, N/2) - 1;
			long long int y = 3*pow(4, N/2);

			long long int hcf = gcd(x, y);
			x/=hcf;
			y/=hcf;

			printf("%lld %lld ", x, y); 
		}	
	}

	return 0;
}