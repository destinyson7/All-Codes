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
        ll N, M;
        cin >> N >> M;

        ll shortest[N+5][N+5];
        vector <ll> u(M+5, 0);
        vector <ll> v(M+5, 0);
        vector <ll> w(M+5, 0);

        for(ll i=0; i<N+5; i++)
        {
            for(ll j=0; j<N+5; j++)
            {
                shortest[i][j] = 1e15;
            }
        }

        for(ll i=0; i<M; i++)
        {
            cin >> u[i] >> v[i] >> w[i];

            shortest[u[i]][v[i]] = w[i];
            shortest[v[i]][u[i]] = w[i];
        }

        for(ll i=1; i<=N; i++)
        {
            for(ll j=1; j<=N; j++)
            {
                for(ll k=1; k<=N; k++)
                {
                    shortest[j][k] = min(shortest[j][k], shortest[j][i]+shortest[i][k]);
                }
            }
        }

        bool f = false;

        for(ll i=0; i<M; i++)
        {
            if(shortest[u[i]][v[i]]!=w[i])
            {
                f = true;
                break;
            }
        }

        if(f)
        {
            cout << "Case #" << t << ": Impossible" << endl;
        }

        else
        {
            cout << "Case #" << t << ": " << M << endl;

            for(ll i=0; i<M; i++)
            {
                cout << u[i] << " " << v[i] << " " << w[i] << endl;
            }
        }

    }

    return 0;
}