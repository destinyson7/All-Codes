#include<stdio.h>
#include<string.h>

typedef long long int ll;

int main()
{
	char s[1005];
	scanf("%[^\n]s", s);

	// printf("string = %s\n", s);

	ll len = strlen(s);
	// printf("length %lld\n", len);

	ll end = len-1;

	while(end--)
	{
		if(s[end]==' ')
		{
			printf("%s ", &s[end] + 1);
			s[end]='\0';
		}
	}

	printf("%s\n", s);

	return 0;
}