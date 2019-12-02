#include<stdio.h>
#include<stdlib.h>

int main()
{
int i, j;
int m, p=0, q=0;
	
for(i=1; i<=5; i++)
{
	for(j=0; j<=4; j++)
	{
	scanf("%d", &m);
	if(m==1)
	{
		p=i;
		q=j+1;
	}
	}
}

printf("%d", abs(p-3) + abs(q-3));

return 0;
}
