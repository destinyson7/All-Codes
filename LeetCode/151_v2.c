#include<stdio.h>
#include<string.h>

typedef long long int ll;

void reverseWords(char *s) {

    long long int end=0;
    
   	end = strlen(s)-1;

   	if(end<0)
   		end=0;

	while(end--)
   	{
	    if(s[end]==' ')
    	    {
          	printf("%s ", s+end+1);
         	s[end]='\0';
            }
	}
    
   	printf("%s", s);
}


int main()
{
	char s[1005];
	scanf("%[^\n]s", s);

	// printf("string = %s\n", s);

	reverseWords(s);

	return 0;
}	
