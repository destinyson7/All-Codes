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
    
    ll q;
    cin >> q;

    while(q--)
    {
        ll n, m;
        cin >> n >> m;

        vector <ll> row(n+5, 0);
        vector <ll> col(m+5, 0);

        char g[n+5][m+5];

        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cin >> g[i][j];

                if(g[i][j] == '*')
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        ll ans = 1e15;

        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                ll cnt = row[i] + col[j];

                if(g[i][j] == '*')
                {
                    cnt--;
                }

                ans = min(ans, n+m-1-cnt);
            }
        }

        cout << ans << endl;
    }

    return 0;
}