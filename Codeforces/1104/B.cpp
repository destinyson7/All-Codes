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

	string s;
	cin >> s;

	ll len = s.length();

	ll cnt = 0;
	for(ll i=0; i<len; i++)
	{
		if(i<0)
		{
			i=0;
		}
		// string temp;
		// cout << s[i] << " " << s[i+1] << endl;
		if(s[i]==s[i+1])
		{
			// cout << i << " " << i+1 << endl;
			s.erase(i, 2);

			// cout << s << endl;
			len-=2;
			i-=2;
			// cout << "i " << i << endl;
			// cout << "len " << len << endl;

			cnt++;
		}
	}

	// cout << s << endl;

	if(cnt%2==0)
	{
		cout << "No" << endl;
	}

	else
	{
		cout << "Yes" << endl;
	}

	return 0;
}