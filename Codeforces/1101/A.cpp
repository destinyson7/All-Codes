#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll q;
	cin >> q;

	while(q--)
	{
		ll l, r, d;
		cin >> l >> r >> d;

		if(d>=l && d<=r)
		{
			if(r%d==0)
			{
				cout << (r/d+1)*d << endl;
			}

			else
			{
				cout << (r/d+1)*d << endl;
			}
		}

		else
		{
			cout << d << endl;
		}
	}


	return 0;
}