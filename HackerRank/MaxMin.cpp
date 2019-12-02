#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

ll arr[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n;
    cin >> k;

    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    
    ll m = 1e15;
    for(ll i=0; i<n-k+1; i++)
    {
        m = min(m, arr[i+k-1] - arr[i]);
    }

    cout << m << endl;

    return 0;
}