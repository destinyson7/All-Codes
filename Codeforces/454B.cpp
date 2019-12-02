using namespace std;

#include <iostream>

typedef long long int ll;

ll arr[200005];

int main()
{
	ll n;
	cin >> n;

	cin >> arr[0];
	arr[n]=arr[0];

	for(ll i=1; i<n; i++)
	{
		cin >> arr[i];
		arr[i+n]=arr[i];
	}

	ll flag=0, index;

	for(ll j=0; j<n; j++)
	{
		for(ll k=j; k<n+j-1; k++)
		{
			if(arr[k+1]<arr[k])
			{
				j=k;
				// cout << "breaking      ";
				break;
			}

			else if(k==(n+j-2))
			{
				// cout << "else at j= " << j << " and k= " << k << endl;
				index = j;
				flag=1;
			}
		}

		if(flag==1)
		{
			break;
		}
	}

	if(index==0)
		index=n;
	
	if(flag)
	{
		cout << n - index << endl;
	}

	else
	{
		cout << "-1" << endl;
	}

	return 0;
}