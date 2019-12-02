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

const ll L = 3e5+5;
const ll mod = 998244353;

ll fact[L];

void factorial()
{
    fact[0] = 1;

    for(ll i=1; i<L; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
}

map <ll, ll> cnt1, cnt2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    factorial();

    vector <pll> p;

    for(ll i=0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;

        cnt1[a]++;
        cnt2[b]++;

        p.pb(mp(a, b));
    }

    sort(all(p));

    bool f = true;

    for(ll i=1; i<n; i++)
    {
        if(p[i].ff < p[i-1].ff)
        {
            f = false;
            break;
        }
    }

    for(ll i=1; i<n; i++)
    {
        if(p[i].ss < p[i-1].ss)
        {
            f = false;
            break;
        }
    }

    ll ans = fact[n];

    // cout << ans << endl;

    ll temp1 = 1, temp2 = 1, temp3 = 1;

    for(auto i: cnt1)
    {
        temp1 = (temp1 * fact[i.ss])%mod;
    }

    for(auto i: cnt2)
    {
        temp2 = (temp2 * fact[i.ss])%mod;
    }

    ll cur = 1;
    for(ll i=1; i<n; i++)
    {
        if(p[i].ff == p[i-1].ff && p[i].ss == p[i-1].ss)
        {
            cur++;
        }

        else
        {
            temp3 = (temp3 * fact[cur])%mod;
            cur = 1;
        }
    }

    temp3 = (temp3 * fact[cur])%mod;

    // cout << temp1 << " " << temp2 << endl;

    if(f)
    {
        ans = (ans + temp3)%mod;
    }

    ans = (ans - temp1 + mod)%mod;
    ans = (ans - temp2 + mod)%mod;

    cout << ans << endl;

    return 0;
}