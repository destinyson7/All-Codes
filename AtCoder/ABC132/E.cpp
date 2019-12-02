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

vector <ll> adj[3*L];
ll visited[3*L];
ll dis[3*L];

void bfs(ll s, ll t, ll N)
{
    queue <ll> q;
    visited[s] = 1;
    ll cnt = 0;
    q.push(s);
    dis[s] = 0;

    while(!q.empty())
    {
        cnt++;
        ll u = q.front();
        q.pop();

        for(auto i: adj[u])
        {
            if(!visited[i])
            {
                dis[i] = dis[u]+1;
                // if(i<=N)
                // {
                    // cout << i << " ";
                // }

                // else if(i<=2*N)
                // {
                //     cout << i-N << " ";
                // }

                // else
                // {
                //     cout << i-2*N << " ";
                // }

                visited[i] = 1;
                q.push(i);

                if(i == t)
                {
                    // cout << dis[i] << endl;
                    cout << dis[i]/3 << endl;
                    return;
                }
            }
        }
        // cout << endl;
    }

    cout << -1 << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M;
    cin >> N >> M;

    for(ll i=0; i<M; i++)
    {
        ll u, v;
        cin >> u >> v;

        // u--;
        // v--;

        adj[u].pb(v+N);
        adj[u+N].pb(v+2*N);
        adj[u+2*N].pb(v);
    }

    ll s, t;
    cin >> s >> t;

    bfs(s, t, N);


    return 0;
}