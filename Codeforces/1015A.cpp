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
    
    ll n, m;
    cin >> n >> m;

    map <ll, ll> v;

    for(ll i=0; i<n; i++)
    {
        ll l, r;
        cin >> l >> r;

        for(ll j=l; j<=r; j++)
        {
            v[j] = 1;
        }
    }

    vector <ll> ans;

    for(ll i=1; i<=m; i++)
    {
        if(v[i]!=1)
        {
            ans.pb(i);
        }
    }

    cout << sz(ans) << endl;

    for(ll i=0; i<sz(ans); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}