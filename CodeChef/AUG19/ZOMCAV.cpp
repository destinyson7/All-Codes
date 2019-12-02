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
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll N;
        cin >> N;

        vector <ll> c, h;

        for(ll i=0; i<N; i++)
        {
            ll t;
            cin >> t;

            c.pb(t);
        }

        for(ll i=0; i<N; i++)
        {
            ll t;
            cin >> t;

            h.pb(t);
        } 

        vector <ll> pref(N, 0);

        for(ll i=0; i<N; i++)
        {
            if(i+c[i] < N-1)
            {
                pref[i+c[i]+1]--;
            }   

            pref[max(0LL, i-c[i])]++;
        }

        for(ll i=1; i<N; i++)
        {
            pref[i]+=pref[i-1];
        }

        sort(all(h));
        sort(all(pref));

        if(pref == h)
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }

    }

    return 0;
}