#include<stdio.h>

int main()
{
char s[200];
int i=0, j=0;
int cnt=0;
scanf("%s", s);
for(i=0; s[i]!='\0'; i++)
cnt++;

for(i=1; i<cnt; i++)
{
	if(s[i]<=90)
	j++;
}

if(j==cnt-1)
{
	for(i=0; i<cnt; i++)
	{
		if(s[i]<=90)	
		s[i]+=32;
		
		else
		s[i]-=32;
	}

	printf("%s", s);
}

else
printf("%s", s);

return 0;
}
