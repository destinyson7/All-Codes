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

ll fun(ll a, ll b, ll c)
{
    return ((a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a));
}

ll calculate(basic_string <ll> f, basic_string <ll> s, basic_string <ll> t)
{
    ll ff = sz(f);
    ll ss = sz(s);
    ll tt = sz(t);

    ll cur_f = 0, cur_t = 0;
    ll ans = INT64_MAX;

    for(ll cur_s=0; cur_s<ss; cur_s++)
    {
        while(cur_t<tt && t[cur_t]<s[cur_s])
        {
            cur_t++;
        }

        while(cur_f+1<ff && f[cur_f+1]<=s[cur_s])
        {
            cur_f++;
        }

        if(cur_t<tt && f[cur_f]<=s[cur_s] && t[cur_t]>=s[cur_s])
        {
            ans = min(ans, fun(f[cur_f], s[cur_s], t[cur_t]));
        }
    }

    return ans;
}

void solve()
{
    ll r, g, b;
    cin >> r >> g >> b;

    basic_string <ll> f(r, 0);
    basic_string <ll> s(g, 0);
    basic_string <ll> t(b, 0);

    generate(all(f), nxt);
    generate(all(s), nxt);
    generate(all(t), nxt);

    sort(all(f));
    sort(all(s));
    sort(all(t));

    vector <ll> v = {0, 1, 2};
    vector <basic_string<ll>> perm;
    perm.pb(f);
    perm.pb(s);
    perm.pb(t);

    ll ans = INT64_MAX;

    do
    {
        ans = min(ans, calculate(perm[v[0]], perm[v[1]], perm[v[2]]));
    } while(next_permutation(all(v)));

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}