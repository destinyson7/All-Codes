#include<stdio.h>

int main()
{

char s1[150], s2[150];
int i, l=0, cnt=0;

scanf("%s", s1);
scanf("%s", s2);

for(i=0; s1[i]!='\0'; i++)
cnt++;

for(i=0; s1[i]!='\0'; i++)
{
int j=s1[i], k=s2[i];
if(j>=65 && j<=90)
{

	if(k>=65 && k<=90)
	{
	if(j<k)
	{
	printf("-1");
	break;
	}

	else if(j>k)
	{
	printf("1");
	break;
	}

	}

	else
	{
        if(j<(k-32))
        {
	printf("-1");
	break;
	}

        else if(j>k-32)
        {
	printf("1");
	break;
	}
	
	}
}

else
{

	if(k>=65 && k<=90)
	{
        if((j-32)<k)
        {	
	printf("-1");
	break;
	}
        else if((j-32)>k)
        {
	printf("1");
	break;
	}
	
	}

	else
	{
        if(j<k)
	{
        printf("-1");
	break;
	}

        else if(j>k)
        {
	printf("1");
	break;
	}
	
	}


}

}

for(i=0; s1[i]!='\0'; i++)
{

int j=s1[i], k=s2[i];

if(j>=65 && j<=90)
{
        if(k>=65 && k<=90)
        {
                if(j==k)
                l++;
        }

        else
        {
                if(j==(k-32))
                l++;
        }
}

else
{
        if(k>=65 && k<=90)
        {
                if((j-32)==k)
                l++;
        }

        else
        {
                if(j==k)
                l++;
        }
}


}

if(l==cnt)
printf("0");


return 0;
} 
