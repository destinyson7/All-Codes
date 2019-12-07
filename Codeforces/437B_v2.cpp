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

vector <ll> lowbits[35];
ll req[35];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll sum, limit;
    cin >> sum >> limit;

    vector <ll> ans;

    for(ll i=limit; i>0; i--)
    {
        for(ll j=0; j<20; j++)
        {
            if(i & ((1LL << j)))
            {
                lowbits[j].pb(i);

                break;
            }
        }
    }

    ll bit = 0;

    while(sum)
    {
        if(sum & 1)
        {
            req[bit]++;
        }

        sum >>= 1;
        bit++;
    }

    for(ll i=34; i>=0; i--)
    {
        while(req[i] && sz(lowbits[i]) > 0)
        {
            req[i]--;
            ans.pb(lowbits[i].back());
            lowbits[i].pop_back();
        }

        if(i == 0 && req[i] > 0)
        {
            cout << -1 << endl;
            return 0;
        }

        if(i > 0)
        {
            req[i-1] += (2*req[i]);
        }
    }

    cout << sz(ans) << endl;

    for(auto i: ans)
    {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}