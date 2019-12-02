using namespace std;

#include <iostream>

typedef long long int ll;

ll arr[1005];

ll dfs(ll n)
{
	bool visited[1005];

	for(ll i=0; i<1005; i++)
	{
		visited[i]=false;
	}

	while(visited[n]==false)
	{
		visited[n]=true;
		n=arr[n];
	}

	return n;
}

int main()
{
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		cin >> arr[i];
	}

	for(ll j=1; j<=n; j++)
	{
		cout << dfs(j) << " ";
	}
	cout << endl;

	return 0;
}