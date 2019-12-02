#include<stdio.h>
#include<string.h>

int main()
{
	char s[201];

	scanf("%s", s);

	int flag=0;

	for(int i=0; i<strlen(s); i++)
	{
		if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
		{
			printf(" ");
			i+=2;
		}
		

		else
			printf("%c", s[i]);
	}	

	return 0;
}