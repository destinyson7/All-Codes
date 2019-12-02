#include<stdio.h>
#include<string.h>

long long int arr[100005];

int main()
{
	long long int N, Q, K;
	scanf("%lld %lld %lld", &N, &Q, &K);

	for(long long int i=0; i<N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	char Que[300005];
	scanf("%s", Que);

	for(long long int j=0; j<Q; j++)
	{
		if(Que[j]=='!')
		{
			long long int temp=arr[N-1];
			
			for(long long int k=N-1; k>0; k--)
			{
				arr[k]=arr[k-1];
			}

			arr[0]=temp;

			// for(long long int a=0; a<N; a++)
			// {
			// 	printf("%lld ", arr[a]);
			// }
		}

		else
		{
			long long int cnt=0, max=0;

			for(long long int k=0; k<N; k++)
			{
				if(arr[k]==1)
				{
					if(cnt<K)
					{
						cnt++;
					}
					// printf("cnt is %lld ", cnt);
				}

				else
				{
					if(cnt>max)
					{
						max=cnt;
					}

					cnt=0;
				}

				if(cnt>max)
				{
					max=cnt;
				}
			}

			printf("%lld\n", max);
		}
	}

	return 0;
}