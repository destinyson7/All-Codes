#include<stdio.h>
#include<math.h>

int main()
{
    int T, i;
    long long int N, Q, j, k, m, p, L, R, cnt=0, product, a, b;
    
    
    scanf("%d", &T);

    for(i=0; i<T; i++)
    {
	
	scanf("%lld %lld", &N, &Q);
	long long int arr[N];
	for(j=0; j<N; j++)
	    scanf("%lld", &arr[j]);

	for(k=0; k<Q; k++)
	{   cnt=0;
	    scanf("%lld %lld", &L, &R);
	
	    for(m=L-1; m<R; m++)
	    {
		product= arr[m];

		for(p=m; p<R; p++)
		{
		    product= (product & arr[p]); 
		    
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
