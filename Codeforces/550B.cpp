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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, l, r, x;
    cin >> n >> l >> r >> x;

    vector <ll> c(n, 0);

    for(ll i=0; i<n; i++)
    {
        cin >> c[i];
    }

    ll M = (1LL << n);

    ll ways = 0;

    for(ll i=0; i<M; i++)
    {
        ll total = 0;
        ll ele = 0;
        ll ma = -1e15;
        ll mi = 1e15;

        for(ll j=0; j<n; j++)
        {
            // Include only those elements whose bits are set in 'i'
            if((1LL<<j) & i)
            {
                ele++;
                total+=c[j];
                ma = max(ma, c[j]);
                mi = min(mi, c[j]);
            }
        }

        if(ele >= 2)
        {
            if(total >= l && total <= r && (ma - mi) >= x)
            {   
                ways++;
            }
        }
    }

    cout << ways << endl;

    return 0;
}