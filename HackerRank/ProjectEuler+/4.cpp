using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

bool checkPalindrome(ll x)
{
	ll temp = x;

	// cout << temp << endl;

	ll arr[20];

	ll cnt=0;
	while(temp)
	{
		arr[cnt++]=temp%10;
		// cout << arr[cnt-1] << " ";
		temp/=10;
	}

	// cout << "cnt " << cnt << endl;
	ll cnt2=0, cnt3=cnt-1;
	if(cnt%2==0)
	{
		while(cnt3>cnt2)
		{
			if(arr[cnt2++]!=arr[cnt3--])
			{
				return 0;
			}
		}

		return 1;
	}

	return 0;
}

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N;
		cin >> N;

		ll a = 100;
		ll b = 100;

		ll max = 100001;

		// cout << checkPalindrome(100001);

		for(ll i=a; i<=999; i++)
		{
			for(ll b=a; b<=999; b++)
			{
				ll pr = i*b;

				if(pr < N)
				{
					if(checkPalindrome(pr))
					{
						if(pr > max)
						{
							max = pr;
						}
					}
				}

				else
				{
					break;
				}
			}
		}

		cout << max << endl;
	}

	return 0;
}