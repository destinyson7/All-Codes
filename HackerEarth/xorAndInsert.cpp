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

const ll L = 1e5+5;

vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll q;
    cin >> q;

    v.pb(0);

    ll m = 0;

    while(q--)
    {
        ll type;
        cin >> type;

        if(type==1)
        {
            ll x;
            cin >> x;

            v.pb(x);

            m = min(m, x);
        }

        else if(type==2)
        {
            ll x;
            cin >> x;

            m = 1e15;

            for(auto i: v)
            {
                i^=x;

                m = min(m, i);
            }
        }

        else
        {
            cout << m << endl;
        }
    }

    return 0;
}