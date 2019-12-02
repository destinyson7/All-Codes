#include<stdio.h>
#include<math.h>

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int ans=0;

	for(long long int i=1; i<=n; i++)
	{
		ans+=powl(2,i);
	}

	printf("%lld\n", ans);

	return 0;
}