using namespace std;

#include <iostream>
#include <algorithm>

typedef long long int ll;

ll arr[100005];

int main()
{
	ll n;	
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n);

	ll flag=0;
	// cout << arr[0] << endl << arr[1] << endl;
	for(ll i=2; i<n; i++)
	{
		// cout << arr[i] << endl;
		if(arr[i-1]+arr[i-2] > arr[i])
		{
			flag=1;
			break;
		}
	}	

	if(flag)
	{
		cout << "YES" << endl;
	}

	else
	{
		cout << "NO" << endl;
	}

	return 0;
}