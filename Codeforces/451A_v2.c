#include<stdio.h>

int main()
{
    int n, m, cnt=0, points;

    scanf("%d %d", &n, &m);

    points=n*m;	

    for(int i=0; points!=0 ; i++)
    {
	points= points - n - m + 1;
	n=n-1;
	m=m-1;
	cnt++;

	if(points==0)
	{

	    if(cnt%2==0)
	        printf("Malvika");

	    else
		printf("Akshat");
	}
    }

    return 0;
}


