#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;

	ll cnt = 0;
	while(n)
	{
		ll x = n%10;

		if(x==4 || x==7)
		{
			cnt++;
		}

		n/=10;
		// cout << n << endl;
	}

	ll flag = 0;

	if(!cnt)
	{
		flag = 1;
	}

	while(cnt)
	{
		if(cnt%10!=4 && cnt%10!=7)
		{
			flag = 1;
			break;
		}

		cnt/=10;
	}

	if(flag)
	{
		cout << "NO" << endl;
	}

	else
	{
		cout << "YES" << endl;
	}

	return 0;
}