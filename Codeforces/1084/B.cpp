using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

typedef long long int ll;

ll arr[1005];

int main()
{
	ll n, s;
	cin >> n >> s;

	ll min = 1000000007;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];

		if(arr[i]<min)
		{
			min = arr[i];
			// cout << min << endl;
		}
	}

	sort(arr, arr+n);

	for(ll j=0; j<n; j++)
	{
		arr[j]-=min;
	}

	ll flag = 0;

	ll ans;
	for(ll k=n-1; k>=0; k--)
	{
		// cout << arr[k] << " ";
		s-=arr[k];
		// cout << s << endl;

		if(s<=0)
		{
			ans = min;
			flag=1;
			break;
		}
	}


	if(flag==0)
	{
		while(min--)
		{
			// cout << min << endl;
			s-=n;
			// cout << s << endl;

			if(s==0)
			{
				ans=min;
				flag=1;
				break;
			}

			else if(s<0)
			{
				ans = min;
				flag=1;
				break;
			}
		}
	}

	if(flag==1)
	{
		cout << ans << endl;
	}

	else
	{
		cout << "-1" << endl;
	}
	

	return 0;
}