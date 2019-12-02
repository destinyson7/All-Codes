#include<stdio.h>

long long int isprime[205];
long long int issemiprime[205];

int main()
{
	long long int T;
	scanf("%lld", &T);	

	while(T--)
	{
		long long int N;
		scanf("%lld", &N);

		for(long long int i=2; i<=N; i++)
		{	
			isprime[i]=1;
		}
	
		for(long long int j=2; j<=N; j++)
		{
			if(isprime[j]==1)
			{
				for(int k=2*j; k<=N; k+=j)
				{
					isprime[k]=0;
				}
			}
		}

		for(long long int b=2; b<=N; b++)
		{
			for(long long int d=2; d<=N; d++)
			{
				if(isprime[d]==1)
				{
					if((b%d==0) && ((b/d)!=d))
					{
						long long int c= b/d;

						if(isprime[c]==1)
						{
							issemiprime[b]=1;
							// issemiprime[c]=1;
						}
					}
				}
			}
		}

		long long int flag=0;

		for(long long int a=1; a<=N; a++)
		{
			if(issemiprime[a]==1)
			{
				if(issemiprime[N-a]==1)
				{
					flag=1;
					// printf("a=%lld N-a=%lld\n",a, N-a);
					break;
				}
			}
		}

		if(flag==1)
		{
			printf("YES\n");
			flag=0;
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}