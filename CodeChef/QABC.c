#include<stdio.h>
int arr[100005];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N, a;
		scanf("%d", &N);

		for(int i=0; i<N; i++)
		{
			scanf("%d", &arr[i]);
		}

		for(int j=0; j<N; j++)
		{
			scanf("%d", &a);
			arr[j]=(a-arr[j]);
		}

		int flag2=0, flag=0;

		for(int k=0; k<(N-2); k++)
		{
			if(arr[k]<0)
			{
				flag2=1;
				break;
			}
		
			while(arr[k]>0)
			{
				arr[k]--;
				arr[k+1]-=2;
				arr[k+2]-=3;
			}
		}

		if(flag2==1)
		{
			printf("NIE\n");
		}

		else
		{
			for(int b=0; b<N; b++)
			{
				if(arr[b])
				{
					flag=1;
					break;
				}
			}

			if(flag==0)
			{
				printf("TAK\n");
			}

			else
			{
				printf("NIE\n");
			}
		}
	}

	return 0;
}