#include<stdio.h>
long long int arr[100005];

int  main()
{
    long long int n;
    scanf("%lld", &n);

    for(long long int i=1; i<=n; i++)
    {
    	scanf("%lld", &arr[i]);
    }

    long long int cnt=0, start, end;

    for(long long int j=1; j<n; j++)
    {
    	if(arr[j+1]<=arr[j])
	{
	    cnt++;
	    start=j;
//	    printf("start=%lld ", start);
	    break;
	}
    }

    if(cnt==1)
    {	
	for(long long int k=start+1; k<n; k++)
    	{
	    if(arr[k+1]>arr[k])
	    {
	    	cnt++;
	   	end=k;
//		printf("end=%lld ", end);
	  	break;
	    }
   	}
    }

    if(cnt==2)
    {
	for(long long int a=end+1; a<n; a++)
	{
	    if(arr[a+1]<=arr[a])
	    {
		cnt++;
		break;
	    }
	}
    }

    if(cnt==0)
    {
	printf("yes\n");
	printf("1 1");
    }

    else if(cnt==1)
    {
	if(arr[n]>arr[start-1] && start>1)
	{
	    printf("yes\n");
	    printf("%lld %lld", start, n);
	}

	else if(start==1)
	{
	     printf("yes\n");
	     printf("%lld %lld", start, n);
	}

	else
	{
	    printf("no\n");
	}
    }

    else if(cnt==2)
    {
	if(start==1 && end==n)
	{
	    printf("yes\n");
	    printf("%lld %lld", start, end);
	}

	else if(start==1 && arr[end+1]>arr[1])
	{
	    printf("yes\n");
	    printf("%lld %lld", start, end);
	}

	else if(end==n && arr[n]>arr[start-1])
	{
	    printf("yes\n");
	    printf("%lld %lld", start, end);
	}

	else if(arr[end+1]>arr[start] && arr[end]>arr[start-1])
	{
	    printf("yes\n");
	    printf("%lld %lld", start, end);
	}

	else
	{
	    printf("no\n");
	}
    }

    else
    {
	printf("no\n");
    }


}
