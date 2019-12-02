#include<stdio.h>

int main()
{
    char s[200], t[200];
    int cnt=0, l=0;

    scanf("%s %s", s, t);

    for(int i=0; s[i]!='\0'; i++)
	cnt++;

    for(int k=0; s[k]!='\0'; k++)
    {
	if(s[k]==t[cnt-1-k])
	    l++;
    }

    if(l==cnt)
	printf("YES");

    else
	printf("NO");



    return 0;
}
