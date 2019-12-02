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
	    ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		if(l1==r2)
		{
			cout << l1 << " " << l2 << endl;
		}

		else
		{
			cout << l1 << " " << r2 << endl;
		}
	}

	return 0;
}