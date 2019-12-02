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

	ll cnt=0;
	for(ll j=0; j<n-2; j++)
	{
		if(arr[j]==1 && arr[j+1]==0 && arr[j+2]==1)
		{
			cnt++;
			j+=2;
		}
	}

	ll cnt2=0;
	for(ll j=n-1; j>1; j--)
	{
		if(arr[j]==1 && arr[j-1]==0 && arr[j-2]==1)
		{
			cnt2++;
			j-=2;
		}
	}

	// printf("cnt %lld cnt2 %lld\n", cnt, cnt2);
	ll min = cnt;

	if(cnt>cnt2)
		min = cnt2;

	printf("%lld\n", min);

	return 0;
}