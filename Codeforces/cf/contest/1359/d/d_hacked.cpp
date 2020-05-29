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
    basic_string <ll> a(n, 0);
    generate(all(a), nxt);


    ll cur = a[0];
    ll cur_max = a[0];
    ll cur_score = 0;
    ll ans = 0;

    for(ll i=1; i<n; i++)
    {
        cur += a[i];

        if(cur < a[i])
        {
            ans = max(ans, cur_score);
            cur = a[i];
            cur_max = a[i];
            cur_score = 0;
        }

        else
        {
            // cout << "going " << i << endl;
            cur_score += (cur_max + a[i]);
            cur_max = max(cur_max, a[i]);
            cur_score -= cur_max;
            ans = max(ans, cur_score);
        }

        // vector <ll> temp = {cur, cur_max, cur_score, ans};
        // cout << temp << endl;
    }

    ll cur2 = a[n-1];
    ll cur_max2 = a[n-1];
    ll cur_score2 = 0;
    ll ans2 = 0;

    for(ll i=n-2; i>=0; i--)
    {
        cur2 += a[i];

        if(cur2 < a[i])
        {
            ans2 = max(ans2, cur_score2);
            cur2 = a[i];
            cur_max2 = a[i];
            cur_score2 = 0;
        }

        else
        {
            // cout << "going " << i << endl;
            cur_score2 += (cur_max2 + a[i]);
            cur_max2 = max(cur_max2, a[i]);
            cur_score2 -= cur_max2;
            ans2 = max(ans2, cur_score2);
        }

        // vector <ll> temp = {cur, cur_max, cur_score, ans};
        // cout << temp << endl;
    }

    cout << max(ans, ans2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}