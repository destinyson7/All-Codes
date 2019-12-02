#include<stdio.h>

int main()
{
int a, b, c;

scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);

if(a==0 || c<4 || b<2)
printf("0");

else if(c/4 <= a && b/2 <= a && c/4 <= b/2)
printf("%d", 7*(c/4));

else if(c/4 <= a && b/2 <= a && c/4 > b/2)
printf("%d", 7*(b/2));

else
{

if(c/4 <=a && b/2 >= a)
printf("%d", 7*(c/4));

else if(c/4 >=a && b/2 <= a)
printf("%d", 7*(b/2));

else
printf("%d", 7*a);

}

return 0;
}
