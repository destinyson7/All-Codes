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

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    for(ll t=1; ; t++)
    {
        ll n;
        cin >> n;

        if(!n)
        {
            break;
        }

        map <string, ll> v;
        vector < pair <ll, float> > adj[n+5];

        for(ll i=0; i<n; i++)
        {
            string s;
            cin >> s;

            v[s] = i;
        }

        ll m;
        cin >> m;

        vector < pair <ll, pair <ll, float> > > edges;

        for(ll i=0; i<m; i++)
        {
            string a, b;
            float w;

            cin >> a >> w >> b;

            w = 1/w;
            w = log(w);

            // cout << a << " " << w << " " << b << endl;

            adj[v[a]].pb(mp(v[b], w));
            edges.pb(mp(v[a], mp(v[b], w)));
        }

        float ini = 1e15;

        vector <float> dis(n+5, ini);
        dis[0] = 0;

        for(ll i=0; i<n; i++)
        {
            for(auto j: edges)
            {
                if(dis[j.ss.ff] > dis[j.ff] + j.ss.ss)
                {
                    dis[j.ss.ff] = dis[j.ff] + j.ss.ss;
                }
            }
        }

        bool f = false;

        for(auto j: edges)
        {
            if(dis[j.ss.ff] > dis[j.ff] + j.ss.ss)
            {
                f = true;
                break;
            }
        }

        if(f)
        {
            cout << "Case " << t << ": Yes" << endl;
        }

        else
        {
            cout << "Case " << t << ": No" << endl;
        }
    }


    return 0;
}