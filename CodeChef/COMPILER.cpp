#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		string exp;
		cin >> exp;

		stack <ll> s;

		ll len = exp.length();
			
		ll ans = 0, cnt=0;	
		for(ll i=0; i<len; i++)
		{
			if(exp[i]=='<')
			{
				cnt++;
			}

			else if(exp[i]=='>')
			{
				cnt--;
			}

			if(cnt==0)
			{
				ans = max(ans, i+1);
			}

			if(cnt < 0)
			{
				break;
			}
		}

		cout << ans << endl;
	}


	return 0;
}