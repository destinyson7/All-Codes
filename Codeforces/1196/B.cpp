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
        ll n, k;
        cin >> n >> k;

        vector <ll> store;
        vector <ll> v;

        ll cur = 0;

        for(ll i=0; i<n; i++)
        {
            ll a;
            cin >> a;

            v.pb(a);

            cur+=a;

            if(cur&1)
            {
                store.pb(i);
                cur=0;
            }

            // cout << cur << endl;
        }

        ll len = sz(store);

        if(len < k)
        {
            cout << "NO" << endl;
        }

        else
        {
            ll ind = store[k-1];

            // cout << "ind " << ind << endl;

            ll rem = 0;

            for(ll i=ind+1; i<n; i++)
            {
                rem+=v[i];
            }

            // cout << rem << endl;

            if(rem&1)
            {
                cout << "NO" << endl;
            }

            else
            {
                cout << "YES" << endl;

                for(ll i=0; i<k-1; i++)
                {
                    cout << store[i]+1 << " ";
                }
                cout << n << endl;
            }
        }
    }


    return 0;
}