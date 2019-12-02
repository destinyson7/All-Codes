#include<stdio.h>

int main()

{
int s, a, b, p, q;
scanf("%d %d %d %d %d", &s, &a, &b, &p, &q);

if(a*s + 2*p < b*s + 2*q)
printf("First");

else if(a*s + 2*p > b*s + 2*q)
printf("Second");

else
printf("Friendship");



return 0;
}
