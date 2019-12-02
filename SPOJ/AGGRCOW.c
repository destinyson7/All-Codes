#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll x[100005];

void Merge(ll *arr, ll *left, ll l1, ll *right, ll l2)
{
    ll i=0, j=0, k=0;

    while(i<l1 && j<l2)
    {
    	if(left[i]<=right[j])
	    arr[k++]=left[i++];

	else
	    arr[k++]=right[j++];
    }

    while(i<l1)
	arr[k++]=left[i++];

    while(j<l2)
	arr[k++]=right[j++];

}

void MergeSort(ll *arr, ll n)
{
    ll mid, *left, *right;

    if(n<2)
	return;

    mid = n/2;

    left=(ll*)malloc(mid*sizeof(ll));
    right=(ll*)malloc((n-mid)*sizeof(ll));

    for(ll i=0; i<mid; i++)
	left[i]=arr[i];

    for(ll j=mid; j<n; j++)
	right[j-mid]=arr[j];

    MergeSort(left, mid);
    MergeSort(right, mid);
    Merge(arr, left, mid, right, n-mid);

    free(left);
    free(right);
		
}

int main()
{
    ll t;
    scanf("%lld", &t);
	
    while(t--)
    {
    	ll N, C;
	scanf("%lld %lld", &N, &C);
	
	ll min = 1000000007;
	ll max = 0;
	for(ll i=0; i<N; i++)
	{
	    scanf("%lld", &x[i]);

	    if(x[i]<min)
		min = x[i];

	    if(x[i]>max)
		max=x[i];
    	}

	MergeSort(x, N);

	ll low = 0;
	ll high = max - min + 1;

	ll mid, ans=0;

	while(low<=high)
	{
	    mid = low + (high-low)/2;
	    
	    ll check = x[0];
	    ll cnt=1;

	    for(ll j=1; j<N; j++)
	    {
		if(x[j]-check >= mid)
		{
		    cnt++;
		    check = x[j];
		}
	    }

	    if(cnt>=C)
	    {
	    	low = mid + 1;
		ans = mid;
	    }

	    else
	    {
	    	high = mid - 1;
	    }			
	}

	printf("%lld\n", ans);
    }


    return 0;
}
