#include<stdio.h>

int main()
{
char s[100];
int i, mx=0;

scanf("%s", s);

for(i=1; s[i]!='\0'; i++)
{


if(s[i] == s[i-1])
mx++;

else if(s[i] != s[i-1])
mx=0;

if(mx==6)
break;

}

if(mx==6)
printf("YES");

else
printf("NO");

return 0;
}
