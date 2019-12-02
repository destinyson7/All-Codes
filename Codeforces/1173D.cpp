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

const ll L = 2e5+5;
const ll mod = 998244353;

ll fact[L];
ll deg[L];

void factorial()
{
    fact[0] = 1;

    for(ll i=1; i<L; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    factorial();

    ll n;
    cin >> n;

    for(ll i=0; i<n-1; i++)
    {
        ll u, v;
        cin >> u >> v;

        deg[u]++;
        deg[v]++;
    }

    ll ans = n;

    for(ll i=1; i<=n; i++)
    {
        ans = (ans*fact[deg[i]])%mod;
    }

    cout << ans << endl;

    return 0;
}
