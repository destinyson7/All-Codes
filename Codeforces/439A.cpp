using namespace std;

#include <iostream>

typedef long long int ll;

ll arr[105];

int main()
{
	ll n, d;
	cin >> n >> d;

	ll sum = 0, sum2=0;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];

		sum += arr[i];
		sum2 += arr[i];
		sum += 10;
	}

	sum -=10;

	if(d < sum)
	{
		cout << "-1" << endl;
	}

	else
	{
		cout << (d-sum2)/5 << endl;
	}

	return 0;
}