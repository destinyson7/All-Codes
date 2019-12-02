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

ll C(ll n)
{
    if(n < 2)
    {
        return 0;
    }

    return (n*(n-1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll N;
        cin >> N;

        vector <ll> a;
        map <ll, vector <ll>> cnt;

        for(ll i=0; i<N; i++)
        {
            ll t;
            cin >> t;

            a.pb(t);
        }

        vector <ll> pref;

        pref.pb(a[0]);
        cnt[0].pb(0);
        cnt[pref[0]].pb(1);        

        for(ll i=1; i<N; i++)
        {
            pref.pb(pref[i-1]^a[i]);
            cnt[pref[i]].pb(i+1);
        }

        ll res = 0;

        for(auto i: cnt)
        {
            ll freq = sz(i.ss);

            // cout << freq << endl;

            for(ll j=0; j<freq; j++)
            {
                res+=(i.ss[j]*(2*j+1-freq));
            }

            res-=C(freq);

            // cout << res << endl;
        }

        cout << res << endl;
    }   

    return 0;
}