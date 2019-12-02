#include<stdio.h>
#include<string.h>

#define ll long long int
int main()
{
	char s[1005];

	scanf("%[^\n]s", s);

	int lngth=strlen(s);

	int cnt=0, cntr=0, cntd=0;

	int flag[1005] = {0};

	for(int i=1; i<lngth-1; i+=3)
	{

		if(flag[s[i]]==1)
			continue;

		for(int j=1; j<(lngth-1); j+=3)
		{
			if(j==i)
				continue;

			if(s[i]==s[j])
			{
				flag[s[i]]=1;
			}



		}

		if(flag[s[i]]==0)
			cnt++;

		if(flag[s[i]]==1)
			cntd++;

	}

	printf("%d", cnt + cntd);	

	return 0;
}