#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

long long int a, b, s;

scanf("%I64d %I64d %I64d", &a, &b, &s);

if(s < abs(a)+ abs(b))
printf("No");

else
{

if((s -(abs(a)+abs(b)))%2 == 0)
printf("Yes");

else
printf("No");

}

return 0;

}
