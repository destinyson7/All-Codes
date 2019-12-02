#include<stdio.h>

int main()
{

int n,i;
char s[100];
int cnt=0;

scanf("%d", &n);
scanf("%s", s);

for(i=1; i<=n; i++)
{

if(s[i] == s[i-1])
cnt++;

}

printf("%d", cnt);

return 0;
}
