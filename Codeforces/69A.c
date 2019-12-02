#include<stdio.h>

int main()
{
    int n;
    int d=0, e=0, f=0;
    
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
	int a, b, c;

	scanf("%d %d %d", &c, &b, &a);
	
	d=d+a;
	e=e+b;
	f=f+c;

    }

    if(d==0 && e==0 && f==0)
	printf("YES");

    else
	printf("NO");

    return 0;
}
