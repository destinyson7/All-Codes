#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

int arr[300000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, i;

	cin >> n;

	for(i=0; i<n; i++)
		cin >> arr[i];

	for(i=n-1; i>=1; i--)
	{
		if(arr[i]==arr[i-1])
		{
			continue;
		}

		else
		{
			break;
		}
	}

	cout << i;	

	return 0;
}