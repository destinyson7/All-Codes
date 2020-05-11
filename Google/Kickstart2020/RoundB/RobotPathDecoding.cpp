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
const ll mod = 1e9;

ll add(ll x, ll y)
{
    return ((x + y)%mod + mod)%mod;
}

void solve()
{
    string s;
    cin >> s;

    ll n = sz(s);

    stack <pair<ll, vector<ll>>> v;
    v.push(mp(1, vector<ll>(2, 0)));

    for(ll i=0; i<n; i++)
    {
        if(s[i] == '(')
        {
            v.push(mp(s[i-1]-48, vector<ll>(2, 0)));
        }

        else if(s[i] == ')')
        {
            pair<ll, vector<ll>> top = v.top();
            v.pop();

            pair<ll, vector<ll>> next = v.top();
            v.pop();

            next.ss[0] = add(next.ss[0], (top.ff*top.ss[0]));
            next.ss[1] = add(next.ss[1], (top.ff*top.ss[1]));

            v.push(next);
        }

        else if(s[i] == 'N')
        {
            pair<ll, vector<ll>> top = v.top();
            v.pop();

            top.ss[0] = add(top.ss[0], -1);
            v.push(top);
        }

        else if(s[i] == 'S')
        {
            pair<ll, vector<ll>> top = v.top();
            v.pop();

            top.ss[0] = add(top.ss[0], 1);
            v.push(top);
        }

        else if(s[i] == 'E')
        {
            pair<ll, vector<ll>> top = v.top();
            v.pop();

            top.ss[1] = add(top.ss[1], 1);
            v.push(top);
        }

        else if(s[i] == 'W')
        {
            pair<ll, vector<ll>> top = v.top();
            v.pop();

            top.ss[1] = add(top.ss[1], -1);
            v.push(top);
        }
    }

    assert(sz(v) == 1);
    
    vector <ll> pos = v.top().ss;
    
    ll x = ((pos[1]%mod) + mod)%mod;
    ll y = ((pos[0]%mod) + mod)%mod;
    
    if(x == (ll)1e9)
    {
        x = 1;
    }
    
    else
    {
        x++;
    }
    
    if(y == (ll)1e9)
    {
        y = 1;
    }
    
    else
    {
        y++;
    }

    cout << x << " " << y << endl;
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