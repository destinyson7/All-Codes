#include<stdio.h>

int main()
{
    int n, max=1, min=0, cntn=0, cntm=0, i, j, k, l, m;
   
    scanf("%d", &n);

    int arr[n];

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

	cntm=0;
	
    }
    

    for(l=n-1; l>=0; l--)
    {
	for(m=0; m<n; m++)
	{
	    if(arr[l]<=arr[m])
		cntn++;
	}

	if(cntn==n)
	{
	    min=l+1;
	    break;
	}

	cntn=0;
    }

    if(min<max)
	printf("%d", max-1+n-min-1);

    else
	printf("%d", max-1+n-min);
		
    return 0;
}
