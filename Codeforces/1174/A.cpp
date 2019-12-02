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

const ll L = 2e3+5;

ll a[L];

const ll M = 1e6+5;

ll cnt[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll f = 0;

    for(ll i=0; i<2*n; i++)
    {
        cin >> a[i];

        cnt[a[i]]++;

        if(i && a[i]!=a[i-1])
        {
            f = 1;
        }
    }

    if(!f)
    {
        cout << -1 << endl;
        return 0;
    }

    for(ll i=0; i<M; i++)
    {
        for(ll j=0; j<cnt[i]; j++)
        {
            cout << i << " ";
        }
    }
    cout << endl;


    return 0;
}