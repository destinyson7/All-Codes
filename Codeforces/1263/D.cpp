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

ll parent[300];
ll unionSize[300];

ll find(ll s)
{
    if(parent[s]==s)
    {
        return s;
    }

    return parent[s] = find(parent[s]);
}

void unionSet(ll x, ll y)
{
    ll a = find(x);
    ll b = find(y);
    
    if (unionSize[a] > unionSize[b])
    {
        unionSet(y, x);      
        return;
    }  
    
    parent[a] = b;

    unionSize[b] += unionSize[a];
}

map <char, bool> pres;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(ll i=0; i<300; i++)
    {
        parent[i] = i;
    }

    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        ll len = sz(s);

        ll store = -1;

        for(ll j=0; j<len; j++)
        {
            pres[s[j]] = true;
        }

        for(ll j=0; j<len; j++)
        {
            store = find(ll(s[j]));
            if(store != (ll)s[j])
            {
                break;
            }
        }

        if(store == -1)
        {
            store = s[0];
        }

        for(ll j=0; j<len; j++)
        {
            if(s[j] == store)
            {
                continue;
            }

            unionSet(store, (ll)s[j]);
        }
    }

    set <ll> ss;

    for(ll i='a'; i<='z'; i++)
    {
        if(pres[i] == true)
        {
            ss.insert(find((ll)i));
        }
    }

    cout << sz(ss) << endl;

    return 0;
}