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

const ll L = 1e2+5;

vector <ll> adj[L];

bool visited[L];

ll cnt = 0;

bool cycle = false;

void dfs(ll s, ll p)
{
    if(visited[s])
    {
        cycle = true;
        return;
    }

    cnt++;
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(i != p)
        {
            dfs(i, s);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    ll ans = 0;

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
            cycle = false;
            cnt = 0;
            
            dfs(i, -1);
            
            if(cycle && (cnt&1))
            {
                ans++;
            }
        }
    }

    if((n-ans)&1)
    {
        ans++;
    }

    cout << ans << endl;


    return 0;
}