#include<stdio.h>
#include<math.h>

int main()

{
long long int n, t;

scanf("%I64d %I64d", &n, &t);

if(t!=10)
{
    printf("%I64d", t);
    for(int i=1; i<n; i++)
	printf("0");
}

else
{
       
    if(n!=1)
    {
	
        printf("1");
        for(int j=1; j<n; j++)
	    printf("0");
    }

    else
	printf("-1");
}

return 0;
}
