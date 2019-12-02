#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	string s;
	cin >> s;

	ll len = s.length();
	string ans = "";

	ll i=0, flag=1;
	for(i=0; i<len; i++)
	{
		if(flag==1 && s[i]=='[')
		{
			flag++;
			ans+=s[i];
		}

		else if(flag==2 && s[i]==':')
		{
			flag++;
			ans+=s[i];
			break;
		}
	}

	for(ll j=len-1; j>=0; j--)
	{
		if(j==i)
			break;

		if(flag==3 && s[j]==']')
		{
			flag++;
			ans+=s[j];
		}

		else if(flag==4 && s[j]==':')
		{
			flag++;
			ans+=s[j];
		}

		else if(flag==5 && s[j]=='|')
		{
			ans+=s[j];
		}
	}

	if(ans.length()>0 && flag==5)
	cout << ans.length() << endl;
	
	else
	{
		cout << "-1" << endl;
	}

	return 0;
}