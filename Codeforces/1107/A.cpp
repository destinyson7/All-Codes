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

	ll q;
	cin >> q;

	while(q--)
	{
		ll n;
		cin >> n;

		string s;
		cin >> s;

		if(s.length()==2 && s[1]<=s[0])
		{
			cout << "NO" << endl;
		}

		else
		{
			cout << "YES\n2" << endl;
			cout << s[0] << " ";

			ll len = s.length();

			for(ll i=1; i<len; i++)
			{
				cout << s[i];
			}
			cout << endl;
		}
	}	

	return 0;
}