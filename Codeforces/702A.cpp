using namespace std;

#include <iostream>

typedef long long int ll;

ll arr[100005];

int main()
{
	ll n;
	cin >> n;

	ll cnt=1, maxi=0;
	
	cin >> arr[0];
	for(ll i=1; i<n; i++)
	{
		cin >> arr[i];

		if(arr[i]>arr[i-1])
		{
			cnt++;
		}

		else
		{
			maxi = max(maxi, cnt);
			cnt = 1;
		}
	}
	maxi = max(maxi, cnt);

	cout << maxi << endl;

}