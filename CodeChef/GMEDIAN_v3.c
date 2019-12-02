#include<stdio.h>
#include<stdlib.h>

long long int arr[1005];
long long int arr2[1005];
long long int idx[1005];
long long int cntless[1005];
long long int cntmore[1005];
long long int permute[1005][1005];

long long int C(long long int n, long long int r, long long int mod)
{
// 	printf("%lld %lld %lld  debug \n",n,r,mod);
	
	if(n==r)
	{
	    return 1;
	}
	
	else if(n<r)
	{
	    return 0;
	}

	if(r==1)
	{
		return permute[n][1];
	}

	if(permute[n][r]!=(-1))
	{
		return permute[n][r];
	}

	permute[n][r] = (C(n-1, r-1, mod) + C(n-1, r, mod))%mod;
	return (permute[n][r]);

}

long long int modexp(long long int a,long long int b,long long int c)
{
	long long int ans=1;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans*a)%c);
		}
		b >>= 1;
		a=(a*a)%c;
	}

	return ans;
}

long long int modmul(long long int a,long long int b,long long int c)
{
	long long int ans=0;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans+a)%c);
		}
		b >>= 1;
		a=(a*2)%c;
	}

	return ans;
}

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

	while(T--)
	{
		long long int N, mod = 1000000007;
		scanf("%lld", &N);

		for(long long int i=0; i<N; i++)
		{
			scanf("%lld", &arr[i]);
			arr2[i]=arr[i];
			idx[i]=i;
		}

		for(long long int a=0; a<1005; a++)
		{
			for(long long int b=0; b<1005; b++)
			{
				permute[a][b]=-1;
			}
		}

		for(long long int d=0; d<1005; d++)
		{
			cntless[d]=0;
			cntmore[d]=0;
			permute[d][0]=1;
			permute[d][1]=d;
		}

		long long int res=0;
		res= modexp(2, N-1, mod);

		// printf("%lld\n", res);

		MergeSort(arr2, N, idx);

		for(long long int b=0; b<N; b++)
		{
			for(long long int c=0; c<b; c++)
			{
				if(arr[c]<=arr[b])
				{
					cntless[b]++;
				}
			}

			for(long long int c=b+1; c<N; c++)
			{
				if(arr[c]>=arr[b])
				{
					cntmore[b]++;
				}
			}
		}

		// for(long long int f=0; f<N; f++)
		// {
		// 	printf("cntless[%lld] is %lld and cntmore[%lld] is %lld\n", f, cntless[f], f, cntmore[f]);
		// }

		// for(long long int f=0; f<N; f++)
		// {
		// 	printf("arr[%lld] is %lld, arr2[%lld] is %lld, idx[%lld] is %lld\n", f, arr[f], f, arr2[f], f, idx[f]);
		// }

		long long int cnt1=0, cnt2=0;

		for(long long int j=0; j<N-1; j++)
		{
			for(long long int a=j+1; a<N; a++)
			{
				if(arr2[j]==arr2[a])
				{
					if(idx[j]<idx[a])
					{
						cnt1=cntless[idx[j]];
						cnt2=cntmore[idx[a]];

						// printf("cnt1 is %lld, cnt2 is %lld\n", cnt1, cnt2);

						if(cnt2<cnt1)
						{
							cnt2=cnt1^cnt2;
							cnt1=cnt1^cnt2;
							cnt2=cnt1^cnt2;
						}
					}

					else
					{
						cnt1=cntless[idx[a]];
						cnt2=cntmore[idx[j]];

						// printf("cnt1 is %lld, cnt2 is %lld\n", cnt1, cnt2);

						if(cnt2<cnt1)
						{
							cnt2=cnt1^cnt2;
							cnt1=cnt1^cnt2;
							cnt2=cnt1^cnt2;
						}
					}

					for(long long int e=0; e<=cnt1; e++)
					{
						long long int pr1 = C(cnt1, e, mod);
						// printf("pr1 is %lld\n", pr1);
						long long int pr2= C(cnt2, e, mod);
						// printf("pr2 is %lld\n", pr2);
						res+= modmul(pr1, pr2, mod);
						// printf("res is %lld\n", res);
					}
				}

				else
				{
					break;
				}
			}
		}

		printf("%lld\n", res);
	}


	return 0;
}