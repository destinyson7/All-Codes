using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll arr[2005];
ll ansarr[2005][5];

int main()
{
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	ll ans=0, cnt=0;

	for(ll i=n-1; i>=0; i--)
	{
		arr[i]+=ans;

		if(arr[i]%n!=i)
		{
			ll temp = i - (arr[i]%n);

			if(temp<0)
			{
				temp+=n;
			}

			ansarr[cnt][0] = temp;
			ansarr[cnt][1] = i;
			cnt++;
			ans+=temp;
		}
	}

	cout << cnt+1 << endl;

	for(ll m=0; m<cnt; m++)
	{
		cout << "1" << " " << ansarr[m][1]+1 << " " << ansarr[m][0] << endl;
	}

	cout << "2" << " " << n << " " << n << endl;
	
	return 0;
}