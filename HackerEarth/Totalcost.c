#include<stdio.h>

int main()
{
	long long int P, S, T, H, x;
	scanf("%lld %lld %lld %lld %lld", &P, &S, &T, &H, &x);

	long long int cost=0;

	if(x < (S-T))
	{
		cost = P*x;
	}

	// printf("cost= %lld\n", cost);

	else
	{
		cost+= P*(S-T);
		// printf("cost= %lld\n", cost);		 
		cost+= H*(x-S+T);
	}

	printf("%lld\n", cost);

	return 0;
}