#include<stdio.h>

int main()
{
    long long int n, t;
    scanf("%lld %lld", &n, &t);

    char s[55];
    scanf("%s", s);

    while(t--)
    {
    	for(long long int i=0; i<n; i++)
	{
    		if(s[i]=='B' && s[i+1]=='G')
		{
		    s[i]='G';
		    s[i+1]='B';
		    i++;
		}
    	}
    }

    printf("%s", s);

    return 0;
}
