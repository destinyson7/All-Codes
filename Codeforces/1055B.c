#include<stdio.h>
long long int a[100005];

int main()
{
	long long int n, m, l;
	scanf("%lld %lld %lld", &n, &m, &l);

	long long int cnt=0, flag=0;

	for(long long int k=1; k<=n; k++)
	{
		scanf("%lld", &a[k]);
		a[k]-=l;

		if(a[k]>0)
		{
			flag=1;
		}

		if(flag==1 && a[k]<=0)
		{
			cnt++;
			flag=0;
		}

		if(k==n && flag==1)
		{
			cnt++;
		}
	}

	// printf("cnt is %lld\n", cnt);

	for(long long int j=1; j<=m; j++)
	{
		long long int t, p, d;
		scanf("%lld", &t);

		if(t==0)
		{
			printf("%lld\n", cnt);

		}

		else
		{
			scanf("%lld %lld", &p, &d);

			if(a[p]>0)
			{
				a[p]+=d;
			}

			else
			{
				a[p]+=d;

				// printf("%lld %lld %lld\n", a[p-1], a[p], a[p+1]);

				if(p==1 || p==n)
				{
					if(p==1)
					{
						if(a[p]>0 && a[p+1]<=0)
						{
							cnt++;
						}
					}

					else
					{
						if(a[p]>0 && a[p-1]<=0)
						{
							cnt++;
						}
					}
				}	

				else if(a[p]>0 && a[p-1]<=0 && a[p+1]<=0)
				{
					cnt++;
					// printf("cnt if %lld\n", cnt);
				}

				else
				{
					if(a[p]>0 && a[p-1]>0 && a[p+1]>0)
					{
						cnt--;	
					}
				}
			}
		}
	}

	return 0;
}