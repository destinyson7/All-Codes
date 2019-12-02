using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll arr[100005];
ll cnt[200005];
ll cnt2[200005];

int main()
{
	ll n, k;
	cin >> n >> k;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
		cnt2[arr[i]]++;
	}

	sort(cnt, arr+200000);

	ll flag=3;
	while(flag)
	{
		for(ll j=200000-k+1; j<200000; j++)
		{
			if(cnt[j]/2 > cnt[200000-k])
			{
				cnt[200000-k] = cnt[j];
				cnt2[200000-k]=cnt2[j];
				flag=1;
			}
		}

		if(flag==1)
		{
			flag=3;
		}

		else if(flag==3)
		{
			flag=0;
		}
	}

	for(ll m = 200000-k; m<200000; m++)
	{
		cout <<  << " ";
	}
	cout << endl;

	return 0;
}