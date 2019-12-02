#include<stdio.h>

int main()
{
    int n, max, min, cntn=0, cntm=0, i, j, k, l, m;
    int arr[200];

    scanf("%d", &n);

    for(i=0; i<n; i++)
    	scanf("%d", &arr[i]);

    for(j=0; j<n; j++)
    {
	for(k=0; k<n; k++)
	{
	    if(arr[j]>=arr[k])
	    	cntm++;		    
	}
	
	if(cntm==n)
	{
	    max=j+1;
	    break;
	}
    }

    for(l=0; l<n; l++)
    {
	for(m=0; m<n; m++)
	{
	    if(arr[l]<=arr[m])
		cntn++;
	}

	if(cntn==n)
	    min=l+1;
	    
    }
    
    printf("%d %d\n", max, min);

    if(min<max)
	printf("%d", max-1+n-min-1);

    else
	printf("%d", max-1+n-min);
		
    return 0;
}
