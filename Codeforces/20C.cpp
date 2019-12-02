#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e5+5;

vector < pair <ll, ll> > adj[L];
vector <ll> d(L);
vector <ll> par(L);

priority_queue < pair <ll, ll>, vector < pair <ll, ll > >, greater < pair <ll, ll> > > pq;

ll n;

ll dijkstras(ll s)
{
    for(ll i=0; i<L; i++)
    {
        d[i] = 1e15;
    }

    d[s] = 0;

    pq.push(mp(0, s));

    while(!pq.empty())
    {
        pair <ll, ll> top = pq.top();
        ll i = top.ss;
        
        pq.pop();

        for(auto u: adj[i])
        {
            ll w = u.ss;

            if(d[i] + w < d[u.ff])
            {
                d[u.ff] = d[i] + w;
                par[u.ff] = i;
                pq.push(mp(d[u.ff], u.ff));
            }
        }

    }

    if(d[n]==1e15)
    {
        return -1;
    }

    return d[n];
} 

stack <ll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }

    ll dis = dijkstras(1);

    if(dis==-1)
    {
        cout << -1 << endl;
        return 0;
    }

    par[1] = -1;

    ll cur = n;

    while(cur!=-1)
    {
        s.push(cur);
        cur = par[cur];
    }

    // cout << dis << " ";

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}