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

const ll L = 55;
const ll M = 1e4+5;

ll adj[L][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll m, n;
    cin >> m >> n;

    for(ll i=0; i<m; i++)
    {
        ll s;
        cin >> s;

        for(ll j=0; j<s; j++)
        {
            ll a;
            cin >> a;

            adj[i][a] = 1;
        }
    }

    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(i!=j)
            {
                ll flag = 0;
                for(ll k=1; k<=n; k++)
                {
                    if(adj[i][k] && adj[j][k])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(!flag)
                {
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "possible" << endl;

    return 0;
}