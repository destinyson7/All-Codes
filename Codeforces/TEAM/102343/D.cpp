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
 
const ll L = 1e5+5;
 
ll pos[10];
 
map <string, ll> col;
 
vector <pair <ll, ll>> cur(505);
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll n, p;
    cin >> n >> p;
 
    vector <vector <ll>> m(205);
 
    ll assign = 1;
    for(ll i=1; i<n; i++)
    {
        string s;
        cin >> s;
 
        if(col.find(s) == col.end())
        {
            col[s] = assign;
            assign++;
        }
 
        // cout << s << " * " << col[s] << endl;
 
        m[col[s]].pb(i);
    }
 
    for(ll i=0; i<10; i++)
    {
        pos[i] = 0;
    }
 
    for(ll i=0; i<assign; i++)
    {
        m[i].pb(n);
    }
 
    ll c;
    cin >> c;
 
    for(ll i=0; i<c; i++)
    {
        string ch;
        cin >> cur[i].ff >> ch;
 
        if(col.find(ch) == col.end())
        {
            // cout << "**" << endl;
            col[ch] = assign;
            assign++;
            m[col[ch]].pb(n);
        }
        
        cur[i].ss = col[ch];
    }
 
    ll whose = 0;
    ll iter = 0;
    while(1)
    {
        iter++;
        for(ll i=0; i<c; i++)
        {
            ll next = whose;
 
            if(cur[i].ff == 1)
            {
                pos[next] = *upper_bound(all(m[cur[i].ss]), pos[next]);
 
                // cout << pos[next] << endl;
 
                // assert(pos[next] <= n);
 
                if(pos[next] >= n)
                {
                    cout << next + 1 << endl;
                    return 0;
                }
            }
 
            else if(cur[i].ff == 2)
            {
                pos[next] = *upper_bound(all(m[cur[i].ss]), pos[next]);
 
                // assert(pos[next] <= n);
 
                if(pos[next] >= n)
                {
                    cout << next + 1 << endl;
                    return 0;
                }
 
                pos[next] = *upper_bound(all(m[cur[i].ss]), pos[next]);
 
                // assert(pos[next] <= n);
 
                if(pos[next] >= n)
                {
                    cout << next + 1 << endl;
                    return 0;
                }
            }
 
            else
            {
                pos[next] = m[cur[i].ss][0];
 
                // assert(pos[next] <= n);
 
            }
 
            whose++;
 
            if(whose >= p)
            {
                whose-=p;
            }
        }
 
        if(iter > 100000)
        {
            assert(false);
        }
    }
 
    return 0;
}