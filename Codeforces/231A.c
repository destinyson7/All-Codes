#include<stdio.h>

int main()
{
int n, a, b, c;

scanf("%d", &n);
int i, cnt=0;

for(i=1; i<=n; i++)
{

scanf("%d %d %d", &a, &b, &c);

if(a==1 && b==1)
cnt++;

else if(b==1 && c==1)
cnt++;

else if(a==1 && c==1)
cnt++;

}

printf("%d", cnt);

return 0;
}
