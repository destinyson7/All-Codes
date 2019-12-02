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

const ll L = 150005;

vector <ll> adj[L];
bool visited[L];
ll v = 0, e = 0;

void dfs(ll s)
{
    assert(!visited[s]);

    visited[s] = true;
    v++;

    for(auto i: adj[s])
    {
        e++;

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
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(ll i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            v = 0, e = 0;

            dfs(i);

            ll t = (v*(v-1));

            if(t != e)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}