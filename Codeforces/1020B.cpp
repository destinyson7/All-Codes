using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll p[1005];
ll ans[1005];
ll flag[1005];

int main()
{
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		cin >> p[i];
	}

	ll cnt=0;
	ll temp;
	for(ll j=1; j<=n; j++)
	{
		temp = j;
		while(1)
		{	
			flag[temp]++;

			if(flag[temp]==2)
			{
				ans[cnt++]=temp;
				break;
			}

			temp = p[temp];
		}

		for(ll m=0; m<1005; m++)
		{
			flag[m]=0;
		}
	}

	for(ll k=0; k<cnt; k++)
	{
		cout << ans[k] << " ";
	}
	cout << endl;

	return 0;
}