#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e5+5;
const ll mod = 1e9+7;

ll fact[L];

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;
    a%=c;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b>>=1;
    }

    return ans;
}

ll K;
ll ans = 1;

vector <ll> adj[L];
vector <bool> visited(L, false);

void dfs(ll s, ll par)
{
    visited[s] = true;

    ll cur = K-2;

    if(par == -1)
    {
        cur++;
    }

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            if(cur <= 0)
            {
                ans = 0;
            }

            // cout << i << " " << cur << " " << ans << endl;

            ans = (ans*cur)%mod;
            cur--;

            dfs(i, s);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N >> K;

    for(ll i=0; i<N-1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    ans = K;

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}