#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll flag[205];

int main()
{
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;

	ll len1, len2, len3;
	len1 = s1.length();
	len2 = s2.length();
	len3 = s3.length();

	for(ll i=0; i<len1; i++)
	{
		for(ll j=0; j<len3; j++)
		{
			if(s1[i] == s3[j] && flag[j]==0)
			{
				flag[j]=1;
				break;
			}
		}
	}

	for(ll i=0; i<len2; i++)
	{
		for(ll j=0; j<len3; j++)
		{
			if(s2[i] == s3[j] && flag[j]==0)
			{
				flag[j]=1;
				break;
			}
		}
	}

	if(len3!=(len1+len2))
	{
		cout << "NO" << endl;
		return 0;
	}

	for(ll k=0; k<len3; k++)
	{
		if(flag[k]==0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}