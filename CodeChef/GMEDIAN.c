#include<stdio.h>
long long int arr[1005];

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		long long int N, ans=1;
		scanf("%lld", &N);

		for(long long int i=1; i<=N; i++)
		{
			scanf("%lld", &arr[i]);			
		}

		if(N&1)
		{
			long long int index;

			for(long long int j=1; j<=N; j++)
			{
				if(arr[j]==((N+1)/2))
				{
					index=j;
					break;
				}
			}

			long long int left = index-1;
			long long int right = N-index;
			// printf("left=%lld right=%lld\n", left, right);

			long long int ans = (left+1)*(right+1);
		
			printf("%lld\n", ans);
		}

		else
		{
			printf("0\n");	
		}
	}

	return 0;
}