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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    for(ll t=1; t<=T; t++)
    {
        // cout << "t " << t << endl;

        ll N, M;
        cin >> N >> M;

        ll edge[N+5][N+5];
        ll shortest[N+5][N+5];

        for(ll i=0; i<N+5; i++)
        {
            for(ll j=0; j<N+5; j++)
            {
                edge[i][j] = -1;
                shortest[i][j] = 1e15;
            }
        }

        for(ll i=1; i<=M; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;

            edge[u][v] = w;
            edge[v][u] = w;

            shortest[u][v] = w;
            shortest[v][u] = w;
        }

        // Floyd Warshall
        for(ll i=1; i<=N; i++)
        {
            for(ll j=1; j<=N; j++)
            {
                for(ll k=1; k<=N; k++)
                {
                    shortest[i][j] = min(shortest[i][j], shortest[i][k]+shortest[k][j]);
                }
            }
        }

        bool f = false;

        for(ll i=0; i<=N; i++)
        {
            for(ll j=0; j<=N; j++)
            {
                if(edge[i][j]!=-1 && shortest[i][j]!=edge[i][j])
                {
                    cout << "Case #" << t << ": Impossible" << endl;
                    f=true;
                    break;
                    // return 0;
                }
            }

            if(f)
            {
                break;
            }
        }

        if(f)
        {
            continue;
        }

        cout << "Case #" << t << ": " << M << endl;

        for(ll i=1; i<=N; i++)
        {
            for(ll j=i+1; j<=N; j++)
            {
                if(edge[i][j]!=-1)
                {
                    cout << i << " " << j << " " << edge[i][j] << endl;
                }
            }
        }



    }


    return 0;
}