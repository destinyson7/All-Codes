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

ll owe[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        owe[a][b] = c;
    }

    for(ll l=1; l<=n; l++)
    {
            for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                for(ll k=1; k<=n; k++)
                {
                    if(owe[i][j] && owe[j][k])
                    {
                        ll t = min(owe[i][j], owe[j][k]);

                        owe[i][j]-=t;
                        owe[j][k]-=t;
                        owe[i][k]+=t;
                    }
                }
            }
        }
    }

    ll sum = 0;

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            sum+=owe[i][j];
        }
    }

    cout << sum << endl;
    return 0;
}