#include<stdio.h>
#include<stdlib.h>

long long int arr[100005];
long long int b[100005];
long long int c[100005];

void Merge(long long int *arr, long long int *left, long long int l1, long long int *right, long long int l2, long long int *arr2, long long int *left2, long long int *right2)
{
	long long int i=0, j=0, k=0;

	while(i<l1 && j<l2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			arr2[k]=left2[i];
			i++;
		}

		else
		{
			arr[k]=right[j];
			arr2[k]=right2[j];
			j++;
		}

		k++;
	}

	while(i<l1)
	{
		arr[k]=left[i];
		arr2[k]=left2[i];
		i++;
		k++;
	}

	while(j<l2)
	{
		arr[k]=right[j];
		arr2[k]=right2[j];
		j++;
		k++;
	}

}

void MergeSort(long long int *arr, long long int n, long long int *arr2)
{
	long long int mid, *left, *right, *left2, *right2;

	if(n<2)
	{	
		return;
	}

	mid=n/2;

	left=(long long int*)malloc(mid*sizeof(long long int));
	left2=(long long int*)malloc(mid*sizeof(long long int));
	right=(long long int*)malloc((n-mid)*sizeof(long long int));
	right2=(long long int*)malloc((n-mid)*sizeof(long long int));

	for(long long int i=0; i<mid; i++)
	{
		left[i]=arr[i];
		left2[i]=arr2[i];
	}

	for(long long int j=mid; j<n; j++)
	{
		right[j-mid]=arr[j];
		right2[j-mid]=arr2[j];
	}

	MergeSort(left, mid, left2);
	MergeSort(right, n-mid, right2);
	Merge(arr, left, mid, right, n-mid, arr2, left2, right2);
	
	free(left);
	free(left2);
	free(right);
	free(right2);
}

int main()
{
	long long int T;
	scanf("%lld", &T);
	// printf("5\n");

	while(T--)
	{
		long long int N;
		scanf("%lld", &N);

		for(long long int i=1; i<=N; i++)
		{
			scanf("%lld", &arr[i]);
		}

		for(long long int j=1; j<=N; j++)
		{
			if(arr[j]<=N)
			{
				b[j]=arr[arr[j]];
				c[j]=arr[j];
			}

			else
			{
				b[j]=-1;
				c[j]=-1;
			}
		}

		b[0]=-1;
		c[0]=-1;

		// printf("1\n");

		MergeSort(b, N+1, c);

		// printf("2\n");

		long long int flag=0;

		for(long long int k=2; k<=N; k++)
		{
			if(b[k]!=(-1))
			{
				if(b[k]==b[k-1])
				{
					if(c[k]!=c[k-1])
					{
						flag=1;
					}
				}
			}
		}

		// printf("3\n");

		if(flag)
		{
			printf("Truly Happy\n");
		}

		else
		{
			printf("Poor Chef\n");
		}
	}

	return 0;
}