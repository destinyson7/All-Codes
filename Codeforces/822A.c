#include<stdio.h>

int main()
{

long long int A, B;
long long int num=1;

scanf("%I64d %I64d", &A, &B);

if(A>=B)
{

	for(int i=1; i<=B; i++)
	num=num*i;
	
printf("%I64d", num);

}

else
{
	for(int i=1; i<=A; i++)
	num=num*i;

printf("%I64d", num);

}

return 0;
}
