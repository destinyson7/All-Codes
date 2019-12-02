#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
	
    int temp;

    if(m>n)
	temp=n;

    else
	temp=m;

    if(temp%2==0)
    {
	if(abs(m-n)%2==0)
	    printf("Akshat");
	
	else
	    printf("Malvika");
    }
    
    else
    {
	if(abs(m-n)%2==0)
	    printf("Malvika");

	else
	    printf("Akshat");
    }

    return 0;
}
