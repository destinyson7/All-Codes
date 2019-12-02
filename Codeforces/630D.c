#include<stdio.h>

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int ans=1;

	ans += 3*n*(n+1);

	printf("%lld\n", ans);

	return 0;
}