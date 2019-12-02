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

const ll L = 1e6+5;

vector <pll> store;
set <pll> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll h = 0, v = 0;

    store.pb(mp(h, v));

    for(ll i=0; i<n; i++)
    {
        if(s[i]=='U')
        {
            v++;
        }

        else if(s[i]=='R')
        {
            h++;
        }

        else if(s[i]=='D')
        {
            v--;
        }

        else
        {
            h--;
        }

        store.pb(mp(h, v));
    }

    ll st = 0;

    ll final = 0;

    for(ll e=0; e<sz(store); e++)
    {
        while(check.count(store[e]))
        {
            check.erase(store[st]);
            st++;
        }

        check.insert(store[e]);

        final = max(final, e-st);
    }

    cout << final << endl;

    return 0;
}