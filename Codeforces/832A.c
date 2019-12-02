#include<stdio.h>

int main()
{
long long int n, k;

scanf("%I64d %I64d", &n, &k);

if(n==k)
printf("YES");

else
{

if(n/k%2 !=0)
printf("YES");

else
printf("NO");

}
return 0;
}
