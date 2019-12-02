using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>

typedef long long int ll;
ll cnt[10005];

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		ll len = s.length();

		for(ll k=0; k<10005; k++)
		{
			cnt[k]=0;
		}

		ll flag=0;
		for(ll i=0; i<len; i++)
		{
			cnt[s[i]]++;

			if(i)
			{
				if(s[i]!=s[i-1])
				{
					flag=1;
				}
			}
		}

		// for(ll a=0; a<10005; a++)
		// {
		// 	cout << cnt[a]
		// }

		if(flag==1 && len>1)
		{
			for(ll j=0; j<10005; j++)
			{
				while(cnt[j]--)
				{
					printf("%c", (char)j);
				}
			}
			cout << endl;
		}

		else
		{
			cout << "-1" << endl;
		}
	}

	return 0;
}