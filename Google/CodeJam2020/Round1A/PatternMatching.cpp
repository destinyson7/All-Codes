#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 1e5+5;

void solve()
{
    ll n = nxt();

    vector <vector<string>> v(n);

    for(ll i=0; i<n; i++) 
    {
        string s;
        cin >> s;

        if(s == "*")
        {
            continue;
        }

        ll start = 0;
        ll len = sz(s);

        for(ll j=0; j<len; j++)
        {
            if(s[j] == '*')
            {
                v[i].pb(s.substr(start, j-start));
                start = j + 1;
            }
        }

        v[i].pb(s.substr(start));

        // cout << sz(v[i]) << endl;
    }

    // cout << v << endl;

    // bool possible = true;

    string prefix = "";
    ll len = 0;

    for(ll i=0; i<n; i++)
    {
        if(sz(v[i]) > 0)
        {
            string cur = v[i][0];
            ll siz = sz(cur);

            for(ll j=0; j<min(len, siz); j++)
            {
                if(cur[j] != prefix[j])
                {
                    // cout << "here" << endl;
                    cout << "*" << endl;
                    return;
                }
            }

            if(len < siz)
            {
                prefix = cur;
                len = siz;
            }

            // len = sz(prefix);
        }
    }

    // cout << prefix << endl;

    string suffix = "";
    len = 0;

    for(ll i=0; i<n; i++)
    {
        if(sz(v[i]) > 0)
        {
            string cur = v[i][sz(v[i])-1];
            ll siz = sz(cur);

            // cout << suffix << "  " << cur << endl;

            for(ll j=1; j<=min(siz, len); j++)
            {
                if(cur[siz-j] != suffix[len-j])
                {
                    cout << "*" << endl;
                    return;
                }
            }

            if(len < siz)
            {
                suffix = cur;
                len = siz;
            }

            // len = sz(prefix);
        }
    }

    // cout << suffix << endl;

    string ans = prefix;

    for(ll i=0; i<n; i++)
    {
        for(ll j=1; j<sz(v[i])-1; j++)
        {
            ans += v[i][j];
        }
    }

    ans += suffix;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}