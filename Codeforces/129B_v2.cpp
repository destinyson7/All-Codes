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
ll deg[L];
ll ret[L];
bool visited[L];

bool f = false;

void dfs(ll s)
{
    visited[s] = true;

    for(auto i: adj[s])
    {
        if(deg[s] == 1)
        {
            ret[i]--;
            if(deg[s] == ret[s])
            {
                ret[s]--;
            }

            f = true;
        }

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

        deg[a]++;
        deg[b]++;
        ret[a]++;
        ret[b]++;
    }

    ll cnt = 0;

    while(true)
    {
        f = false;

        for(ll i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }

        if(f)
        {
            cnt++;
        }

        else
        {
            break;
        }

        for(ll i=1; i<=n; i++)
        {
            visited[i] = false;
            deg[i] = ret[i];
        }
    }

    cout << cnt << endl;

    return 0;
}