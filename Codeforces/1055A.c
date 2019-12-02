#include<stdio.h>
long long int f[1005];
long long int b[1005];
long long int flag2[1005];

int main()
{
	long long int n, s;
	scanf("%lld %lld", &n, &s);

	long long int flag1=0, flag3=0;

	for(long long int i=1; i<=n; i++)
	{
		scanf("%lld", &f[i]);
		if(f[1]==1)
		{
			if(i==s && f[i]==1)
			{
				flag1=1;
			}
		}

		if(i>s && f[1]==1)
		{
			if(f[i]==1)
			{
				flag2[i]=1;
				// idx[cnt++]=i;
			}
		}
	}

	for(long long int j=1; j<=n; j++)
	{
		scanf("%lld", &b[j]);

		if(j==s)
		{
			if(b[j]==1 && f[1]==1)
			{
				flag3=1;
			}
		}
	}

	if(flag3)
	{
		for(long long int k=n; k>=s; k--)
		{
			if(f[k]==1 && b[k]==1)
			{
				flag1=1;
			}
		}
	}

	if(flag1)
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}