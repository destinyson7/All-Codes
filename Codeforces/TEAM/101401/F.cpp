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

const ll L = 2e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    ll len = sz(s);

    set <char> s1, s2;
    s1.insert(s[0]);
    s1.insert(s[1]);
    s1.insert(s[2]);

    s2.insert(s[len-1]);
    s2.insert(s[len-2]);
    s2.insert(s[len-3]);

    if(sz(s1) == 3 || sz(s2) == 3)
    {
        if(len == 3)
        {
            cout << 0 << endl;
            return 0;
        }

        cout << 1 << endl;
        return 0;
    }

    for(ll i=0; i<len-2; i++)
    {
        set <char> t;

        t.insert(s[i]);
        t.insert(s[i+1]);
        t.insert(s[i+2]);

        if(sz(t) == 3)
        {
            cout << 2 << endl;
            return 0;
        }
    }

    set <char> t1, t2;

    t1.insert(s[0]);
    t1.insert(s[1]);
    t1.insert(s[len-1]);

    t2.insert(s[0]);
    t2.insert(s[len-2]);
    t2.insert(s[len-1]);

    if(sz(t1) == 3 || sz(t2) == 3)
    {
        cout << 2 << endl;
        return 0;
    }

    for(ll i=0; i<len-1; i++)
    {
        set <char> t;

        t.insert(s[0]);
        t.insert(s[i]);
        t.insert(s[i+1]);

        if(sz(t) == 3)
        {
            cout << 3 << endl;
            return 0;
        }
    }

    for(ll i=len-1; i>=1; i--)
    {
        set <char> t;

        t.insert(s[len-1]);
        t.insert(s[i]);
        t.insert(s[i-1]);

        if(sz(t) == 3)
        {
            cout << 3 << endl;
            return 0;
        }
    }

    for(ll i=0; i<len; i++)
    {
        set <char> t;

        t.insert(s[0]);
        t.insert(s[1]);
        t.insert(s[i]);

        if(sz(t) == 3)
        {
            cout << 3 << endl;
            return 0;
        }
    }

    for(ll i=len-1; i>=0; i--)
    {
        set <char> t;

        t.insert(s[len-1]);
        t.insert(s[len-2]);
        t.insert(s[i]);

        if(sz(t) == 3)
        {
            cout << 3 << endl;
            return 0;
        }
    }

    if(s[0] != s[len-1])
    {
        cout << 4 << endl;
        return 0;
    }

    for(ll i=0; i<len-1; i++)
    {
        set <char> t;

        t.insert(s[i]);
        t.insert(s[i+1]);

        if(sz(t) == 2)
        {
            cout << 4 << endl;
            return 0;
        }
    }

    cout << 5 << endl;

    return 0;
}