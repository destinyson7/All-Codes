#include<stdio.h>

int main()
{

long long int a, b, c;

scanf("%I64d %I64d %I64d", &a, &b, &c);

if(c==0 && b==a)
printf("YES");

else if(c==0 && b!=a)
printf("NO");

else if(b>a && c<0)
printf("NO");

else if(b<a && c>0)
printf("NO");
else
{
if(abs(b-a)%abs(c) == 0)
printf("YES");

else
printf("NO");

}

return 0;
}
