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

const ll L = 2e5+5;

ll a[L];
ll b[L];

vector <pll> p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        cin >> a[i] >> b[i];

        p.pb(mp(b[i], a[i]));
    }

    sort(all(p));

    ll cur = 0;
    for(ll i=0; i<N; i++)
    {
        cur+=p[i].ss;

        // cout << i << " " << cur << " " << b[i] << endl;

        if(p[i].ff<cur)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}