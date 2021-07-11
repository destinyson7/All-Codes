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

const ll L = 1e5 + 5;
const ll mod = 1e9 + 7;

ll l[L];
ll r[L];

map <ll, ll> pref;

void solve()
{
    ll n = nxt(), c = nxt();

    pref.clear();

    for(ll i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];

        pref[l[i] + 1]++;
        pref[r[i]]--;
    }

    ll ans = n;

    // multiset <ll> s;

    // for(ll i = 1; i < L; i++)
    // {
    //     pref[i] += pref[i - 1];
    //     if(pref[i])
    //     {
    //         s.insert(pref[i]);
    //     }
    // }

    ll prefix_sum = 0;
    bool f = true;
    ll prev = -1;

    multiset <pll> s;

    for(auto i: pref)
    {
        if(f)
        {
            f = false;
        }

        else
        {
            if(prefix_sum > 0)
            {
                s.insert(mp(prefix_sum, i.ff - 1 - prev + 1));
            }
        }

        prev = i.ff;
        prefix_sum += i.ss;
    }

    while(c)
    {
        if(s.empty())
        {
            break;
        }

        // ll add = (*(s.rbegin()));
        // ans += add;

        // s.erase(s.lower_bound(add));

        pll temp = *(s.rbegin());

        if(c >= temp.ss)
        {
            ans += (temp.ff * temp.ss);
            c -= temp.ss;
        }

        else
        {
            ans += (temp.ff * c);
            c = 0;
        }

        s.erase(s.lower_bound(temp));
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    for(ll i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
