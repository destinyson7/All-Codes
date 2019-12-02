#include<stdio.h>

int arr[100005];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		arr[0]=0;

		scanf("%d", &arr[1]);

		for(int j=2; j<=N; j++)
		{
			scanf("%d", &arr[j]);

			arr[j]+=arr[j-1];
		}

		int days=0, cnt=1;

		while(cnt<N)
		{
			cnt+=arr[cnt];

			days++;
		}

		printf("%d\n", days);

	}

	return 0;
}