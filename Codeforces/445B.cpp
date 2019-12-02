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

const ll L = 3e3+5;

vector <ll> adj[L];

vector <ll> visited(55, 0);

ll cnt = 0;

void dfs(ll s)
{
    visited[s] = true;

    cnt++;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll ans = 1;

    for(ll i=1; i<=n; i++)
    {
        cnt = 0;

        if(!visited[i])
        {
            dfs(i);

            ans*=(1LL << (cnt-1));
        }
    }

    cout << ans << endl;


    return 0;
}