#include<stdio.h>

long long int max(long long int a, long long int b)
{
	if(a>b)
		return a;

	return b;
}

long long int min(long long int x, long long int y)
{
	if(x<y)
		return x;

	return y;
}

int main()
{
	long long int l1, r1, t1;
	scanf("%lld %lld %lld", &l1, &r1, &t1);

	long long int l2, r2, t2;
	scanf("%lld %lld %lld", &l2, &r2, &t2);

	long long int dif1, dif2, dif3, dif4, max1, max2, max3, max4;
	dif1=(r1-l1);
	// dif3=dif1%t1;
	dif2=(r2-l2);
	// dif4=dif2%t2;

	if(dif1>=dif2)
	{
		max1=dif1;
		// max3=dif3;
		max2=dif2;
		// max4=dif4;
	}

	else
	{
		max1=dif2;
		max2=dif1;
		// max3=dif4;
		// max4=dif3;
	}

	long long int maxf, maxf1, maxf2;

	if(max1%max2==0)
	{	
		printf("%lld\n", max1);
	}

	else
	{
		printf("%lld\n", max2);

	}

	// printf("%lld\n", maxf);
}