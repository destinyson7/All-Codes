#include<stdio.h>

int main()
{
        char s[150];
	    int cnt=0;
	        
	        scanf("%s", s);
		    
		    for(int k=0; s[k]!='\0'; k++)
			    cnt++;

		        for(int i=0; i<=cnt-2; i+=2)
			        {
				    	for(int j=2; j<=cnt; j+=2)
					    	{
						    	    if(s[j] < s[j-2])
									    {
												s[j]=s[j]^s[j-2];
														s[j-2]=s[j]^s[j-2];
																s[j]=s[j]^s[j-2];
																	    }
							    	
							    	}
					    }

			    printf("%s", s);
			        
			        return 0;
}

