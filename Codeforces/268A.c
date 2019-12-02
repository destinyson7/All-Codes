#include<stdio.h>

int main()
{
    int n, i, cnt=0;
    scanf("%d", &n);
	
    int arr1[200], arr2[200];

    for(i=0; i<n; i++)
    {
	scanf("%d %d", &arr1[i], &arr2[i]);
    }

    for(int j=0; j<n; j++)
    {
	for(int k=0; k<n; k++)
	{
	    if(arr1[j]==arr2[k])
		cnt++;
	}
    }

    printf("%d", cnt);

    return 0;
}

