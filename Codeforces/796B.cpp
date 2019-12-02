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

const ll L = 1e6+5;
vector <bool> hole(L, false);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, k;
    cin >> n >> m >> k;


    for(ll i=0; i<m; i++)
    {
        ll a;
        cin >> a;

        hole[a] = true;
    }

    ll cur = 1;

    if(hole[cur])
    {
        cout << 1 << endl;
        return 0;
    }

    while(k--)
    {
        ll u, v;
        cin >> u >> v;

        if(cur == u)
        {
            cur = v;
        }

        else if(cur == v)
        {
            cur = u;
        }

        if(hole[cur])
        {
            cout << cur << endl;
            return 0;
        }
    
        // cout << "k " << u << " " << v << " " << k << " " << cur << endl;
    }


    cout << cur << endl;

    return 0;
}