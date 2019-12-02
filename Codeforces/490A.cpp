using namespace std;

#include <iostream>

typedef long long int ll;

ll arr[5005];
ll cnt[5];
ll hash1[5005];
ll hash2[5005];
ll hash3[5005];

int main()
{
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		cin >> arr[i];

		cnt[arr[i]]++;

		if(arr[i]==1)
		{
			hash1[cnt[arr[i]]]=i;
		}

		if(arr[i]==2)
		{
			hash2[cnt[arr[i]]]=i;
		}

		if(arr[i]==3)
		{
			hash3[cnt[arr[i]]]=i;
		}
	}

	ll cnt2 = min(cnt[1], cnt[2]);
	ll w = min(cnt2, cnt[3]);

	cout << w << endl;

	for(ll j=1; j<=w; j++)
	{
		cout << hash1[j] << " " << hash2[j] << " " << hash3[j] << " " << endl;
	}

	return 0;
}