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

vector <ll> adj[2*L];
bool visited[2*L];

ll X = 0, Y = 0;

void dfs(ll s)
{
    visited[s] = true;

    if(s<L)
    {
        X++;
    }

    else
    {
        Y++;
    }

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
    
    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        ll x, y;
        cin >> x >> y;

        y+=L;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll ans = 0;

    for(ll i=0; i<2*L; i++)
    {
        if(!visited[i])
        {
            X = 0, Y = 0;
            dfs(i);
            ans+=(X*Y);
        }
    }

    cout << ans-N << endl;

    return 0;
}