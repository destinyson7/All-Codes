#include<stdio.h>
#include<math.h>

int main()
{
    int T, i;
    long long int N, Q, j, k, m, p,  cnt=0, product, a, b;
    long long int arr[100001];
    long long int L[100001]={0};
    long long int R[100001]={0};

    scanf("%d", &T);

    for(i=0; i<T; i++)
    {
	scanf("%lld %lld", &N, &Q);
	
	for(j=0; j<N; j++)
	    scanf("%lld", &arr[j]);

	for(k=1; k<=Q; k++)
	    scanf("%lld %lld", &L[i], &R[i]);

	for(b=1; b<=Q; b++)
	{
	    for(m=L[b]-1; m<R[b]; m++)
	    {
		product= arr[m];

		for(p=m; p<R[b]; p++)
		{
		    product= product & arr[p]; 
		    
		    a=sqrt(product);

		    if((a*a)==product)
			cnt++;

		}	
		
	    }
	    
	    printf("%lld\n", cnt);
	}
    }

    return 0;
}
