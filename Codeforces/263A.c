#include<stdio.h>
#include<stdlib.h>

int main()
{

char s[50];

int i, j, l, m, n;

for(i=1; i<=5; i++)
{
scanf("%[^\n]s", s);

	for(j=0; s[j]!='\0'; j++)
	{
	if(s[j]=='1')
	m=i, n=j+1;
	}

}

n=(n/2+1);

l=abs(m-3) + abs(n-3);

printf("%d", l);

return 0;
}
