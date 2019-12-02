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

const ll L = 55;

ll f[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        cin >> f[i];
    }

    sort(f, f+m);

    ll mi = 1e15;
    for(ll i=0; i<m-n+1; i++)
    {
        // cout << f[i+n-1] - f[i] << endl;
        mi = min(mi, f[i+n-1] - f[i]);
    }

    cout << mi << endl;

    return 0;
}