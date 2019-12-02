#include<stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int s[55];

	for(int i=0; i<m; i++)
		scanf("%d", &s[i]);

	for(int j=0; j<m-1; j++)
	{
		for(int k=0; k<m-j-1; k++)
		{
			if(s[k]>s[k+1])
			{
				s[k]=s[k]^s[k+1];
				s[k+1]=s[k]^s[k+1];
				s[k]=s[k]^s[k+1];
			}
		}
	}

	int min=s[n-1]-s[0];

	for(int l=0; l<=m-n; l++)
	{
		if((s[l+n-1]-s[l])<min)
		{
			min=s[l+n-1]-s[l];
		}
	}

	printf("%d", min);

	return 0;
}