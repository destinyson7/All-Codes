#include<stdio.h>

long long int arr[100005];

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		long long int N;
		scanf("%lld", &N);

		arr[0]=0;

		scanf("%lld", &arr[1]);

		for(long long int j=2; j<=N; j++)
		{
			scanf("%lld", &arr[j]);

			arr[j]+=arr[j-1];
		}

		long long int days=0, cnt=1;

		while(cnt<N)
		{
			cnt+=arr[cnt];

			days++;
		}

		printf("%lld\n", days);

	}

	return 0;
}