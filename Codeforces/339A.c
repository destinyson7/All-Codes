#include<stdio.h>

int main()
{
char s[200];
int i;
int a=0, b=0, c=0;
for(i=0; s[i]!='\0'; i+=2)
{

if(s[i] == '1')
a++;

else if(s[i] == '2')
b++;

else
c++;

}

char arr1[]='1+';
char arr2[]='2+';
char arr3[]='3+';

printf("%.*s", a, arr1);
printf("%.*s", b, arr2);
printf("%.*s", c-1, arr3);
printf("3"); 



return 0;
}
