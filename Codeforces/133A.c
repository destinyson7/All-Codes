#include<stdio.h>

int main()
{
int i, j=0;
char s[200];

scanf("%s", s);

for(i=0; s[i]!='\0'; i++)
{
	if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
	j++;
}

if(j>=1)
printf("YES");

else
printf("NO");

return 0;
}
