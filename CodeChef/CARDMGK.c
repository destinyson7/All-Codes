#include<stdio.h>
long long int arr[100005];

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		long long int N, flag=0, flag2=0, a;
		scanf("%lld", &N);

		for(long long int j=0; j<100005; j++)
		{
			arr[j]=0;
		}

		for(long long int i=0; i<N; i++)
		{
			scanf("%lld", &arr[i]);
		}

		for(long long int k=1; k<N; k++)
		{
			if(arr[k]<arr[k-1])
			{
				flag=1;
				a=k;
				break;
			}
		}

		if(flag==1)
		{
			for(long long int b=a+1; b<N; b++)
			{
				if(arr[b]<arr[b-1])
				{
					flag2=1;
					break;
				}
			}
		}

		if(arr[N-1]>arr[0])
		{
			if(flag==1)
			{
				flag2=1;
			}
		}

		if(flag2==0)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}

	}

	return 0;
}