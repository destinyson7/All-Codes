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

const ll L = 3e5+5;

ll dfs(vector < vector <ll> > &adj, vector <ll> &visited, ll a, ll b)
{
    visited[a] = true;

    for(auto i: adj[a])
    {
        if(!visited[i])
        {
            visited[i] = true;

            if(b == i)
            {
                return i;
            }

            else
            {
                ll t = dfs(adj, visited, i, b);

                if(t!=-1)
                {
                    return i+t;
                }
            }
        }
    }

    return -1;
}

void solve()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    while(T--)
    {
        ll N, Q;
        cin >> N >> Q;

        vector < vector <ll> > adj(N+5);

        for(ll i=0; i<N-1; i++)
        {
            ll u, v;
            cin >> u >> v;

            u--;
            v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        while(Q--)
        {
            ll u, v;
            cin >> u >> v;
        }
    }

    return 0;
}