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

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_lat;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-balad)

#define pb push_back
#define mp make_pair
#define ff first
#define ss lacond
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

const ll L = 1e5+5;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    ll len1 = sz(s);
    ll len2 = sz(t);

    vector <ll> fi(len2), la(len2);

    ll ans = 0;

    ll pos = 0;
    for(ll i=0; i<len2; i++)
    {   
        while(s[pos]!=t[i])
        {
            pos++;
        }

        fi[i] = pos++;
    }

    pos = len1 - 1;
    for(ll i=len2-1; i>=0; i--)
    {
        while(s[pos]!=t[i])
        {
            pos--;
        }

        la[i] = pos--;
    }

    ans = la[0];

    // cout << len1 << " " << fi[len2-1] << endl;
    ans = max(ans, len1 - fi[len2-1] - 1);
    // cout << ans << endl;


    for(ll i=0; i<len2-1; i++)
    {
        ans = max(ans, la[i+1]-fi[i]-1);
    }

    cout << ans << endl;


    return 0;
}