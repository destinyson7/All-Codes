using namespace std;

#include <iostream>
#include <string>

typedef long long int ll;
ll w[30];

int main()
{
	string s;
	cin >> s;

	ll k;
	cin >> k;

	ll max = -1;
	for(ll i=1; i<=26; i++)
	{
		cin >> w[i];

		if(w[i] > max)
		{
			max = w[i];
		}
	}

	ll len = s.length();

	ll ans = 0;
	for(ll j=0; j<len; j++)
	{
		ans += (j+1)*(w[s[j]-96]);
	}	

	for(ll m=1; m<=k; m++)
	{
		len++;
		ans+=max*len;
	}

	cout << ans << endl;

	return 0;
}