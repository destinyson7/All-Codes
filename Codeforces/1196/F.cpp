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

const ll L = 8e2+5;

vector <pll> adj[L];

map <ll, ll> v;
set <ll> s;
ll dis[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, k;
    cin >> n >> m >> k;   

    vector < pair <ll, pll> > p;

    for(ll i=0; i<m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;

        p.pb(mp(w, mp(x, y)));
    }

    sort(all(p));

    for(ll i=0; i<min(m, k); i++)
    {
        s.insert(p[i].ss.ff);
        s.insert(p[i].ss.ss);
    }

    ll cnt = 0;

    for(auto i: s)
    {
        // cout << i << ": " << cnt << endl;
        v[i] = cnt++;
    }

    for(ll i=0; i<min(m, k); i++)
    {
        adj[v[p[i].ss.ff]].pb(mp(v[p[i].ss.ss], p[i].ff));
        adj[v[p[i].ss.ss]].pb(mp(v[p[i].ss.ff], p[i].ff));
    }

    // Floyd Warshall
    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            dis[i][j] = 1e15;
        }
    }

    for(ll i=0; i<L; i++)
    {
        dis[i][i] = 0;
    }

    for(ll i=0; i<min(m, k); i++)
    {
        dis[v[p[i].ss.ff]][v[p[i].ss.ss]] = min(dis[v[p[i].ss.ff]][v[p[i].ss.ss]], p[i].ff);
        dis[v[p[i].ss.ss]][v[p[i].ss.ff]] = dis[v[p[i].ss.ff]][v[p[i].ss.ss]];
    }

    for(ll i=0; i<cnt; i++)
    {
        for(ll j=0; j<cnt; j++)
        {
            for(ll k=0; k<cnt; k++)
            {
                dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
                dis[k][j] = dis[j][k];
            }
        }
    }

    vector <ll> store;

    // cout << endl << endl;

    for(ll i=0; i<cnt; i++)
    {
        for(ll j=i+1; j<cnt; j++)
        {
            // cout << dis[i][j] << " " << i << " " << j << endl;
            store.pb(dis[i][j]);
        }
    }

    sort(all(store));

    cout << store[k-1] << endl;

    return 0;
}