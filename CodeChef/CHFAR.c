#include<stdio.h>
long long int arr[10005];

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		long long int N, K;
		scanf("%lld %lld", &N, &K);

		long long int flag=0, cnt=0;

		for(long long int i=0; i<N; i++)
		{
			scanf("%lld", &arr[i]);
			
			if(arr[i]==1)
			{
				cnt++;
			}
		}

		cnt+=K;

		if(cnt>=N)
		{
			flag=1;
		}

		if(flag)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}
}