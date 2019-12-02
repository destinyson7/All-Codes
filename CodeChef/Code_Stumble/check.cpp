#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, copy;

	cin >> s;

	copy = s;
	
	ll len = s.size();

	ll temp = len;
	ll cnt = 0;

	ll flag = 0;
	while(flag==0)
	{
		cnt++;
		ll temp2 = len;

		for(ll i=1; i<=temp2/2; i++)
		{
			s.insert(s[len-i], i);
			s.erase(len-i+1, 1);
		}

		for(ll j=0; j<len; j++)
		{
			if(copy[j]!=s[j])
			{
				flag = 0
				break;
			}

			else
			{
				flag = 1;
			}
		}

		if(flag==1)
		{
			break;
		}
	}	

	cout << cnt << endl;

	return 0;
}