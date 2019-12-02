#include <bits/stdc++.h>

using namespace std;

typedef long long ll ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll len[105];

ll maxSum(ll arr[], ll n, ll k) 
{ 
    // k must be greater 
    if (n < k) 
    { 
       cout << "Invalid"; 
       return -1; 
    } 
  
    // Compute sum of first window of size k 
    ll res = 0; 
    for (ll i=0; i<k; i++) 
       res += arr[i]; 
  
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of  
    // current window. 
    ll curr_sum = res; 
    for (ll i=k; i<n; i++) 
    { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum); 
    } 
  
    return res; 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N, K;
	cin >> N >> K;

	for(ll i=0; i<N; i++)
	{
		cin >> len[i];

		ll tempmax = -1e10, finalmax = -1e10;
		for(ll j=0; j<len[i]; j++)
		{
			if(j==0)
			{
				cin >> a;

				finalmax=a;
				tempmax=a;
			}
			
			else
			{
				cin >> rest;		

				tempmax+=rest;

				if(rest > tempmax)
				{
					tempmax=rest;
				}

				if(tempmax > finalmax)
				{
					finalmax=tempmax;
				}
			}			
		}

		store[i] = finalmax;
	}

	for(ll m=1; m<=K; m++)
	{
		ll res[m] = maxSum(store, N, m)
	}

	ll ans = res[1];
	for(ll o=1; o<=K; o++)
	{
		ans = max(ans, res[m]);
	}

	return 0;
}