#include<stdio.h>

int main()
{
char s[2000];
int i;

scanf("%s", s);

if(s[0]>=97)
s[0]-=32;

printf("%s", s);

return 0;
}
