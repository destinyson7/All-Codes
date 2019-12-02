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

const ll L = 2e5+5;

ll tim[L];
ll lite[L];
ll ma[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    vector <ll> a;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }   

    ll q;
    cin >> q;

    for(ll che = 0; che < q; che++)
    {
        ll type;
        cin >> type;

        if(type == 1)
        {
            ll p, x;
            cin >> p >> x;

            a[p-1] = x;
            tim[p-1] = che;
            
            ma[che] = 0;
        }

        else
        {
            ll x;
            cin >> x;

            ma[che] = x;
        }

        // cout << ma[che] << endl;
    }

    // sort(all(x));

    ll curmax = 0;

    // cout << q << " size" << endl;

    for(ll i=q-1; i>=0; i--)
    {
        // cout << curmax << endl;
        curmax = max(curmax, ma[i]);
        ma[i] = curmax;
    }

    for(ll i=0; i<n; i++)
    {
        cout << max(a[i], ma[tim[i]]) << " ";
    }
    cout << endl;

    return 0;
}