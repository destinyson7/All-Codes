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
	
	ll n;
	cin >> n;

	for(ll i=1; i<n; i++)
	{
		if(i&1)
		{
			cout << "I hate that ";
		}

		else
		{
			cout << "I love that ";
		}
	}

	if(n&1)
	{
		cout << "I hate it" << endl;
	}

	else
	{
		cout << "I love it" << endl;
	}

	return 0;
}