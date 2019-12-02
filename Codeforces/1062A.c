#include<stdio.h>

typedef long long int ll;

ll arr[105];

int main()
{
	ll n;
	scanf("%lld", &n);

	for(ll i=0; i<n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	ll cnt=1, flag=0, max=1, flag2=0, cnt2=0;

	for(ll j=0; j<n-1; j++)
	{
		if(arr[j+1]-arr[j] == 1)
		{
			if(j==0)
			{	
				if(arr[0]==1)
					cnt2=1;
				// cnt++;
			}	

			if(j==n-2)
			{
				if(arr[n-1]==1000)
					cnt2=1;
			}
			cnt++;
			// printf("cnt is %lld\n", cnt);
			flag=1;
		}

		else if(flag==1)
		{
			if(cnt+cnt2>max)
			{
				max=cnt+cnt2;
				cnt2=0;
				flag2=1;
				// printf("flag2 %lld\n", flag2);
			}

			// printf("max main %lld\n", max);
			cnt=1;
			flag=0;
		}

		if(j==n-2 && flag==1)
		{
			if(cnt+cnt2>max)
			{
				max=cnt+cnt2;
				// cnt2=0;
			}	
			cnt2=0;
			// printf("max %lld\n", max);
			flag2=1;
		}
	}

	if(flag2==0 || n==1)
	{
		printf("0\n");
	}

	else
	{
		printf("%lld\n", max-2 +cnt2);
	}

	return 0;
}