#include<stdio.h>

int main()
{

int i;
char c[150];

scanf("%s", &c);

for(i=0; c[i]!='\0'; i++)
{

int j= c[i];
	if(c[i] == 'a' || c[i] == 'e' || c[i] == 'o' || c[i] == 'u' || c[i] == 'y' || c[i] == 'A' || c[i] == 'E' || c[i] == 'O' || c[i] == 'I' || c[i] == 'U' || c[i] == 'Y' || c[i] == 'i')
	printf("");

	else if(j>=65 && j<=90)
	printf(".%c", j+32);

	else
	printf(".%c", c[i]);

}

return 0;
}
