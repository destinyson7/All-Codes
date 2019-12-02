#include<stdio.h>

long long int arr[1000005];

int main()
{
	long long int l, r, n;
	scanf("%lld %lld %lld", &l, &r, &n);

	// for(long long int a=0; a<1000005; a++)
	// {
	// 	arr[a]=0;	
	// }

	// long long int max;

	// if(n>r)
	// 	max=n;

	// else
	// 	max=r;

	for(long long int i=1; i<=n; i++)
	{
		long long int temp=l-l%i;

		for(long long int j=temp; j<=r; j+=i)
		{
			if(j>=l && j<=r)
				arr[j-l]++;
		}
	}

	// for(long long int a=0; a<25; a++)
	// {
	// 	printf("%lld ", arr[a]);	
	// }

	long long int cnt=0;

	for(long long int k=0; k<r-l+1; k++)
	{
		if(arr[k]%2==0)
			cnt++;
	}

	printf("%lld\n", cnt);


	return 0;
}