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

ll parent[L][L];
ll unionSize[L][L];

ll find(ll c, ll s)
{
    if(parent[c][s] == s)
    {
        return s;
    }

    return parent[c][s] = find(c, parent[c][s]);
}

void unionSet(ll x, ll y, ll c)
{
    ll a = find(c, x);
    ll b = find(c, y);

    if(unionSize[c][a] > unionSize[c][b])
    {
        swap(x, y);
    }

    parent[c][a] = b;
    unionSize[c][b]+=unionSize[c][a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            parent[i][j] = j;
            unionSize[i][j] = 1;
        }
    }

    for(ll i=0; i<m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        unionSet(a, b, c);
    }   

    ll q;
    cin >> q;

    while(q--)
    {
        ll u, v;
        cin >> u >> v;

        ll ans = 0;

        for(ll i=1; i<=m; i++)
        {
            if(find(i, u) == find(i, v))
            {
                ans++;
            }
        }

        cout << ans << endl;
    }


    return 0;
}