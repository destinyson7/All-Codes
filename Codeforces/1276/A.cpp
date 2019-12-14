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

void solve()
{
    string s;
    cin >> s;

    ll len = sz(s);

    vector <bool> remove(len+5, false);

    for(ll i=0; i<len-4; i++)
    {
        if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e')
        {
            remove[i+2] = true;

            // cout << i+3 << endl;
        }
    }

    for(ll i=0; i<len-2; i++)
    {
        if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e' && remove[i] == false && remove[i+1] == false && remove[i+2] == false)
        {
            remove[i+1] = true;
        }
        
        if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && remove[i] == false && remove[i+1] == false && remove[i+2] == false)
        {
            remove[i+1] = true;
        }
    }

    vector <ll> ans;

    for(ll i=0; i<len; i++)
    {
        if(remove[i] == true)
        {
            ans.pb(i+1);
        }
    }

    cout << sz(ans) << endl;

    for(auto i: ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}