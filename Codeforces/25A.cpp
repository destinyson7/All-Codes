using namespace std;

#include <iostream>

typedef long long int ll;

ll a[105];

int main()
{
	ll n;
	cin >> n;

	ll mini, cntodd=0, cnteven=0;
	for(ll i=1; i<=3; i++)
	{
		cin >> a[i];

		if(a[i]%2==1)
		{
			cntodd++;
		}

		else
		{
			cnteven++;
		}

	    mini = min(cntodd, cnteven);
	}

	if(mini == cntodd)
	{
		for(ll j=1; j<=n; j++)
		{
			if(j>3)
			{
				cin >> a[j];
			}

			if(a[j]%2==1)
			{
				cout << j << endl;
			}
		}
	}

	else
	{
		for(ll j=1; j<=n; j++)
		{
			if(j>3)
			{
				cin >> a[j];
			}

			if(a[j]%2==0)
			{
				cout << j << endl;
			}
		}
	}
	
	return 0;
}