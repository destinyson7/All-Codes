#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
	if(b==0)
		return a;

	return gcd(b, a%b);
}

int main()
{
	long long int p, q;
	scanf("%lld %lld", &p, &q);

	long long int hcf= gcd(p, q);
	// printf("hcf = %lld\n", hcf);

	long long int a= p/hcf;
	long long int b = q/hcf;

	if(b==1 || b==2)
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}