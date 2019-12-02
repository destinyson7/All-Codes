#include<stdio.h>

int main()
{

char s[200];
int i, j=0;

scanf("%s", s);

for(i=0; s[i]!='\0'; i++)
{
	if(s[i]=='h')
	{

	for(int k=i+1; s[k]!='\0'; k++)
	{
		if(s[k]=='e')
		{

		for(int l=k+1; s[l]!='\0'; l++)
		{
			if(s[l]=='l')
			{

			for(int m=l+1; s[m]!='\0'; m++)
			{
				if(s[m]=='l')
				{

				for(int n=m+1; s[n]!='\0'; n++)
				{
					if(s[n]=='o')
					{
					j++;
				
					}
	
				
					
				}
				}

			
			}
			}
			
		
		
		
		}
		}	
		
		

		
	}	
	}				
}


if(j>=1)
printf("YES");

else
printf("NO");

return 0;
}
