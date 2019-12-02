#include<stdio.h>

int main()
{

int y=0, n;
char s[20];
scanf("%d", &n);

int i;
for(i=1; i<=n; i++)
{

scanf("%s", s);
int j=s[2];
int k=s[1], l=s[3];

if(k==43 || l==43)
y++;

else
y--;

}

printf("%d", y);

return 0;
}

